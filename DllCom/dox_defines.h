#ifndef __DOX_DEFINES_H__
#define __DOX_DEFINES_H__

/* Define version */
#define VERSION "2.70"
#define COPYRIGHT "Copyright 1998-2000 by Andrew Punch."
#define GENERATOR "Dox "VERSION" "COPYRIGHT

/* Registry locations for user information */
#define LOCALKeyName "SOFTWARE\\Dox\\2.00"
#define USERKeyName "Software\\Dox\\2.00"

#define PRESERVED 4      /* Styles which are initialised only once per document*/
#define MAXSTYLES 16     /* Number of styles. */
#define MAXSTR 1024      /* Size to allocate for strings. */
#define MAX_LINE_LEN 255 /* Maximum number of characters per line. Applies to txt */
#define DEF_LINE_LEN 80  /* Default line length for wrapping. */
#define MAXFILES 64      /* Maximum number of files in command line. */
#define MAXFILENAME 1024  /* Maximum length of filenames. */
#define NUMDOCS 3        /* Number of document types. */
#define TDoxConInfo state_type
/* Define true and false if it isn't already done. */
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#ifndef true
#define true 1
#define false 0
#endif

#define DOX_BAIL TRUE
#define FAIL -1         /* Fail condition. */

/* This value tells what format the input or output file will be in. */
enum doc_code
        {
        doc_rtf,  /* rtf (Rich Text Format) */
        doc_html, /* html (HyperText Markup Language) */
        doc_text, /* text ASCII text */
        doc_word  /* word (MS Word) - not yet supported. */
        };

#define LXOR(x,y) ( ((x)||(y)) && (!((x)&&(y))) )

#endif