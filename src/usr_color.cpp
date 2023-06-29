//----------------------------------------------------------------------//
// カラー関連関数														//
//																		//
//----------------------------------------------------------------------//
#ifndef USE_COMMON_PCH
#include <vcl.h>
#include <algorithm>
#pragma hdrstop
#endif

#include "usr_color.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//輝度を取得(0～1.0)
//---------------------------------------------------------------------------
double GetLuminance(TColor col)
{
	int c = ColorToRGB(col);
	return ((GetRValue(c)*0.3 + GetGValue(c)*0.59 + GetBValue(c)*0.11) / 255.0);
}

//---------------------------------------------------------------------------
//カラーに倍率をかける
//---------------------------------------------------------------------------
TColor RatioCol(TColor col, float rt)
{
	if (rt>1.0) rt = 1.0; else if (rt<0.0) rt = 0.0;
	int c = ColorToRGB(col);
	int r = GetRValue(c) * rt;
	int g = GetGValue(c) * rt;
	int b = GetBValue(c) * rt;
	return TColor(RGB(r, g, b));
}
//---------------------------------------------------------------------------
TColor RatioCol(TColor col, double rr, double rg, double rb)
{
	if (col==Graphics::clNone) col = clBlack;
	int c = ColorToRGB(col);
	int r = GetRValue(c) * rr;
	int g = GetGValue(c) * rg;
	int b = GetBValue(c) * rb;
	return TColor(RGB(r, g, b));
}

//---------------------------------------------------------------------------
//補色を取得
//---------------------------------------------------------------------------
TColor ComplementaryCol(TColor col)
{
	int c = ColorToRGB(col);
	int r = GetRValue(c);
	int g = GetGValue(c);
	int b = GetBValue(c);
	int m = std::max(std::max(r, g), b) + std::min(std::min(r, g), b);
	return TColor(RGB(m - r, m - g, m - b));
}

//---------------------------------------------------------------------------
//輝度に基づいてグレースケール化
//---------------------------------------------------------------------------
TColor GrayCol(TColor col)
{
	if (col==Graphics::clNone) col = clBlack;
	BYTE v = (BYTE)(GetLuminance(col) * 255);
	return TColor(RGB(v, v, v));
}

//---------------------------------------------------------------------------
TColor GrayCol(TColor col, double gv)
{
	if (col==Graphics::clNone) col = clBlack;

	int c = ColorToRGB(col);
	int r = GetRValue(c);
	int g = GetGValue(c);
	int b = GetBValue(c);

	if (gv>1.0) gv = 1.0;
	if (gv<0.0) gv = 0.0;

	r -= ((r - 128) * gv);
	g -= ((g - 128) * gv);
	b -= ((b - 128) * gv);

	return TColor(RGB(r,g,b));
}

//---------------------------------------------------------------------------
//RGB→HSL 変換
//---------------------------------------------------------------------------
void RgbToHsl(TColor col, int *h, int *s, int *l)
{
	int cref = ColorToRGB(col);
	float r = GetRValue(cref)/255.0;
	float g = GetGValue(cref)/255.0;
	float b = GetBValue(cref)/255.0;

	float maxv = std::max(r, std::max(g, b));
	float minv = std::min(r, std::min(g, b));
	float h_f, s_f;
	float l_f = (maxv + minv)/2.0;

	if (maxv==minv) {
		h_f = s_f = 0.0;
	}
	else {
		float d = maxv - minv;
		if		(maxv==r) h_f = (g - b)/d;
		else if (maxv==g) h_f = (b - r)/d + 2.0;
		else			  h_f = (r - g)/d + 4.0;
		h_f *= 60.0;
		if (h_f<0.0) h_f += 360.0;

		s_f = ((l_f<0.5)? d/(maxv + minv) : d/(2.0 - maxv - minv)) * 100.0;
	}

	l_f *= 100.0;

	*h = (int)(h_f + 0.5);
	*s = (int)(s_f + 0.5);
	*l = (int)(l_f + 0.5);
}
//---------------------------------------------------------------------------
//RGB→HSV 変換
//---------------------------------------------------------------------------
void RgbToHsv(TColor col, int *h, int *s, int *v)
{
	int cref = ColorToRGB(col);
	float r = GetRValue(cref)/255.0;
	float g = GetGValue(cref)/255.0;
	float b = GetBValue(cref)/255.0;

	float maxv = std::max(r, std::max(g, b));
	float minv = std::min(r, std::min(g, b));
	float h_f, s_f;
	float v_f = maxv * 100;

	if (maxv==minv) {
		h_f = s_f = 0.0;
	}
	else {
		float d = maxv - minv;
		if		(maxv==r) h_f = (g - b)/d;
		else if (maxv==g) h_f = (b - r)/d + 2.0;
		else			  h_f = (r - g)/d + 4.0;
		h_f *= 60.0;
		if (h_f<0.0) h_f += 360.0;

		s_f = d/maxv * 100.0;
	}

	*h = (int)(h_f + 0.5);
	*s = (int)(s_f + 0.5);
	*v = (int)(v_f + 0.5);
}

