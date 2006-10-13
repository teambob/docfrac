//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("TFilePropertiesForm.cpp", FilePropertiesForm);
USEFORM("TMainForm.cpp", MainForm);
USEFORM("TProgressForm.cpp", ProgressForm);
USEFORM("TAboutForm.cpp", AboutForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "DocFrac";
        Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TFilePropertiesForm), &FilePropertiesForm);
		Application->CreateForm(__classid(TProgressForm), &ProgressForm);
		Application->CreateForm(__classid(TAboutForm), &AboutForm);
		Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
