//----------------------------------------------------------------------//
// Custom Scheme Setting												//
//----------------------------------------------------------------------//
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCustomDlg *CustomDlg;

//---------------------------------------------------------------------------
__fastcall TCustomDlg::TCustomDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCustomDlg::FormCreate(TObject *Sender)
{
	LastH = LastS = LastL =0;
}
//---------------------------------------------------------------------------
void __fastcall TCustomDlg::FormShow(TObject *Sender)
{
	RadioGroup1->ItemIndex = StartsStr("S", Scheme)? 1 : StartsStr("L", Scheme)? 2 : 0;
	RadioGroup1Click(NULL);
	TrackBar1->Position = Scheme.SubString(2, 3).ToIntDef(0);
}
//---------------------------------------------------------------------------
void __fastcall TCustomDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
	Scheme = GetCustomStr();
}

//---------------------------------------------------------------------------
UnicodeString __fastcall TCustomDlg::GetCustomStr()
{
	UnicodeString cs = (RadioGroup1->ItemIndex==1)? "S" : (RadioGroup1->ItemIndex==2)? "L" : "H";
	cs.cat_printf(_T("%u"), TrackBar1->Position);
	return cs;
}
//---------------------------------------------------------------------------
void __fastcall TCustomDlg::RadioGroup1Click(TObject *Sender)
{
	TrackBar1->Enabled = false;
	switch (RadioGroup1->ItemIndex) {
	case 1:
		TrackBar1->Max = 50;
		TrackBar1->Frequency = 10;
		if (Sender) TrackBar1->Position = LastS;
		break;
	case 2:
		TrackBar1->Max = 50;
		TrackBar1->Frequency = 10;
		if (Sender) TrackBar1->Position = LastL;
		break;
	default:
		TrackBar1->Max = 180;
		TrackBar1->Frequency = 60;
		if (Sender) TrackBar1->Position = LastH;
	}
	TrackBar1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TCustomDlg::TrackBar1Change(TObject *Sender)
{
	Caption = "Custom Scheme (" + GetCustomStr() + ")";
	if (TrackBar1->Enabled) {
		((RadioGroup1->ItemIndex==1)? LastS : (RadioGroup1->ItemIndex==2)? LastL : LastH)
			= TrackBar1->Position;
	}
}
//---------------------------------------------------------------------------
