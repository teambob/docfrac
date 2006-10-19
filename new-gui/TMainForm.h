//---------------------------------------------------------------------------
#ifndef TMainFormH
#define TMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class Documents;

class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *MainToolbar;
    TMainMenu *MainMenu;
    TMenuItem *FileMenu;
    TMenuItem *FileExit;
    TMenuItem *HelpMenu;
    TMenuItem *HelpAbout;
    TMenuItem *FileAdd;
    TOpenDialog *OpenFilesDialog;
    TToolButton *AddIcon;
    TImageList *ToolbarImages;
    TToolButton *RemoveIcon;
    TToolButton *ClearIcon;
    TToolButton *SpacerIcon;
    TToolButton *ConvertIcon;
    TToolButton *PropertiesIcon;
    TMenuItem *FileProperties;
    TPopupMenu *ContextMenu;
    TMenuItem *PopupAdd;
    TMenuItem *N1;
    TMenuItem *PopupProperties;
    TMenuItem *PopupRemove;
    TListView *FileList;
    TMenuItem *FileConvert;
    TMenuItem *N2;
    TStatusBar *MainStatusBar;
    TMenuItem *EditMenu;
    TMenuItem *EditSelectAll;
    TMenuItem *EditRemove;
    TMenuItem *EditClear;
    void __fastcall FileAddClick(TObject *Sender);


    void __fastcall ContextMenuPopup(TObject *Sender);
    
    void __fastcall ClearIconClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FileExitClick(TObject *Sender);
    void __fastcall ConvertClick(TObject *Sender);
    
    void __fastcall HelpAboutClick(TObject *Sender);
    void __fastcall PropertiesClick(TObject *Sender);
    
    
    void __fastcall EditSelectAllClick(TObject *Sender);
    void __fastcall RemoveIconClick(TObject *Sender);
    void __fastcall FileListChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
private:	// User declarations
  Documents *documents;
  void UpdateDisplay(void);
  void UpdateEnabled(void);
  void __fastcall OnDropFiles(TWMDropFiles& Message);

public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);

BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_DROPFILES, TWMDropFiles, OnDropFiles)
END_MESSAGE_MAP(TForm)
    
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
