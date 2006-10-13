; docfrac-win32-gui.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install makensisw.exe into a directory that the user selects,

;--------------------------------

; The name of the installer
Name "DocFrac Windows GUI"

; The file to write
OutFile "docfrac-win32-gui.exe"

; Set compression
SetCompressor bzip2

; Define project name
!define PROJECT "DocFrac"

; The default installation directory
InstallDir $PROGRAMFILES\${PROJECT}

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\${PROJECT}" "Install_Dir"

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
  File "..\new-gui\NewDocfrac.exe"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\${PROJECT} "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "DisplayName" "${PROJECT}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"
  CreateDirectory "$SMPROGRAMS\${PROJECT}"
  CreateShortCut "$SMPROGRAMS\${PROJECT}\DocFrac.lnk" "$INSTDIR\NewDocfrac.exe" "" "$INSTDIR\NewDocfrac.exe" 0
  CreateShortCut "$SMPROGRAMS\${PROJECT}\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PROJECT}"
  DeleteRegKey HKLM SOFTWARE\${PROJECT}

  ; Remove files and uninstaller
  Delete $INSTDIR\NewDocfrac.exe
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\${PROJECT}\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\${PROJECT}"
  RMDir "$INSTDIR"

SectionEnd