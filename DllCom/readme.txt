** Quick Installation **
1. The installer should register the server.
2. You should then import the library into your programming environment.

Windows NT/2000 users: Security in Windows NT/2000 is often unnecessarily set
up to prevent registering or access to ActiveX DLLs. If you are having
problems try running in admistrator or root mode.



** Manually registering the automation server **
1. If you have an old server with the name "doxcom.exe" delete all traces of
it. If windows says that it may impact on registered programmes answer 'Yes'
to delete it.
2. Unzip the new server to a directory.
3. To register manually open an MSDOS box type  regsvr32 doxcom.dll  
(You may have to include the full path of the file e.g. c:\apps\dox\doxcom.dll)
4. You should now be able to select the library. In visual basic:
Projects->References or select DoxCom.tlb from Projects->References->Browse.



** Unregistering the automation server **
1. Type  regsvr32 /u doxcom.dll  (You may have to include the full path of the
file e.g. c:\apps\dox\doxcom.dll)
2. You can now delete doxcom.dll


** Distribution **
1. Distribute doxcom.dll
2. Register doxcom.dll.
3. Unregister doxcom.dll when uninstalling.
4. Delete doxcom.dll when uninstalling.


** Programming the interface **
Included files:
DoxCom.dll   Automation server.
DoxCom.tlb   Type library.
Host.exe     Sample automation controller.
Resume.rtf   Sample rtf file.
vb\          Sample visual basic source.
bcb3\        Sample Borland C++ Builder source.


** Programming **

The interface is called DoxLib.
It has three main functions:
SetInFileName(LPSTR FileName)
SetOutFileName(LPSTR FileName)
Convert()

The first two must be called before the last one. The default conversion is from 
rtf to html.

Note: If you wish to use multiple threads you *must* access the library through the dispatch interface NOT through the dual/vtable interface.

SetInFormat(LPSTR Extension)
SetOutFormat(LPSTR Extension)

To override the default conversion pass a string to SetInFormat or SetOutFormat:
"rtf"            Rtf format
"htm" or "html"  Html format
"txt"            Text format
"auto"           Figure it out from the extensions of the filenames (set by SetInFileName 
                 and SetOutFileName).

If SetInFormat is not called it will assume you wish to convert from rtf.
If SetOutFormat is not called it will assume you wish to convert to html.

SetInString(LPSTR In)
BSTR StringConvert()

Simply use SetInString(InputString) to set the input string you wish to use and 
OutputString = StringConvert() to convert and receive the output in a string.

You need not use these functions together. For example in MSVB:
dim x as new DoxLib
x.SetInString(Temp)
x.SetOutFile("Save.html")
x.Convert()


**Alternative**
If you are using MSVC or BCB you may wish to use the traditional DLL included 
in this package


Acronyms:
MSVC    Microsoft Visual C++
MSVB    Microsoft Visual Basic
BCB     Borland C++ Builder
Delphi  Borland Delphi

Website:
http://docfrac.sourceforge.net/
Contact:
andrewpunch@bigfoot.com
