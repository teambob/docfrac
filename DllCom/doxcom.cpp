#include <vcl.h>
#include <registry.hpp>
#include <syncobjs.hpp>
#include <time.h>
#pragma hdrstop
#include <atl\atlvcl.h>
#include <string>

#define LOCALKeyName "SOFTWARE\\Dox\\2.00"
#define MAXTHREADS 10

#include "TDox.h"
#include "DoxLib.h"

#include "DocFracLib.h"
#pragma package(smart_init)
USERES("doxcom.res");
USEUNIT("doxcom_ATL.cpp");
USETLB("doxcom.tlb");
USEUNIT("doxcom_TLB.cpp");
USEUNIT("DoxLib.cpp"); /* DoxLib: CoClass */
USEUNIT("tdox.cpp");
USEUNIT("..\WriterInterface.cpp");
USEUNIT("..\DoxFactory.cpp");
USEUNIT("..\DoxInterface.cpp");
USEUNIT("..\HtmlCharacterMap.cpp");
USEUNIT("..\HtmlReader.cpp");
USEUNIT("..\HtmlWriter.cpp");
USEUNIT("..\ReaderInterface.cpp");
USEUNIT("..\RtfCommand.cpp");
USEUNIT("..\RtfReader.cpp");
USEUNIT("..\RtfStyle.cpp");
USEUNIT("..\RtfWriter.cpp");
USEUNIT("..\Style.cpp");
USEUNIT("..\TextWriter.cpp");
USEUNIT("..\UnicodeCharacter.cpp");
USEUNIT("..\debug.cpp");
USEUNIT("..\ExtensionToFormatMap.cpp");
USEUNIT("..\FileFormat.cpp");
USEUNIT("..\..\..\dox_stuff\docfrac-3.1.0\DllCom\DocFracLib.cpp");
USEUNIT("..\..\..\dox_stuff\docfrac-3.1.0\DllCom\ConvertBSTR.cpp");
//---------------------------------------------------------------------------
TComModule  Project2Module;
TComModule &_Module = Project2Module;
//TCriticalSection *LockModule=NULL;
HANDLE DoxComSemaphore;

#if defined(DoxCOMTrial)
int TestTrial(void);
int Mime2Int(int Chr);
#endif

// The ATL Object map holds an array of _ATL_OBJMAP_ENTRY structures that
// described the objects of your OLE server. The MAP is handed to your
// project's CComModule-derived _Module object via the Init method.
//
BEGIN_OBJECT_MAP(ObjectMap)
  OBJECT_ENTRY(CLSID_DoxLib, TDoxLibImpl)
  OBJECT_ENTRY(CLSID_DocFracLib, TDocFracLibImpl)
END_OBJECT_MAP()

// Entry point of your Server invoked by Windows for processes or threads are
// initialized or terminated.
//
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        #if defined(DoxCOMTrial)
            if (!TestTrial())
                {
                ShowMessage("Trial period over or code invalid.\n"
                "Try running trial.exe or"
                " visit http://users.hunterlink.net.au/~mabatp/");
                }
        #endif
        //if (LockModule==NULL)
        //    LockModule=new TCriticalSection;
        //LockModule->Acquire();
        DoxComSemaphore = CreateSemaphore(NULL, MAXTHREADS, MAXTHREADS, NULL);
        if (DoxComSemaphore==NULL)
            OutputDebugString("Semaphore creation failed.");

        _Module.Init(ObjectMap, hinst);
        DisableThreadLibraryCalls(hinst);
    }
    return TRUE;
}

// _Module.Term is typically invoked from the DLL_PROCESS_DETACH of your
// DllEntryPoint. However, this may result in an incorrect shutdown sequence.
// Instead an Exit routine is setup to invoke the cleanup routine
// CComModule::Term.
//
void ModuleTerm(void)
{
    CloseHandle(DoxComSemaphore);
    _Module.Term();
    //LockModule->Release();
}
#pragma exit ModuleTerm 63

// Entry point of your Server invoked to inquire whether the DLL is no
// longer in use and should be unloaded.
//
STDAPI __export DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

// Entry point of your Server allowing OLE to retrieve a class object from
// your Server
//
STDAPI __export DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

// Entry point of your Server invoked to instruct the server to create
// registry entries for all classes supported by the module
//
STDAPI __export DllRegisterServer(void)
{
    return _Module.RegisterServer(TRUE);
}

// Entry point of your Server invoked to instruct the server to remove
// all registry entries created through DllRegisterServer.
//
STDAPI __export DllUnregisterServer(void)
{
    return _Module.UnregisterServer();
}
//---------------------------------------------------------------------------
#if defined(DoxCOMTrial)
int TestTrial(void)
{
TRegistry *Reg;
AnsiString Rego;
int Count, Match;
long Jul, InvJul, JulNow;
struct tm Time;
time_t CurTime;

Reg = new TRegistry;

Reg->RootKey = HKEY_LOCAL_MACHINE;
Reg->OpenKey(LOCALKeyName, false);
if (Reg->ValueExists("ITU"))
        {
        Rego = Reg->ReadString("ITU");
        Jul = 0;
        InvJul = 0;
        for (Count=0;Count<=5;Count++)
            {
            Jul |= Mime2Int(Rego[Count+1])<<((5-Count)*5);
            InvJul |= Mime2Int(Rego[Count+7])<<((5-Count)*5);
            }

        if (Jul!=((~InvJul)&0x20FFFFFF)) // 30bit
            Match=false;
        else
            {
            time(&CurTime);
            Time = *localtime(&CurTime);
            JulNow = Time.tm_yday + Time.tm_year*1000;
            if (JulNow<=Jul)
                Match = true;
            else
                Match = false;
            }
        }
    else
        Match = false;
    Reg->RootKey = HKEY_CURRENT_USER;
    Reg->CloseKey();
    delete Reg;
return Match;
}

int Mime2Int(int Chr)
{
/* 0 - 9 => 0 - 9, 10 - 35 => a - z, 36 - 62 => A - Z, 63 => ( */
if ((Chr>='0')&&(Chr<='9'))
    return (Chr-'0');
else if ((Chr>='a')&&(Chr<='z'))
    return (Chr-'a'+10);
else if ((Chr>='A')&&(Chr<='Z'))
    return (Chr-'A'+36);
else return 63;
}
#endif

