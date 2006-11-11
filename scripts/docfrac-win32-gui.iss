[Files]
Source: ..\new-gui\NewDocfrac.exe; DestDir: {app}; Flags: 32bit
[Setup]
AppName=DocFrac
AppCopyright=Copyright 2006 Andrew Punch
AppVerName=3.1.4
DefaultDirName={pf}\DocFrac\
DefaultGroupName=DocFrac
ShowLanguageDialog=yes
InternalCompressLevel=ultra
OutputBaseFilename=docfrac-win32-gui
[Icons]
Name: {group}\DocFrac; Filename: {app}\NewDocfrac.exe; WorkingDir: {app}; IconFilename: {app}\NewDocfrac.exe
Name: {group}\{cm:UninstallProgram, DocFrac}; Filename: {uninstallexe}
[UninstallDelete]
Name: {app}\NewDocfrac.exe; Type: files
