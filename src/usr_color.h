//----------------------------------------------------------------------//
// ÉJÉâÅ[ä÷òAä÷êî														//
//																		//
//----------------------------------------------------------------------//
#ifndef UsrColorH
#define UsrColorH

//---------------------------------------------------------------------------
double GetLuminance(TColor col);

TColor RatioCol(TColor col, float rt);
TColor RatioCol(TColor col, double rr, double rg, double rb);

TColor ComplementaryCol(TColor col);

TColor GrayCol(TColor col);
TColor GrayCol(TColor col, double gv);

void RgbToHsl(TColor col, int *h, int *s, int *l);
void RgbToHsv(TColor col, int *h, int *s, int *v);
TColor HslToCol(int h, int s, int l);

TColor SelectWorB(TColor col, float rt = 1.0);
TColor AdjustColor(TColor col, int adj);
TColor AdjustRGB(TColor col, int adj_r, int adj_g, int adj_b);
void str_to_Color(TColor &col, UnicodeString s);

TColor RainbowCol(double pv);
TColor RainbowColW(double pv);

TColor WhiteCol(TColor c, int wv);
TColor MonochromeCol(TColor c, double rv);
TColor Gradation2Col(double pv, TColor c0, TColor c1);
TColor SkyCol(double pv);

//---------------------------------------------------------------------------
#endif