//---------------------------------------------------------------------------
//HSL→RGB 変換
//---------------------------------------------------------------------------
TColor HslToCol(int h, int s, int l)
{
	float maxv, minv;
	if (l<50) {
		maxv = 2.55 * (l + l * (s/100.0));
		minv = 2.55 * (l - l * (s/100.0));
	}
	else {
		maxv = 2.55 * (l + (100 - l) * (s/100.0));
		minv = 2.55 * (l - (100 - l) * (s/100.0));
	}
	
	float fR, fG, fB;
	switch (h/60) {
	case 0: 
		fR = maxv;
		fG = minv + (h/60.0) * (maxv - minv);
		fB = minv;
		break;
	case 1:
		fR = minv + ((120 - h) / 60.0) * (maxv - minv);
		fG = maxv;
		fB = minv;
		break;
	case 2:
		fR = minv;
		fG = maxv;
		fB = minv + ((h - 120) / 60.0) * (maxv - minv);
		break;
	case 3:
		fR = minv;
		fG = minv + ((240 - h) / 60.0) * (maxv - minv);
		fB = maxv;
		break;
	case 4:
		fR = minv + ((h - 240) / 60.0) * (maxv - minv);
		fG = minv;
		fB = maxv;
		break;
	case 5:
		fR = maxv;
		fG = minv;
		fB = minv + ((360 - h) / 60.0) * (maxv - minv);
		break;
	}

	int r = (int)(fR + 0.5);
	int g = (int)(fG + 0.5);
	int b = (int)(fB + 0.5);
	return TColor(RGB(r, g, b));
}

//---------------------------------------------------------------------------
//背景の輝度から白または黒を選択・加減
//---------------------------------------------------------------------------
TColor SelectWorB(
	TColor col,		//背景色
	float  rt)		//加減指定  (default = 1.0)
{
	double v = GetLuminance(col);
	if (rt<1.0)
		return (v>0.5)? RatioCol(clWhite, 1.0 - rt) : RatioCol(clWhite, rt);
	else
		return (v>0.5)? clBlack : clWhite;
}
//---------------------------------------------------------------------------
//輝度に基づいて明暗を加減
//---------------------------------------------------------------------------
TColor AdjustColor(
	TColor col,		//元の色
	int adj)		//加減値	0～255
{
	if (GetLuminance(col)>0.5) adj = -adj;

	int cref = ColorToRGB(col);
	int r = GetRValue(cref);
	int g = GetGValue(cref);
	int b = GetBValue(cref);

	r += adj;  if (r>255) r = 255; else if (r<0) r = 0;
	g += adj;  if (g>255) g = 255; else if (g<0) g = 0;
	b += adj;  if (b>255) b = 255; else if (b<0) b = 0;

	return TColor(RGB(r, g, b));
}
//---------------------------------------------------------------------------
TColor AdjustRGB(
	TColor col,		//元の色
	int adj_r,		//R加減値	0～255
	int adj_g,		//G加減値	0～255
	int adj_b)		//B加減値	0～255
{
	bool is_br = (GetLuminance(col)>0.5);

	if (is_br) {
		adj_r = -adj_r;
		adj_g = -adj_g;
		adj_b = -adj_b;
	}

	int cref = ColorToRGB(col);
	int r = GetRValue(cref);
	int g = GetGValue(cref);
	int b = GetBValue(cref);

	r += adj_r;  if (r>255) r = 255; else if (r<0) r = 0;
	g += adj_g;  if (g>255) g = 255; else if (g<0) g = 0;
	b += adj_b;  if (b>255) b = 255; else if (b<0) b = 0;

	if (is_br) {
		int m = std::max(std::max(r, g), b) + std::min(std::min(r, g), b);
		r = m - r;
		g = m - g;
		b = m - b;
	}

	return TColor(RGB(r, g, b));
}

//---------------------------------------------------------------------------
//文字列からカラーを設定
//---------------------------------------------------------------------------
void str_to_Color(TColor &col, UnicodeString s)
{
	TColor c = (TColor)s.ToIntDef(Graphics::clNone);
	if (c!=Graphics::clNone) col = c;
}

