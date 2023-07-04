//----------------------------------------------------------------------//
// VclColor																//
//----------------------------------------------------------------------//
#include "usr_env.h"
#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVclColForm *VclColForm;

//---------------------------------------------------------------------------
__fastcall TVclColForm::TVclColForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::FormCreate(TObject *Sender)
{
	unsigned int preference = 1;	//DONOTROUND
	DwmSetWindowAttribute(Handle, 33, &preference, sizeof(preference));

	crSpuit = (TCursor)6;
	Screen->Cursors[crSpuit] = (HCURSOR)::LoadImage(HInstance, _T("SPUIT_TOOL"), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE);
	Capturing = false;

	IniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));

	ListFont = load_font_inf(IniFile, "List",	 Application->DefaultFont);
	SetListBoxFont(ColorListBox);
	SetListBoxFont(ValListBox);

	CustomScheme = IniFile->ReadString("Option", "CustomScheme", "H72");
	TriComboBox->Items->Strings[TriComboBox->Items->Count - 1] = "Custom Scheme (" + CustomScheme + ")";

	VclColList  = new TStringList();
	SafeColList = new TStringList();
	SysColList  = new TStringList();

	//VCL/Web Color
	VclColList->AddObject("clBlack",			(TObject*)clBlack);
	VclColList->AddObject("clMaroon",			(TObject*)clMaroon);
	VclColList->AddObject("clGreen",			(TObject*)clGreen);
	VclColList->AddObject("clOlive",			(TObject*)clOlive);
	VclColList->AddObject("clNavy",				(TObject*)clNavy);
	VclColList->AddObject("clPurple",			(TObject*)clPurple);
	VclColList->AddObject("clTeal",				(TObject*)clTeal);
	VclColList->AddObject("clGray",				(TObject*)clGray);
	VclColList->AddObject("clSilver",			(TObject*)clSilver);
	VclColList->AddObject("clRed",				(TObject*)clRed);
	VclColList->AddObject("clLime",				(TObject*)clLime);
	VclColList->AddObject("clYellow",			(TObject*)clYellow);
	VclColList->AddObject("clBlue",				(TObject*)clBlue);
	VclColList->AddObject("clFuchsia",			(TObject*)clFuchsia);
	VclColList->AddObject("clAqua",				(TObject*)clAqua);
	VclColList->AddObject("clLtGray",			(TObject*)clLtGray);
	VclColList->AddObject("clDkGray",			(TObject*)clDkGray);
	VclColList->AddObject("clWhite",			(TObject*)clWhite);
	VclColList->AddObject("clMoneyGreen",		(TObject*)clMoneyGreen);
	VclColList->AddObject("clSkyBlue",			(TObject*)clSkyBlue);
	VclColList->AddObject("clCream",			(TObject*)clCream);
	VclColList->AddObject("clMedGray",			(TObject*)clMedGray);
	VclColList->AddObject("clWebSnow",			(TObject*)clWebSnow);
	VclColList->AddObject("clWebFloralWhite",	(TObject*)clWebFloralWhite);
	VclColList->AddObject("clWebLavenderBlush",	(TObject*)clWebLavenderBlush);
	VclColList->AddObject("clWebOldLace",		(TObject*)clWebOldLace);
	VclColList->AddObject("clWebIvory",			(TObject*)clWebIvory);
	VclColList->AddObject("clWebCornSilk",		(TObject*)clWebCornSilk);
	VclColList->AddObject("clWebBeige",			(TObject*)clWebBeige);
	VclColList->AddObject("clWebAntiqueWhite",	(TObject*)clWebAntiqueWhite);
	VclColList->AddObject("clWebWheat",			(TObject*)clWebWheat);
	VclColList->AddObject("clWebAliceBlue",		(TObject*)clWebAliceBlue);
	VclColList->AddObject("clWebGhostWhite",	(TObject*)clWebGhostWhite);
	VclColList->AddObject("clWebLavender",		(TObject*)clWebLavender);
	VclColList->AddObject("clWebSeashell",		(TObject*)clWebSeashell);
	VclColList->AddObject("clWebLightYellow",	(TObject*)clWebLightYellow);
	VclColList->AddObject("clWebPapayaWhip",	(TObject*)clWebPapayaWhip);
	VclColList->AddObject("clWebNavajoWhite",	(TObject*)clWebNavajoWhite);
	VclColList->AddObject("clWebMoccasin",		(TObject*)clWebMoccasin);
	VclColList->AddObject("clWebBurlywood",		(TObject*)clWebBurlywood);
	VclColList->AddObject("clWebAzure",			(TObject*)clWebAzure);
	VclColList->AddObject("clWebMintcream",		(TObject*)clWebMintcream);
	VclColList->AddObject("clWebHoneydew",		(TObject*)clWebHoneydew);
	VclColList->AddObject("clWebLinen",			(TObject*)clWebLinen);
	VclColList->AddObject("clWebLemonChiffon",	(TObject*)clWebLemonChiffon);
	VclColList->AddObject("clWebBlanchedAlmond",(TObject*)clWebBlanchedAlmond);
	VclColList->AddObject("clWebBisque",		(TObject*)clWebBisque);
	VclColList->AddObject("clWebPeachPuff",		(TObject*)clWebPeachPuff);
	VclColList->AddObject("clWebTan",			(TObject*)clWebTan);
	VclColList->AddObject("clWebYellow",		(TObject*)clWebYellow);
	VclColList->AddObject("clWebDarkOrange",	(TObject*)clWebDarkOrange);
	VclColList->AddObject("clWebRed",			(TObject*)clWebRed);
	VclColList->AddObject("clWebDarkRed",		(TObject*)clWebDarkRed);
	VclColList->AddObject("clWebMaroon",		(TObject*)clWebMaroon);
	VclColList->AddObject("clWebIndianRed",		(TObject*)clWebIndianRed);
	VclColList->AddObject("clWebSalmon",		(TObject*)clWebSalmon);
	VclColList->AddObject("clWebCoral",			(TObject*)clWebCoral);
	VclColList->AddObject("clWebGold",			(TObject*)clWebGold);
	VclColList->AddObject("clWebTomato",		(TObject*)clWebTomato);
	VclColList->AddObject("clWebCrimson",		(TObject*)clWebCrimson);
	VclColList->AddObject("clWebBrown",			(TObject*)clWebBrown);
	VclColList->AddObject("clWebChocolate",		(TObject*)clWebChocolate);
	VclColList->AddObject("clWebSandyBrown",	(TObject*)clWebSandyBrown);
	VclColList->AddObject("clWebLightSalmon",	(TObject*)clWebLightSalmon);
	VclColList->AddObject("clWebLightCoral",	(TObject*)clWebLightCoral);
	VclColList->AddObject("clWebOrange",		(TObject*)clWebOrange);
	VclColList->AddObject("clWebOrangeRed",		(TObject*)clWebOrangeRed);
	VclColList->AddObject("clWebFirebrick",		(TObject*)clWebFirebrick);
	VclColList->AddObject("clWebSaddleBrown",	(TObject*)clWebSaddleBrown);
	VclColList->AddObject("clWebSienna",		(TObject*)clWebSienna);
	VclColList->AddObject("clWebPeru",			(TObject*)clWebPeru);
	VclColList->AddObject("clWebDarkSalmon",	(TObject*)clWebDarkSalmon);
	VclColList->AddObject("clWebRosyBrown",		(TObject*)clWebRosyBrown);
	VclColList->AddObject("clWebPaleGoldenrod",	(TObject*)clWebPaleGoldenrod);
	VclColList->AddObject("clWebLightGoldenrodYellow",	(TObject*)clWebLightGoldenrodYellow);
	VclColList->AddObject("clWebOlive",			(TObject*)clWebOlive);
	VclColList->AddObject("clWebForestGreen",	(TObject*)clWebForestGreen);
	VclColList->AddObject("clWebGreenYellow",	(TObject*)clWebGreenYellow);
	VclColList->AddObject("clWebChartreuse",	(TObject*)clWebChartreuse);
	VclColList->AddObject("clWebLightGreen",	(TObject*)clWebLightGreen);
	VclColList->AddObject("clWebAquamarine",	(TObject*)clWebAquamarine);
	VclColList->AddObject("clWebSeaGreen",		(TObject*)clWebSeaGreen);
	VclColList->AddObject("clWebGoldenRod",		(TObject*)clWebGoldenRod);
	VclColList->AddObject("clWebKhaki",			(TObject*)clWebKhaki);
	VclColList->AddObject("clWebOliveDrab",		(TObject*)clWebOliveDrab);
	VclColList->AddObject("clWebGreen",			(TObject*)clWebGreen);
	VclColList->AddObject("clWebYellowGreen",	(TObject*)clWebYellowGreen);
	VclColList->AddObject("clWebLawnGreen",		(TObject*)clWebLawnGreen);
	VclColList->AddObject("clWebPaleGreen",		(TObject*)clWebPaleGreen);
	VclColList->AddObject("clWebMediumAquamarine",	(TObject*)clWebMediumAquamarine);
	VclColList->AddObject("clWebMediumSeaGreen",	(TObject*)clWebMediumSeaGreen);
	VclColList->AddObject("clWebDarkGoldenRod",	(TObject*)clWebDarkGoldenRod);
	VclColList->AddObject("clWebDarkKhaki",		(TObject*)clWebDarkKhaki);
	VclColList->AddObject("clWebDarkOliveGreen",(TObject*)clWebDarkOliveGreen);
	VclColList->AddObject("clWebDarkgreen",		(TObject*)clWebDarkgreen);
	VclColList->AddObject("clWebLimeGreen",		(TObject*)clWebLimeGreen);
	VclColList->AddObject("clWebLime",			(TObject*)clWebLime);
	VclColList->AddObject("clWebSpringGreen",	(TObject*)clWebSpringGreen);
	VclColList->AddObject("clWebMediumSpringGreen",	(TObject*)clWebMediumSpringGreen);
	VclColList->AddObject("clWebDarkSeaGreen",	(TObject*)clWebDarkSeaGreen);
	VclColList->AddObject("clWebLightSeaGreen",	(TObject*)clWebLightSeaGreen);
	VclColList->AddObject("clWebPaleTurquoise",	(TObject*)clWebPaleTurquoise);
	VclColList->AddObject("clWebLightCyan",		(TObject*)clWebLightCyan);
	VclColList->AddObject("clWebLightBlue",		(TObject*)clWebLightBlue);
	VclColList->AddObject("clWebLightSkyBlue",	(TObject*)clWebLightSkyBlue);
	VclColList->AddObject("clWebCornFlowerBlue",(TObject*)clWebCornFlowerBlue);
	VclColList->AddObject("clWebDarkBlue",		(TObject*)clWebDarkBlue);
	VclColList->AddObject("clWebIndigo",		(TObject*)clWebIndigo);
	VclColList->AddObject("clWebMediumTurquoise",	(TObject*)clWebMediumTurquoise);
	VclColList->AddObject("clWebTurquoise",		(TObject*)clWebTurquoise);
	VclColList->AddObject("clWebCyan",			(TObject*)clWebCyan);
	VclColList->AddObject("clWebAqua",			(TObject*)clWebAqua);
	VclColList->AddObject("clWebPowderBlue",	(TObject*)clWebPowderBlue);
	VclColList->AddObject("clWebSkyBlue",		(TObject*)clWebSkyBlue);
	VclColList->AddObject("clWebRoyalBlue",		(TObject*)clWebRoyalBlue);
	VclColList->AddObject("clWebMediumBlue",	(TObject*)clWebMediumBlue);
	VclColList->AddObject("clWebMidnightBlue",	(TObject*)clWebMidnightBlue);
	VclColList->AddObject("clWebDarkTurquoise",	(TObject*)clWebDarkTurquoise);
	VclColList->AddObject("clWebCadetBlue",		(TObject*)clWebCadetBlue);
	VclColList->AddObject("clWebDarkCyan",		(TObject*)clWebDarkCyan);
	VclColList->AddObject("clWebTeal",			(TObject*)clWebTeal);
	VclColList->AddObject("clWebDeepskyBlue",	(TObject*)clWebDeepskyBlue);
	VclColList->AddObject("clWebDodgerBlue",	(TObject*)clWebDodgerBlue);
	VclColList->AddObject("clWebBlue",			(TObject*)clWebBlue);
	VclColList->AddObject("clWebNavy",			(TObject*)clWebNavy);
	VclColList->AddObject("clWebDarkViolet",	(TObject*)clWebDarkViolet);
	VclColList->AddObject("clWebDarkOrchid",	(TObject*)clWebDarkOrchid);
	VclColList->AddObject("clWebMagenta",		(TObject*)clWebMagenta);
	VclColList->AddObject("clWebFuchsia",		(TObject*)clWebFuchsia);
	VclColList->AddObject("clWebDarkMagenta",	(TObject*)clWebDarkMagenta);
	VclColList->AddObject("clWebMediumVioletRed",	(TObject*)clWebMediumVioletRed);
	VclColList->AddObject("clWebPaleVioletRed",	(TObject*)clWebPaleVioletRed);
	VclColList->AddObject("clWebBlueViolet",	(TObject*)clWebBlueViolet);
	VclColList->AddObject("clWebMediumOrchid",	(TObject*)clWebMediumOrchid);
	VclColList->AddObject("clWebMediumPurple",	(TObject*)clWebMediumPurple);
	VclColList->AddObject("clWebPurple",		(TObject*)clWebPurple);
	VclColList->AddObject("clWebDeepPink",		(TObject*)clWebDeepPink);
	VclColList->AddObject("clWebLightPink",		(TObject*)clWebLightPink);
	VclColList->AddObject("clWebViolet",		(TObject*)clWebViolet);
	VclColList->AddObject("clWebOrchid",		(TObject*)clWebOrchid);
	VclColList->AddObject("clWebPlum",			(TObject*)clWebPlum);
	VclColList->AddObject("clWebThistle",		(TObject*)clWebThistle);
	VclColList->AddObject("clWebHotPink",		(TObject*)clWebHotPink);
	VclColList->AddObject("clWebPink",			(TObject*)clWebPink);
	VclColList->AddObject("clWebLightSteelBlue",(TObject*)clWebLightSteelBlue);
	VclColList->AddObject("clWebMediumSlateBlue",	(TObject*)clWebMediumSlateBlue);
	VclColList->AddObject("clWebLightSlateGray",(TObject*)clWebLightSlateGray);
	VclColList->AddObject("clWebWhite",			(TObject*)clWebWhite);
	VclColList->AddObject("clWebLightgrey",		(TObject*)clWebLightgrey);
	VclColList->AddObject("clWebGray",			(TObject*)clWebGray);
	VclColList->AddObject("clWebSteelBlue",		(TObject*)clWebSteelBlue);
	VclColList->AddObject("clWebSlateBlue",		(TObject*)clWebSlateBlue);
	VclColList->AddObject("clWebSlateGray",		(TObject*)clWebSlateGray);
	VclColList->AddObject("clWebWhiteSmoke",	(TObject*)clWebWhiteSmoke);
	VclColList->AddObject("clWebSilver",		(TObject*)clWebSilver);
	VclColList->AddObject("clWebDimGray",		(TObject*)clWebDimGray);
	VclColList->AddObject("clWebMistyRose",		(TObject*)clWebMistyRose);
	VclColList->AddObject("clWebDarkSlateBlue",	(TObject*)clWebDarkSlateBlue);
	VclColList->AddObject("clWebDarkSlategray",	(TObject*)clWebDarkSlategray);
	VclColList->AddObject("clWebGainsboro",		(TObject*)clWebGainsboro);
	VclColList->AddObject("clWebDarkGray",		(TObject*)clWebDarkGray);
	VclColList->AddObject("clWebBlack",			(TObject*)clWebBlack);

	//Web Safe Color
	for (int r=0; r<=0xff; r+=0x33) {
		for (int g=0; g<=0xff; g+=0x33) {
			for (int b=0; b<=0xff; b+=0x33) {
				SafeColList->AddObject(
					UnicodeString().sprintf(_T("#%02x%02x%02x"), r, g, b),
					(TObject*)TColor(RGB(r, g, b)));
			}
		}
	}

	//System Color
	SysColList->AddObject("clScrollBar",		(TObject*)clScrollBar);
	SysColList->AddObject("clBackground",		(TObject*)clBackground);
	SysColList->AddObject("clActiveCaption",	(TObject*)clActiveCaption);
	SysColList->AddObject("clInactiveCaption",	(TObject*)clInactiveCaption);
	SysColList->AddObject("clMenu",				(TObject*)clMenu);
	SysColList->AddObject("clWindow",			(TObject*)clWindow);
	SysColList->AddObject("clWindowFrame",		(TObject*)clWindowFrame);
	SysColList->AddObject("clMenuText",			(TObject*)clMenuText);
	SysColList->AddObject("clWindowText",		(TObject*)clWindowText);
	SysColList->AddObject("clCaptionText",		(TObject*)clCaptionText);
	SysColList->AddObject("clActiveBorder",		(TObject*)clActiveBorder);
	SysColList->AddObject("clInactiveBorder",	(TObject*)clInactiveBorder);
	SysColList->AddObject("clAppWorkSpace",		(TObject*)clAppWorkSpace);
	SysColList->AddObject("clHighlight",		(TObject*)clHighlight);
	SysColList->AddObject("clHighlightText",	(TObject*)clHighlightText);
	SysColList->AddObject("clBtnFace",			(TObject*)clBtnFace);
	SysColList->AddObject("clBtnShadow",		(TObject*)clBtnShadow);
	SysColList->AddObject("clGrayText",			(TObject*)clGrayText);
	SysColList->AddObject("clBtnText",			(TObject*)clBtnText);
	SysColList->AddObject("clInactiveCaptionText",	(TObject*)clInactiveCaptionText);
	SysColList->AddObject("clBtnHighlight",		(TObject*)clBtnHighlight);
	SysColList->AddObject("cl3DDkShadow",		(TObject*)cl3DDkShadow);
	SysColList->AddObject("cl3DLight",			(TObject*)cl3DLight);
	SysColList->AddObject("clInfoText",			(TObject*)clInfoText);
	SysColList->AddObject("clInfoBk",			(TObject*)clInfoBk);
	SysColList->AddObject("clHotLight",			(TObject*)clHotLight);
	SysColList->AddObject("clGradientActiveCaption",	(TObject*)clGradientActiveCaption);
	SysColList->AddObject("clGradientInactiveCaption",	(TObject*)clGradientInactiveCaption);
	SysColList->AddObject("clMenuHighlight",	(TObject*)clMenuHighlight);
	SysColList->AddObject("clMenuBar",			(TObject*)clMenuBar);
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::FormShow(TObject *Sender)
{
	load_form_pos(this, IniFile, 580, 480);

	FilterComboBox->ItemIndex = 0;
	L_ComboBox->ItemIndex     = 0;
	TriComboBox->ItemIndex    = IniFile->ReadInteger("Option", "TriComboIndex", 0);

	TabControl1Change(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	save_form_pos(this, IniFile);
	save_font_inf(IniFile, "List",	ListFont);
	IniFile->WriteString( "Option", "CustomScheme", CustomScheme);
	IniFile->WriteInteger("Option", "TriComboIndex", TriComboBox->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::FormDestroy(TObject *Sender)
{
	delete VclColList;
	delete SafeColList;
	delete SysColList;
	delete ListFont;
	delete IniFile;
}

//---------------------------------------------------------------------------
void __fastcall TVclColForm::Timer1Timer(TObject *Sender)
{
	if (Capturing) {
		TPoint lt = RightPanel->ClientToScreen(Point(0, 0));
		TPoint rb = RightPanel->ClientToScreen(Point(RightPanel->Width, ColPanel->Height * 3));
		TRect rc = Rect(lt.x, lt.y, rb.x, rb.y);
		if (!rc.PtInRect(Mouse->CursorPos)) {
			HDC hDc = ::GetDC(0);
			if (hDc) {
				POINT p = Mouse->CursorPos;
				COLORREF c = ::GetPixel(hDc, p.x, p.y);
				::ReleaseDC(0, hDc);
				TColor col = TColor(c);
				if (col!=LastColor) {
					SetPanelCol(ColPanel, col, "<Captured>");
					SetPanelCol(CmpPanel, ComplementaryCol(col));
					SetTriColor(col);
					ColPanelClick(ColPanel);
					LastColor = col;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::FormResize(TObject *Sender)
{
	ColorListBox->Invalidate();
	ValListBox->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TVclColForm::SetTriColorCore(TColor col, UnicodeString cs)
{
	int h,s,l;
	RgbToHsl(col, &h, &s, &l);
	int m = StartsStr('S', cs)? 1 : StartsStr('L', cs)? 2 : 0;
	int d = cs.SubString(2, 3).ToIntDef(0);
	UnicodeString lbl;

	switch (m) {
	case 1:		//S
		{
			int ul   = 100 - d;
			int s_p  = std::clamp(s + d,	 0, 100);
			int s_p2 = std::clamp(s + d * 2, 0, 100);
			int s_n  = std::clamp(s - d,	 0, 100);
			int s_n2 = std::clamp(s - d * 2, 0, 100);
			if (s<=ul && s>=d) {
				SetPanelCol(TriPanel1,	HslToCol(h, s_p, l), lbl.sprintf(_T("+S%u"), s_p - s));
				SetPanelCol(TriPanel2,	col, "0");
				SetPanelCol(TriPanel3,	HslToCol(h, s_n, l), lbl.sprintf(_T("-S%u"), s - s_n));
			}
			else if (s>ul) {
				SetPanelCol(TriPanel1,	col, "0");
				SetPanelCol(TriPanel2,	HslToCol(h, s_n,  l), lbl.sprintf(_T("-S%u"), s - s_n));
				SetPanelCol(TriPanel3,	HslToCol(h, s_n2, l), lbl.sprintf(_T("-S%u"), s - s_n2));
			}
			else if (s<d) {
				SetPanelCol(TriPanel1,	col, "0");
				SetPanelCol(TriPanel2,	HslToCol(h, s_p,  l), lbl.sprintf(_T("+S%u"), s_p - s));
				SetPanelCol(TriPanel3,	HslToCol(h, s_p2, l), lbl.sprintf(_T("+S%u"), s_p2 - s));
			}
		}
		break;
	case 2:		//L
		{
			int ul   = 100 - d;
			int l_p  = std::clamp(l + d,	 0, 100);
			int l_p2 = std::clamp(l + d * 2, 0, 100);
			int l_n  = std::clamp(l - d,	 0, 100);
			int l_n2 = std::clamp(l - d * 2, 0, 100);
			if (l<=ul && l>=d) {
				SetPanelCol(TriPanel1,	HslToCol(h, s, l_p), lbl.sprintf(_T("+L%u"), l_p - l));
				SetPanelCol(TriPanel2,	col, "0");
				SetPanelCol(TriPanel3,	HslToCol(h, s, l_n), lbl.sprintf(_T("-L%u"), l - l_n));
			}
			else if (l>ul) {
				SetPanelCol(TriPanel1,	col, "0");
				SetPanelCol(TriPanel2,	HslToCol(h, s, l_n),  lbl.sprintf(_T("-L%u"), l - l_n));
				SetPanelCol(TriPanel3,	HslToCol(h, s, l_n2), lbl.sprintf(_T("-L%u"), l - l_n2));
			}
			else if (l<d) {
				SetPanelCol(TriPanel1,	col, "0");
				SetPanelCol(TriPanel2,	HslToCol(h, s, l_p),  lbl.sprintf(_T("+L%u"), l_p - l));
				SetPanelCol(TriPanel3,	HslToCol(h, s, l_p2), lbl.sprintf(_T("+L%u"), l_p2 - l));
			}
		}
		break;
	default:	//H
		{
			int h_n = h - d;  if (h_n<0) h_n += 360;
			int h_p = (h + d)%360;
			SetPanelCol(TriPanel1,	HslToCol(h_n, s, l), lbl.sprintf(_T("-H%u"), d)); 
			SetPanelCol(TriPanel2,	col, "0");
			SetPanelCol(TriPanel3,	HslToCol(h_p, s, l), lbl.sprintf(_T("+H%u"), d));
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::SetTriColor(TColor col)
{
	UnicodeString ttyp = TriComboBox->Text;
	if		(SameText(ttyp, "Triad"))				SetTriColorCore(col, "H120");
	else if (SameText(ttyp, "Split Complementary")) SetTriColorCore(col, "H150");
	else if (SameText(ttyp, "Analogous"))			SetTriColorCore(col, "H30");
	else if (SameText(ttyp, "Tetrad"))				SetTriColorCore(col, "H90");
	else if (EndsText("(S20)", ttyp))				SetTriColorCore(col, "S20");
	else if (EndsText("(L20)", ttyp)) 				SetTriColorCore(col, "L20");
	else if (StartsText("Custom", ttyp))			SetTriColorCore(col, CustomScheme);
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::ClearRightPanel()
{
	ValListBox->Clear();
	SetPanelCol(ColPanel,  clBlack, "---");
	SetPanelCol(CmpPanel,  clDkGray);
	SetPanelCol(TriPanel1, TColor(RGB(92, 92, 92)), "---");
	SetPanelCol(TriPanel2, TColor(RGB(64, 64, 64)), "---");
	SetPanelCol(TriPanel3, TColor(RGB(48, 48, 48)), "---");
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::TabControl1Change(TObject *Sender)
{
	ClearRightPanel();
	FilterComboBoxClick(NULL);
}

//---------------------------------------------------------------------------
// Filtering
//---------------------------------------------------------------------------
int __fastcall Comp_Luminance(TStringList *List, int Index1, int Index2)
{
	TColor col1 = (TColor)(int)List->Objects[Index1];
	TColor col2 = (TColor)(int)List->Objects[Index2];
	int h1,s1,l1;
	RgbToHsl(col1, &h1, &s1, &l1);
	int h2,s2,l2;
	RgbToHsl(col2, &h2, &s2, &l2);
	return (l1==l2)? ((s2>s1)? 1 : -1) : ((l2>l1)? 1 : -1);
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::FilterComboBoxClick(TObject *Sender)
{
	TStringList *sp = GetCurList();
	UnicodeString ftyp = FilterComboBox->Text;
	UnicodeString ltyp = L_ComboBox->Text;
	std::unique_ptr<TStringList> flst(new TStringList());
	for (int i=0; i<sp->Count; i++) {
		TColor col = (TColor)(int)sp->Objects[i];
		int h,s,l;
		RgbToHsl(col, &h, &s, &l);
		bool match = SameText(ltyp, "Light")? (l>66) :
					SameText(ltyp, "Medium")? (l>33 && l<=66) :
					  SameText(ltyp, "Dark")? (l<=33) : true;
		if (!match) continue;
		match = SameText(ftyp, "All") || (SameText(ftyp, "Monochrome") && s==0);
		if (!match && s>0) {
			match = SameText(ftyp, "Red")	  ? (h>=330 || h<30) :
					SameText(ftyp, "Yellow")  ? (h>=30  && h<90) :
					SameText(ftyp, "Green")	  ? (h>=90  && h<150) :
					SameText(ftyp, "Cyan")	  ? (h>=150 && h<210) :
					SameText(ftyp, "Blue")	  ? (h>=210 && h<270) :
					SameText(ftyp, "Magenta") ? (h>=270 && h<330) : false;
		}
		if (match) flst->AddObject(sp->Strings[i], sp->Objects[i]);
	}

	if (!SameText(ftyp, "All")) flst->CustomSort(Comp_Luminance);

	ColorListBox->Items->Assign(flst.get());
	ClearRightPanel();
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::TriComboBoxClick(TObject *Sender)
{
	SetTriColor(ColPanel->Color);
	ColPanelClick(ColPanel);
}

//---------------------------------------------------------------------------
void __fastcall TVclColForm::ColorListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect,
	TOwnerDrawState State)
{
	TListBox *lp = (TListBox*)Control;
	TCanvas  *cv = lp->Canvas;
	cv->Font->Assign(lp->Font);
	cv->Brush->Color = State.Contains(odSelected)? clHighlight : clWindow;	
	cv->Font->Color  = State.Contains(odSelected)? clHighlightText : clWindowText;
	TRect rc = Rect;  rc.Right = rc.Right - 80;
	cv->FillRect(rc);

	int yp = Rect.Top + (Rect.Height() - cv->TextHeight("Q"))/2;
	cv->TextOut(Rect.Left + 2, yp, lp->Items->Strings[Index]);
	int col_i = (int)lp->Items->Objects[Index];
	cv->TextOut(Rect.Right - cv->TextWidth("0x00000000") - 88, yp,
					UnicodeString().sprintf(_T("0x%08x"), col_i));
	//Color
	rc = Rect;  rc.Left = rc.Right - 80;
	cv->Brush->Color = (TColor)col_i;
	cv->FillRect(rc);
	//Separator
	cv->Pen->Color = SelectWorB(cv->Brush->Color, 0.25);
	cv->Pen->Style = psSolid;
	cv->Pen->Width = 1;
	cv->MoveTo(rc.Left, Rect.Top);
	cv->LineTo(Rect.Right, Rect.Top);
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::ColorListBoxClick(TObject *Sender)
{
	TListBox *lp = (TListBox*)Sender;
	ValListBox->Clear();
	int idx = lp->ItemIndex;
	if (idx!=-1) {
		TColor col = (TColor)(int)lp->Items->Objects[idx];
		SetPanelCol(ColPanel, col, lp->Items->Strings[idx]);
		SetPanelCol(CmpPanel, ComplementaryCol(col));
		SetTriColor(col);
		ColPanelClick(ColPanel);
	}
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::ColPanelClick(TObject *Sender)
{
	TPanel *pp = (TPanel*)Sender;
	TColor col = pp->Color;
	int  col_i = (int)col;
	col = TColor(ColorToRGB(col));
	ValListBox->Clear();

	switch (pp->Tag) {
	case 0:
		if (!StartsStr("#", ColPanel->Caption)) ValListBox->Items->Add(ColPanel->Caption);
		if ((col_i & 0xff000000)!=0) {
			ValListBox->Items->Add(UnicodeString().sprintf(_T("0x%08x"), col_i));
		}
		break;
	case 1: ValListBox->Items->Add("<Complementary>"); break;
	case 2: ValListBox->Items->Add("1"); break;
	case 3: ValListBox->Items->Add("2"); break;
	case 4: ValListBox->Items->Add("3"); break;
	}

	//COLORREF
	int c = ColorToRGB(col);
	ValListBox->Items->Add(UnicodeString().sprintf(_T("0x%08x"), c));

	//RGB
	int r = GetRValue(c);
	int g = GetGValue(c);
	int b = GetBValue(c);
	ValListBox->Items->Add(UnicodeString().sprintf(_T("RGB(0x%02x,0x%02x,0x%02x)"), r,g,b));
	ValListBox->Items->Add(UnicodeString().sprintf(_T("RGB(%2u,%2u,%2u)"), r,g,b));

	//HTML Color
	ValListBox->Items->Add(UnicodeString().sprintf(_T("#%02x%02x%02x"), r,g,b));
	UnicodeString sR = IntToHex(r, 2).LowerCase();
	UnicodeString sG = IntToHex(g, 2).LowerCase();
	UnicodeString sB = IntToHex(b, 2).LowerCase();
	if (sR[1]==sR[2] && sG[1]==sG[2] && sB[1]==sB[2]) {
		ValListBox->Items->Add(UnicodeString().sprintf(_T("#%c%c%c"), sR[1], sG[1], sB[1]));
	}

	//HSL
	int h,s,l;
	RgbToHsl(col, &h, &s, &l);
	ValListBox->Items->Add(UnicodeString().sprintf(_T("H%u, S%u, L%u"), h,s,l));

	//HSV
	int hh,ss,vv;
	RgbToHsv(col, &hh, &ss, &vv);
	ValListBox->Items->Add(UnicodeString().sprintf(_T("H%u, S%u, V%u"), hh,ss,vv));

	//Find same color
	if (pp->Tag==0) {
		for (int i=0; i<VclColList->Count; i++) {
			if (!SameText(VclColList->Strings[i], ColPanel->Caption)
				&& col==(TColor)(int)VclColList->Objects[i])
			{
				ValListBox->Items->Add("= " + VclColList->Strings[i]);
			}
		}
		for (int i=0; i<SysColList->Count; i++) {
			if (!SameText(SysColList->Strings[i], ColPanel->Caption)
				&& col==TColor(ColorToRGB((TColor)(int)SysColList->Objects[i])))
			{
				ValListBox->Items->Add("= " + SysColList->Strings[i] + "*");
			}
		}
	}
}
//---------------------------------------------------------------------------
// Value List
//---------------------------------------------------------------------------
void __fastcall TVclColForm::ValListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect,
	TOwnerDrawState State)
{
	TListBox *lp = (TListBox*)Control;
	TCanvas  *cv = lp->Canvas;
	UnicodeString lbuf = lp->Items->Strings[Index];
	bool is_hdr = (lbuf.Length()==1 || StartsStr("<", lbuf));
	cv->Brush->Color = is_hdr? clBtnFace : State.Contains(odSelected)? clHighlight : clWindow;
	cv->FillRect(Rect);

	cv->Font->Assign(lp->Font);
	cv->Font->Color = is_hdr? clBtnText : State.Contains(odSelected)? clHighlightText : clWindowText;
	int xp = Rect.Left + 2;
	int yp = Rect.Top + (Rect.Height() - cv->TextHeight("Q"))/2;
	if (lbuf.Length()==1) {
		int x6 = lp->ClientWidth/6;
		switch (lbuf[1]) {
		case '1': xp = x6 * 1; break;
		case '2': xp = x6 * 3; break;
		case '3': xp = x6 * 5; break;
		}
		xp -= cv->TextWidth("Бе")/2;
		cv->TextOut(xp, Rect.Top, "Бе");
	}
	else {
		if (StartsStr("<", lbuf)) xp = (lp->ClientWidth - cv->TextWidth(lbuf))/2;
		cv->TextOut(xp, yp, lbuf);
	}

	if (StartsStr("0x", lbuf) && lbuf.Length()==10) {
		xp = Rect.Right - cv->TextWidth("COLORREF") - 4;
		cv->Font->Color = AdjustColor(cv->Font->Color, 128);
		cv->TextOut(xp, yp, SameStr(lbuf.SubString(3, 2), "00")? "COLORREF" : "int");
	}
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::ValListBoxDblClick(TObject *Sender)
{
	CopyValItemClick(NULL);
}
//---------------------------------------------------------------------------
// Spuit Tool
//---------------------------------------------------------------------------
void __fastcall TVclColForm::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
	int X, int Y)
{
	if (!Capturing && Button == mbLeft) {
		Screen->Cursor = crSpuit;
		Image1->Visible = false;
		Capturing = true;
		LastColor = Graphics::clNone;
	}
}
//---------------------------------------------------------------------------
void __fastcall TVclColForm::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
	int X, int Y)
{
	if (Capturing && Button == mbLeft) {
		Capturing = false;
		Screen->Cursor = crDefault;
		Image1->Visible = true;
	}
}
//---------------------------------------------------------------------------
// Copy this value
//---------------------------------------------------------------------------
void __fastcall TVclColForm::CopyValItemClick(TObject *Sender)
{
	int idx = ValListBox->ItemIndex;
	if (idx!=-1) {
		UnicodeString s = ValListBox->Items->Strings[idx];
		if (s.Length()>1 && !StartsStr("<", s)) {
			Screen->Cursor = crHourGlass;
			if (StartsStr("=", s)) {
				s = ReplaceStr(s, "=", EmptyStr);
				s = ReplaceStr(s, "*", EmptyStr);
				s = Trim(s);
			}
			Clipboard()->AsText = s;
			Sleep(200);
			Screen->Cursor = crDefault;
		}
	}
}
//---------------------------------------------------------------------------
// Copy All
//---------------------------------------------------------------------------
void __fastcall TVclColForm::CopyAllItemClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;
	Clipboard()->AsText = ValListBox->Items->Text;
	Sleep(200);
	Screen->Cursor = crDefault;
}

//---------------------------------------------------------------------------
// Select List Font
//---------------------------------------------------------------------------
void __fastcall TVclColForm::SelFontItemClick(TObject *Sender)
{
	FontDialog1->Font->Assign(ColorListBox->Font);
	if (FontDialog1->Execute()) {
		ListFont->Assign(FontDialog1->Font);
		SetListBoxFont(ColorListBox);
		SetListBoxFont(ValListBox);
	}
}
//---------------------------------------------------------------------------
//Custom Scheme Setting
//---------------------------------------------------------------------------
void __fastcall TVclColForm::CustomSetItemClick(TObject *Sender)
{
	CustomDlg->Left   = TriComboBox->ClientToScreen(Point(0, 0)).x;
	CustomDlg->Top    = TriComboBox->ClientToScreen(Point(0, TriComboBox->Height)).y + 8;
	CustomDlg->LastH  = IniFile->ReadInteger("Option", "LastH", 0);
	CustomDlg->LastS  = IniFile->ReadInteger("Option", "LastS", 0);
	CustomDlg->LastL  = IniFile->ReadInteger("Option", "LastL", 0);
	CustomDlg->Scheme = CustomScheme;
	CustomDlg->ShowModal();
	CustomScheme = CustomDlg->Scheme;
	IniFile->WriteInteger("Option", "LastH", CustomDlg->LastH);
	IniFile->WriteInteger("Option", "LastS", CustomDlg->LastS);
	IniFile->WriteInteger("Option", "LastL", CustomDlg->LastL);

	int idx = TriComboBox->ItemIndex;
	TriComboBox->Items->Strings[TriComboBox->Items->Count - 1] = "Custom Scheme (" + CustomScheme + ")";
	TriComboBox->ItemIndex = idx;
	if (TriComboBox->ItemIndex == TriComboBox->Items->Count - 1) {
		SetTriColor(ColPanel->Color);
		ColPanelClick(ColPanel);
	}
}
//---------------------------------------------------------------------------
