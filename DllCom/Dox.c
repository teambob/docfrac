/* rtf2html.c */
#define __DOX_C__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dox.h"
#include "doxinternal.h"
#ifndef DOX_NEXT_GENERATION
#include "rtf.h"
#include "html.h"
#include "text.h"
#include "debug.h"
#endif

char *extension_list[NUMDOCS] = {"rtf", "html htm", "txt"};
char command_list[NUMDOCS] = "rht";

#ifndef DOX_NEXT_GENERATION
/* *********************************************************************** */
/* ****************** Input and output remapping functions. ************** */
/* *********************************************************************** */

void convert(TDoxState *state)
{
state->in_internal = NULL;
state->out_internal = NULL;
state->yld_internal = NULL;
state->gra_internal = NULL;

DoConvert(state);

if (state->in_internal!=NULL)
        free(state->in_internal);

if (state->out_internal!=NULL)
        free(state->out_internal);

if (state->yld_internal!=NULL)
        free(state->yld_internal);

if (state->gra_internal!=NULL)
  free(state->gra_internal);
}

void DoConvert(TDoxState *state)
{
state->Extra.GraphicName[0] = 0;
state->Extra.GraphicHeight = 0;
state->Extra.TableCols = 0;
state->Extra.FontName[0] = 0;
state->Extra.FontFamily[0] = 0;
state->Extra.Hyperlink[0]=0;
dlog("Ready to start");
switch(state->indoc)
        {
        case doc_rtf:
                rtf_convert(state);
                break;
        case doc_html:
                html_convert(state);
                break;
        case doc_text:
                text_convert(state);
                break;
        }

}

void output(TDoxState *state, char *word)
{
switch(state->outdoc)
        {
        case doc_rtf:
                rtf_output(state, word);
                break;
        case doc_html:
                html_output(state, word);
                break;
        case doc_text:
                text_output(state, word);
                break;
        }
}


void update_style(TDoxState *state)
{
switch(state->outdoc)
        {
        case doc_rtf:
                rtf_update_style(state);
                break;
        case doc_html:
                html_update_style(state);
                break;
        case doc_text:
                text_update_style(state);
                break;
        }
}


/* ******************************************************************** */
/* ************* Miscellaneous functions ****************************** */
/* ******************************************************************** */


void default_style(TDoxState *state, int init, int *Leave)
{
int count;
long LeaveIt[MAXSTYLES];

for (count=0;count<MAXSTYLES;count++)
        LeaveIt[count] = 0;

if (Leave!=NULL)
        for (count=0;Leave[count]!=-1;count++)
                LeaveIt[Leave[count]]=TRUE;


if (init==IniInternal)
    {
    state->New[st_centre]=0;
    init=0;
    }
else if (init)
	{
        state->current[st_begin] = 0;
        state->New[st_begin] = 1;
        state->current[st_break] = 0;
        state->New[st_break] = 0;
        state->current[st_paragraph] = 0;
        state->New[st_paragraph] = 0;
        state->current[st_centre]=0;
        state->New[st_centre]=0;
        }

for (count=PRESERVED;count<MAXSTYLES;count++)
  if (!LeaveIt[count])
	{
        state->New[count]=FALSE;
	if (init)
                state->current[count]=FALSE;
	}
}



int nextchar(FILE *instream)
{
int c;
c = fgetc(instream);
ungetc(c, instream);
return c;
}

#endif
/* ******************************************************************** */
/* ************* Filename and file type functions ********************* */
/* ******************************************************************** */


int whatdoc(char *command, char *filename)
{
int count;
int identifier;
char *extension;
char Temp[255];

if (filename!=NULL)
{
if (strcmp(filename, "-"))
{            
extension = strrchr(filename, '.');

if (extension==NULL)
        {
        fprintf(stderr, "Invalid filename");
        return FAIL;
        }
else
        extension++;

strcpy(Temp, extension);
strlwr(Temp);
extension = Temp;

for (count=0;count<NUMDOCS;count++)
    if (strstr(extension_list[count], extension)!=NULL)
               return count;
}
}

if (command==NULL)
        return FAIL;

if (command[0]=='-')
        {
        if (command[1]=='o')
                identifier = 2;
        else
                identifier = 1;

        if (command[identifier])
                for (count=0;count<NUMDOCS;count++)
                        if (command[identifier]==command_list[count])
                                return count;
        }

return FAIL;
}

int file_type(char *string)
{
if (!strcmp(string, "-"))
        return use_stdin;
else if (strchr(string, 's')!=NULL)
        return use_stdin;
else if (strchr(string, 'f')!=NULL)
        return use_next_file;

return use_options;
}


