//----------------------------------------------------------------------//
// Custom Scheme Setting												//
//----------------------------------------------------------------------//
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TCustomDlg : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TRadioGroup *RadioGroup1;
	TTrackBar *TrackBar1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);

private:	// ���[�U�[�錾
	UnicodeString __fastcall GetCustomStr();

public:		// ���[�U�[�錾
	UnicodeString Scheme;
	int LastH, LastS, LastL;

	__fastcall TCustomDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCustomDlg *CustomDlg;
//---------------------------------------------------------------------------
#endif
