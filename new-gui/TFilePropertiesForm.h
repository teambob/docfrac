//---------------------------------------------------------------------------
#ifndef TFilePropertiesFormH
#define TFilePropertiesFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class FilenameClass;


class TFilePropertiesForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *OutputFormatGroup;
    TComboBox *OutputFormatSelect;
    TGroupBox *OutputFilenameGroup;
    TLabel *Label1;
    TEdit *OutputFilenameEdit;
    TButton *OutputFilenameBrowse;
    TCheckBox *AutomaticFilenameSelect;
    TRadioButton *InputDirectorySelect;
    TRadioButton *OutputDirectorySelect;
    TEdit *OutputDirectoryEdit;
    TButton *OutputDirectoryBrowse;
    TButton *Button1;
    TButton *Button2;
    TSaveDialog *OutputFilenameDialog;
    void __fastcall OutputFilenameBrowseClick(TObject *Sender);
    void __fastcall AutomaticFilenameSelectClick(TObject *Sender);
    void __fastcall InputDirectorySelectClick(TObject *Sender);
    void __fastcall OutputDirectorySelectClick(TObject *Sender);
    void __fastcall OutputDirectoryBrowseClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
  bool multiFile;
  FilenameClass *lastFile;
public:		// User declarations
    __fastcall TFilePropertiesForm(TComponent* Owner);
    virtual __fastcall ~TFilePropertiesForm();
    void SetMultiFile(bool value);
		void LoadOptions();
    void SaveOptions();
};
//---------------------------------------------------------------------------
extern PACKAGE TFilePropertiesForm *FilePropertiesForm;
//---------------------------------------------------------------------------
#endif
