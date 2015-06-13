//---------------------------------------------------------------------------
#ifndef doxfaceH
#define doxfaceH

#if __cplusplus
extern "C" {
#endif

#ifndef __DOX_H__
enum doc_code
        {
        doc_rtf,  /* rtf (Rich Text Format) */
        doc_html, /* html (HyperText Markup Language) */
        doc_text, /* text ASCII text */
        doc_word  /* word (MS Word) - not yet supported. */
        };
#endif

#define DOX_IN_RTF (doc_rtf+1)
#define DOX_IN_HTML (doc_html+1)
#define DOX_IN_TEXT (doc_text+1)

#define DOX_OUT_RTF ((doc_rtf+1)<<4)
#define DOX_OUT_HTML ((doc_html+1)<<4)
#define DOX_OUT_TEXT ((doc_text+1)<<4)

long _export _cdecl DoxConvert(char *InFile, char *OutFile, long Options);

long _export _cdecl DoxStringConvert(char *InBuffer, long InLength,
    char *OutBuffer, long OutLength, long Options);


#if __cplusplus
}
#endif
//---------------------------------------------------------------------------
#endif
 