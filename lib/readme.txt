Non-ActiveX DLL Library Readme.
*******************************
This library is only suitable for MSVC and BCB. Not MSVB.

bcb3.zip contains an example project for BCB version 3.

How to use:
1. Link your project with doxlib.lib
2. Include doxface.h
3. To convert from rtf to html add the line:
DoxConvert(InFile, OutFile, 0);
Where InFile and OutFile are null terminated strings containing the file names.

To do a memory to memory conversion:
RequiredSize = DoxConvert(InBuffer, InSize, OutBuffer, OutSize, 0);
Where InBuffer and OutBuffer are memory buffers. Function returns a positive value
on success, 0 on unspecified error and a negative number if the OutBuffer is too small.
The absolute value of this negative number indicates the space in bytes required.

4. Ensure doxlib.dll is in the same directory as your programme.

Notes:
DoxConvert returns zero on success and non-zero on failure.
Distribute doxlib.dll with your application.

To do a conversion other than rtf to html use the following options or'ed together:
DOX_IN_RTF
DOX_IN_HTML
DOX_IN_TEXT
DOX_OUT_RTF
DOX_OUT_HTML
DOX_OUT_TEXT

For example - to convert c:\resume.html to c:\resume.rtf:
DoxConvert("c:\\resume.html", "c:\\resume.rtf", DOX_IN_HTML|DOX_OUT_RTF);

Dox, this programming kit and this documentation is copyright 2000 Andrew Punch.
