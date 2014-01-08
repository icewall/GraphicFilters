//---------------------------------------------------------------------------
#include <Graphics.hpp>
#pragma hdrstop

#include "Convert.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TColor Convert::yuv2rgb( char y,  char u,  char v)
{
	unsigned char r = (y+(1.403*v));
	unsigned char g = (y-(0.344*u)-(0.714*v));
	unsigned char b = (y+(1.770*u));
	return (TColor)RGB(r,g,b);
}
Cyuv Convert::rgb2yuv( char r, char g, char b)
{
	Cyuv yuv;
	yuv.y  = (0.299 * r + 0.587 * g + 0.114 * b);
	yuv.u  = ((b - yuv.y)*0.565);
	yuv.v  = ((r - yuv.y)*0.713);       
	return yuv;
}
TColor Convert::yuv2rgb(Cyuv yuv)
{
	unsigned char r = (yuv.y+(1.403*yuv.v));
	unsigned char g = (yuv.y-(0.344*yuv.u)-(0.714*yuv.v));
	unsigned char b = (yuv.y+(1.770*yuv.u));
	return (TColor)RGB(r,g,b);
}
Cyuv Convert::rgb2yuv(TColor rgb)
{
	Cyuv yuv;
	yuv.y  = (0.299 * GetRValue(rgb) + 0.587 * GetGValue(rgb) + 0.114 * GetBValue(rgb));
	yuv.u  = ((GetBValue(rgb) - yuv.y)*0.565);
	yuv.v  = ((GetRValue(rgb) - yuv.y)*0.713);       
	return yuv;
}
Cyuv Convert::Prgb2yuv(int r,int g, int b)
{
	Cyuv yuv ;
        
	yuv.y = (int)(0.299 * r + 0.587 * g + 0.114 * b);
	yuv.u = (int)((b - yuv.y) * 0.492f);
	yuv.v = (int)((r - yuv.y) * 0.877f);
        
	return yuv;
}
    
TColor Convert::Pyuv2rgb(int y, int u, int v)
{
	int r,g,b;
        
	r = (int)(1.164*(y - 16) + 1.596*(v - 128));
	g = (int)(1.164*(y - 16) - 0.813*(v - 128) - 0.391*(u - 128));
	b = (int)(1.164*(y - 16) + 2.018*(u - 128));
        
	return TColor(RGB(r,g,b));
}