//---------------------------------------------------------------------------
//レインボーカラー
//---------------------------------------------------------------------------
TColor RainbowCol(double pv)
{
	int v  = (int)(1279*pv);
	int cv = v%256;
	int n  = v/256;
	int r, g, b;

	switch (n) {
	case 0: r = 255;		g = cv; 		b = 0;			break;
	case 1: r = 255 - cv;	g = 255;		b = 0;			break;
	case 2: r = 0;			g = 255;		b = cv; 		break;
	case 3: r = 0;			g = 255 - cv;	b = 255;		break;
	case 4: r = cv;			g = 0;			b = 255;		break;
	case 5: r = 255;		g = 0;			b = 255 - cv;	break;
	}

	return TColor(RGB(r, g, b));
}
//---------------------------------------------------------------------------
TColor RainbowColW(double pv)
{
	int v  = (int)(1535*pv);
	int cv = v%256;
	int n  = v/256;
	int r, g, b;

	switch (n) {
	case 0: r = 255;		g = cv; 		b = 0;			break;
	case 1: r = 255 - cv;	g = 255;		b = 0;			break;
	case 2: r = 0;			g = 255;		b = cv; 		break;
	case 3: r = 0;			g = 255 - cv;	b = 255;		break;
	case 4: r = cv;			g = 0;			b = 255;		break;
	case 5: r = 255;		g = 0;			b = 255 - cv;	break;
	}

	return TColor(RGB(r, g, b));
}

//---------------------------------------------------------------------------
TColor WhiteCol(TColor c, int wv)
{
	if (c==Graphics::clNone) c = clBlack;

	int r = GetRValue(c);
	int g = GetGValue(c);
	int b = GetBValue(c);

	if (wv>=0) {
		r += (255 - r)*wv/255;
		g += (255 - g)*wv/255;
		b += (255 - b)*wv/255;
	}
	else {
		r = r*(255 + wv)/255;
		g = g*(255 + wv)/255;
		b = b*(255 + wv)/255;
	}
	if (r>255) r = 255;
	if (g>255) g = 255;
	if (b>255) b = 255;

	return TColor(RGB(r,g,b));
}

//---------------------------------------------------------------------------
TColor MonochromeCol(TColor c, double rv)
{
	if (c==Graphics::clNone) c = clBlack;

	int r  = GetRValue(c);
	int g  = GetGValue(c);
	int b  = GetBValue(c);
	BYTE v = (BYTE)((r*0.3 + g*0.59 + b*0.11) * rv) ; // 明るさ
	return TColor(RGB(v,v,v));
}

//---------------------------------------------------------------------------
//グラデーションカラー (2色)
//---------------------------------------------------------------------------
TColor Gradation2Col(double pv, TColor c0, TColor c1)
{
	if (c0==Graphics::clNone) c0 = clBlack;
	if (c1==Graphics::clNone) c1 = clBlack;

	int r0 = GetRValue(c0);
	int g0 = GetGValue(c0);
	int b0 = GetBValue(c0);
	int r1 = GetRValue(c1);
	int g1 = GetGValue(c1);
	int b1 = GetBValue(c1);

	int r,g,b;
	if (pv<0.5) {
		pv *= 2;
		r = std::min((int)(r0*(1.0 - pv) + r1*pv), 255);
		g = std::min((int)(g0*(1.0 - pv) + g1*pv), 255);
		b = std::min((int)(b0*(1.0 - pv) + b1*pv), 255);
	}
	else {
		pv -= 0.5;
		pv *= 2;
		r = std::min((int)(r1*(1.0 - pv) + r0*pv), 255);
		g = std::min((int)(g1*(1.0 - pv) + g0*pv), 255);
		b = std::min((int)(b1*(1.0 - pv) + b0*pv), 255);
	}
	return TColor(RGB(r,g,b));
}

//---------------------------------------------------------------------------
//天空カラー
//---------------------------------------------------------------------------
TColor SkyCol(double pv)
{
	int v = (int)(1535*pv);
	if (v<256) return TColor(RGB(v,0,0));

	v -= 256;

	int r  = 255;
	int g  = 0;
	int b  = 0;
	int cr = 1;
	int cg = 0;
	int cb = 0;

	int n  = v/256;
	int cv = v%256;

	int s_d = (255 + (255 - cv))*cv/2;
	int s_u = cv*cv/2;
	int s_f = 255*255;
	int s_h = s_f/2;

	if (n<1) {
		r += 255*cv;  g += s_u;
		cr += cv;  cg += cv;
	}
	else {
		r += s_f;  g += s_h;
		cr += 255;  cg += 255;
		if (n<2) {
			r += s_d;  g += 255*cv;
			cr += cv;  cg += cv;
		}
		else {
			r += s_h;  g += s_f;
			cr += 255;  cg += 255;
			if (n<3) {
				g += 255*cv;  b += s_u;
				cg += cv;  cb += cv;
			}
			else {
				g += s_f;  b += s_h;
				cg += 255;  cb += 255;
				if (n<4) {
					g += s_d;  b += 255*cv;
					cg += cv;  cb += cv;
				}
				else {
					g += s_h;  b += s_f;
					cg += 255;  cb += 255;
					if (n<5) {
						r += s_u;  b += 255*cv;
						cr += cv;  cb += cv;
					}
					else {
						r += s_h;  b += s_f;
						cr += 255;  cb += 255;
					}
				}
			}
		}
	}

	if (cr>0) r /= cr;
	if (cg>0) g /= cg;
	if (cb>0) b /= cb;

	return TColor(RGB(r,g,b));
}
//---------------------------------------------------------------------------

