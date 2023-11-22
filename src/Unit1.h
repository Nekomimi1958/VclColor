//----------------------------------------------------------------------//
// VclColor																//
//----------------------------------------------------------------------//
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include "usr_color.h"
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>
#include <Vcl.VirtualImage.hpp>

//---------------------------------------------------------------------------
class TVclColForm : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TComboBox *FilterComboBox;
	TComboBox *L_ComboBox;
	TComboBox *TriComboBox;
	TFontDialog *FontDialog1;
	TLabel *Label4;
	TLabel *Label5;
	TListBox *ColorListBox;
	TListBox *ValListBox;
	TMenuItem *CopyAllItem;
	TMenuItem *CopyValItem;
	TMenuItem *CustomSetItem;
	TMenuItem *SelFontItem;
	TMenuItem *Sep_1;
	TMenuItem *StyleItem;
	TPanel *CmpPanel;
	TPanel *ColPanel;
	TPanel *LeftPanel;
	TPanel *RightPanel;
	TPanel *TargetPanel;
	TPanel *TopPanel;
	TPanel *TriPanel;
	TPanel *TriPanel1;
	TPanel *TriPanel2;
	TPanel *TriPanel3;
	TPopupMenu *PopupMenu1;
	TPopupMenu *PopupMenu2;
	TPopupMenu *PopupMenu3;
	TTabControl *TabControl1;
	TTimer *Timer1;
	TVirtualImage *VirtualImage1;
	TImageCollection *ImageCollection1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall TabControl1Changing(TObject *Sender, bool &AllowChange);
	void __fastcall TabControl1Change(TObject *Sender);
	void __fastcall FilterComboBoxClick(TObject *Sender);
	void __fastcall TriComboBoxClick(TObject *Sender);
	void __fastcall ColorListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall ColorListBoxClick(TObject *Sender);
	void __fastcall ColPanelClick(TObject *Sender);
	void __fastcall ValListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall ValListBoxDblClick(TObject *Sender);
	void __fastcall CopyValItemClick(TObject *Sender);
	void __fastcall CopyAllItemClick(TObject *Sender);
	void __fastcall CustomSetItemClick(TObject *Sender);
	void __fastcall SelFontItemClick(TObject *Sender);
	void __fastcall SelStyleItemClick(TObject *Sender);
	void __fastcall VirtualImage1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall VirtualImage1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private:	// ���[�U�[�錾
	TIniFile *IniFile;

	TFont *ListFont;

	TCursor crSpuit;
	bool Capturing;
	TColor LastColor;
	TColor IdxColor;

	TColor col_window;
	TColor col_VCL;
	TColor col_System;
	TColor col_Style;

	TStringList *VclColList;
	TStringList *StyleColList;
	TStringList *SafeColList;
	TStringList *SysColList;

	TStringList *FCurList;
	TStringList * __fastcall GetCurList() {
		return ((TabControl1->TabIndex==1)? SysColList :
				(TabControl1->TabIndex==2)? StyleColList :
				(TabControl1->TabIndex==3)? SafeColList : VclColList);
	}
	__property TStringList *CurList = {read = GetCurList};

	void __fastcall SetPanelCol(TPanel *pp, TColor col, UnicodeString tit = EmptyStr)
	{
		pp->Color = col;
		pp->Font->Color = SelectWorB(col);
		if (!tit.IsEmpty()) pp->Caption = tit;
	}

	void __fastcall ClearRightPanel();
    void __fastcall SetStyleColList();
	void __fastcall SetTriColorCore(TColor col, UnicodeString cs);
	void __fastcall SetTriColor(TColor col);

	void __fastcall SetListBoxFont(TListBox *lp)
	{
		lp->Font->Assign(ListFont);
		TCanvas *cv = lp->Canvas;
		cv->Font->Assign(ListFont);
		lp->ItemHeight = cv->TextHeight("Q") * 5 / 4;
	}

public:		// ���[�U�[�錾
	UnicodeString CustomScheme;

	__fastcall TVclColForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVclColForm *VclColForm;
//---------------------------------------------------------------------------
#endif
