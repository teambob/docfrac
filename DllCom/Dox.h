/* dox.h  The support file for dox and all its contributary files. */
/* Includes */
#ifndef __DOX_H__
#define __DOX_H__

#include <stdlib.h>
#include <stdio.h>
#include "dox_defines.h"
#include "doxtypes.h"

/* If building on Unix use strlwr patch */
#ifdef NEED_STRFIX
#include "strfix.h"
#endif

/* Allow C functions to be called from C++
 and vice-versa */
#ifdef __cplusplus
extern "C"{
#endif

/* Filename detirmination */
int whatdoc(char *command, char *filename);
int file_type(char *string);
void make_filename(int OutDoc, char *outfile, char *infile, char *OutDir);

/* Function prototypes. */
/* Public functions. */
/* help and do_yield must be declared as extern "C" if you are using c++ */
/* help is generally called when an error occurs and do_yield is called every */
/* so often during the conversion - allowing a windows yield or a progress */
/* update. */
void convert(TDoxState *state);  /* You may call this from your own programme. */
void DoConvert(TDoxState *state);/* Same as DoConvert, doesn't initialise ???_internal */


/* Callback functions. */
void CallbackMessage(TMessDestination Destination, char *Message);
int CallbackYield(TDoxState *state);  /* You must specify a function do_yield */
FILE *PictCallBack(TDoxState *state, char *Extension, char *Reference);
void PictClose(TDoxState *state, FILE *fptr);
int CallbackGraphicConvert(char *InName, char *OutFormat, char *OutName, long x, long y);
/*void *CallbackMalloc(TDoxState *state, size_t size);
void CallbackFree(TDoxState *state, void *block);*/

/*#include "doxinternal.h"*/
#ifdef __cplusplus
}
#endif
#endif