void make_filename(int OutDoc, char *outfile, char *infile, char *OutDir)
{
int index, ExtensionLength;
char *extension;

strcpy(outfile, infile);

if (OutDir)
if (*OutDir)
    {
    strcpy(outfile, OutDir);
    if (outfile[strlen(outfile)-1] != '\\')
        strcat(outfile, "\\");
    extension = strrchr(infile, '\\')+1;
    strcat(outfile, extension);
    }
   

index = (int)(strrchr(outfile, '.')-outfile);
outfile[index] = 0;
strcat(outfile, ".");

#ifdef NO_LFN
extension = strchr(extension_list[OutDoc], ' ');

if (extension==NULL)
        extension = extension_list[OutDoc];
else
        extension++;

strcat(outfile, extension);
#else
ExtensionLength = (strrchr(extension_list[OutDoc], ' ')-extension_list[OutDoc]);
if (ExtensionLength<0)
        ExtensionLength = strlen(extension_list[OutDoc]);

strncat(outfile, extension_list[OutDoc], ExtensionLength);
#endif
}


#ifndef DOX_NEXT_GENERATION
/* ******************************************************************** */
/* ************* Character escape functions *************************** */
/* ******************************************************************** */

int ConvertCS(TDoxState *state, TEscape Local[], char *code, char *signal)
{
int count;
for (count=0;Local[count].code;count++)
        {
        if (!strcmp(Local[count].code, code))
                break;
        }

if (!Local[count].code)
        return FALSE;
        

/* This is were you would call the function. */
if (Local[count].FuncCS==NULL)
        strcpy(signal, Local[count].signal);

return TRUE;
}

int ConvertSC(TDoxState *state, TEscape Local[], char *signal, char *code)
{
int count;
for (count=0;Local[count].code;count++)
        if ((strstr(Local[count].signal, signal)==Local[count].signal)
            &&Local[count].mandatory)
                {
                strcpy(code, Local[count].code);
                return TRUE;
                }

return FALSE;
}


/* Obsolscent functions. */


void help(TDoxState *state, int level)
{

switch(level)
        {
#ifdef DOX_COMMAND_LINE
        case 0:
                fprintf(stderr, "dox. A RTF/HTML/TXT document converter. "COPYRIGHT"\n");
                fprintf(stderr,  "Type  %s -?  for help. Version "VERSION"\n", COMPILE);
                break;

        case 1:
                fprintf(stderr,  "\nUsage: %s [[-<force>] <infile>] [-o<force> <outfile>] [-s] [-?]\n", COMPILE);
                fprintf(stderr,  "[-<force>] <infile>  input File.\n");
                fprintf(stderr,  "-o[force] [outfile]  Output file.\n");
                fprintf(stderr,  "Use a filename of - for stdin/stdout.\n\n");

                fprintf(stderr,  "-q                   Quiet.\n");
                fprintf(stderr,  "-l <length>          Line wrap length for text output. Default is 80.\n");
                fprintf(stderr,  "-?                   view this help screen.\n");
                CallbackMessage(DoxMessError,  "-x                   eXtract pictures from rtf file.\n");
                CallbackMessage(DoxMessError,  "-b                   emBed pictures. (Implies -x). Experiemental.\n");
                CallbackMessage(DoxMessError,  "-s                   ignored.\n\n");

                CallbackMessage(DoxMessError,  "Force characters:\n");
                fprintf(stderr,  "f      Filename is next argument\n");
                fprintf(stderr,  "s      Stdin/Stdout. (Phasing out, use - filename instead.)\n");
                fprintf(stderr,  "h      Html format\n");
                fprintf(stderr,  "r      Rtf format\n");
                fprintf(stderr,  "t      Txt format\n\n");
                fprintf(stderr,  "e.g. %s bob.rtf -oh\nConverts bob.rtf to html format. It will create bob.html\n", COMPILE);

                exit(0);
                break;
#endif
       case 4:
                CallbackMessage(DoxMessError,  "Failed to allocate memory...\n");
                break;

       case 9:
                CallbackMessage(DoxMessError,  "File error occured during conversion...\n");
                break;

       default:
                CallbackMessage(DoxMessError,  "An unexpected error occured...\n");
       }

}

void DoxMessage(char *Message, int Action)
{
dlog("In DoxMessage");
CallbackMessage(DoxMessError, Message);
if (Action==DOX_BAIL)
        exit(1);
}
#endif
