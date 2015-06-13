; docfrac-win32-programming.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install makensisw.exe into a directory that the user selects,

;--------------------------------

; The name of the installer
Name "DocFrac Programming Kit"

; The file to write
OutFile "docfrac-win32-programming.exe"

; Set compression
SetCompressor bzip2

; Define project name
!define PROJECT "DocFrac Programming Kit"

; The default installation directory
InstallDir "$PROGRAMFILES\${PROJECT}"

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\${PROJECT}" "Install_Dir"

Var installed

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "${PROJECT} (required)"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  ;File "..\old-gui\dox_old.exe"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM "SOFTWARE\${PROJECT}" "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "DisplayName" "${PROJECT}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "NoRepair" 1
  WriteUninstaller "uninstall.exe"

  ; Create shortcut to uninstaller
  CreateDirectory "$SMPROGRAMS\${PROJECT}"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  
SectionEnd



; Optional section (can be disabled by the user)
Section "ActiveX for VB, FoxPro etc."
  WriteRegStr HKLM "SOFTWARE\${PROJECT}" "ActiveX" "Installed"

  CreateDirectory "$INSTDIR\ActiveX"
  SetOutPath $INSTDIR\ActiveX

  File "..\dllcom\doxcom.dll"
  File "..\dllcom\doxcom.tlb"
  File "..\dllcom\readme.html"
  File "..\dllcom\bcpp\host.exe"

  RegDLL "$INSTDIR\ActiveX\doxcom.dll"

  CreateDirectory "$INSTDIR\ActiveX\vb\"
  SetOutPath "$INSTDIR\ActiveX\vb\"

  File "..\dllcom\vb\test.frm"
  File "..\dllcom\vb\test.frx"
  File "..\dllcom\vb\vbtest.vbp"  
  File "..\dllcom\vb\vbtest.vbw"  

  CreateDirectory "$INSTDIR\ActiveX\bcb3\"
  SetOutPath "$INSTDIR\ActiveX\bcb3\"
  File "..\dllcom\bcpp\host.bpr"  
  File "..\dllcom\bcpp\host.cpp"  
  File "..\dllcom\bcpp\host.res"  
  File "..\dllcom\bcpp\readme.txt"  
  File "..\dllcom\bcpp\TDodgyThread.cpp"  
  File "..\dllcom\bcpp\TDodgyThread.h"  
  File "..\dllcom\bcpp\TMain.cpp"  
  File "..\dllcom\bcpp\TMain.h"  
  File "..\dllcom\bcpp\TMain.dfm"  



  CreateDirectory "$SMPROGRAMS\${PROJECT}\ActiveX"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\ActiveX\ActiveX Folder.lnk" "$INSTDIR\ActiveX"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\ActiveX\Readme.lnk" "$INSTDIR\ActiveX\readme.html"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\ActiveX\Test host.lnk" "$INSTDIR\ActiveX\host.exe"
  
SectionEnd



; Optional section (can be disabled by the user)
Section "DLL"
  WriteRegStr HKLM "SOFTWARE\${PROJECT}" "DLL" "Installed"

  CreateDirectory "$INSTDIR\DLL"
  SetOutPath "$INSTDIR\DLL"

  File "..\lib\doxlib.dll"
  File "..\lib\doxface.h"
  File "..\lib\readme.txt"
  File "..\lib\bcb3\testlib.exe"

  CreateDirectory "$INSTDIR\DLL\bcb3"
  SetOutPath "$INSTDIR\DLL\bcb3"
  File "..\lib\bcb3\main.cpp"
  File "..\lib\bcb3\main.dfm"
  File "..\lib\bcb3\main.h"
  File "..\lib\bcb3\TDodgyThread.cpp"
  File "..\lib\bcb3\TDodgyThread.h"
  File "..\lib\bcb3\testlib.bpr"
  File "..\lib\bcb3\testlib.cpp"
  File "..\lib\bcb3\testlib.res"


  CreateDirectory "$SMPROGRAMS\${PROJECT}\DLL"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\DLL\DLL Folder.lnk" "$INSTDIR\DLL"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\DLL\Readme.lnk" "$INSTDIR\DLL\readme.txt"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\DLL\Test programme.lnk" "$INSTDIR\DLL\testlib.exe"
  
SectionEnd


;--------------------------------

; Uninstaller

Section "Uninstall"
  

  

  ReadRegStr $installed HKLM "SOFTWARE\${PROJECT}" "ActiveX"
  StrCmp $installed "" NoActiveX

    ; Remove ActiveX stuff
    UnRegDLL "$INSTDIR\ActiveX\doxcom.dll"
    Delete "$INSTDIR\ActiveX\*.*"
    Delete "$INSTDIR\ActiveX\vb\*.*"
    Delete "$INSTDIR\ActiveX\bcb3\*.*"

    RMDir "$INSTDIR\ActiveX\vb"
    RMDir "$INSTDIR\ActiveX\bcb3"
    RMDir "$INSTDIR\ActiveX"  

    Delete "$SMPROGRAMS\${PROJECT}\ActiveX\*.*"
    RMDir "$SMPROGRAMS\${PROJECT}\ActiveX"
  NoActiveX:


  ReadRegStr $installed HKLM "SOFTWARE\${PROJECT}" "DLL"
  StrCmp $installed "" NoDLL
    ; Remove DLL stuff
    Delete "$INSTDIR\DLL\*.*"
    Delete "$INSTDIR\DLL\bcb3\*.*"
    
    RMDir "$INSTDIR\DLL\bcb3"
    RMDir "$INSTDIR\DLL"

    Delete "$SMPROGRAMS\${PROJECT}\DLL\*.*"
    RMDir "$SMPROGRAMS\${PROJECT}\DLL"

  NoDLL:


  ; Delete uninstaller
  delete "$INSTDIR\uninstall.exe"
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}"
  DeleteRegKey HKLM "SOFTWARE\${PROJECT}"

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\${PROJECT}\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\${PROJECT}"
  RMDir "$INSTDIR"

SectionEnd