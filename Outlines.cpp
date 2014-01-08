//---------------------------------------------------------------------------

#include <vector>
#include <Graphics.hpp>
#include <cmath>
#include "Convert.h"
#pragma hdrstop

using namespace std;

#include "Outlines.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
void COutlines::discretGradient(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez)
{
	for(int y = 1; y < bmp->Height -1;++y){
	 for(int x = 1; x < bmp->Width - 1;++x){
		bmpRez->Canvas->Pixels[x][y]
		= abs(bmp->Canvas->Pixels[x][y] - bmp->Canvas->Pixels[x+1][y+1]) +
		  abs(bmp->Canvas->Pixels[x+1][y] - bmp->Canvas->Pixels[x][y+1]);
	 }
	}
}
void COutlines::robertsGradient(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,double T,TColor krawedz,TColor tlo)
{
	for(int y = 1; y < bmp->Height -1;++y){
	 for(int x = 1; x < bmp->Width - 1;++x){
		TColor color  =
		abs(bmp->Canvas->Pixels[x][y] - bmp->Canvas->Pixels[x+1][y+1]) +
		abs(bmp->Canvas->Pixels[x+1][y] - bmp->Canvas->Pixels[x][y+1]);
		Cyuv yuv = Convert::rgb2yuv(color);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (isProgEnable(T)) {
			Cyuv yuv = Convert::rgb2yuv(TColor(RGB(r,g,b)));
			if (yuv.y >= T ) {//kolor dla krawedzi
			  setColor(r,g,b,krawedz);
			}else {
			  setColor(r,g,b,tlo);
			}
		}

		bmpRez->Canvas->Pixels[x][y] = RGB(r,g,b);
	 }
	}
}
void COutlines::robertsGradientYuv(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,double T,TColor krawedz,TColor tlo,bool b_krawedz,bool b_tlo)
{
	Cyuv yuv1,yuv2,yuv3,yuv4,yuvREZ;
	int r,g,b;		
	for(int y = 1; y < bmp->Height -1;++y){
	 for(int x = 1; x < bmp->Width - 1;++x){
		yuvREZ = Convert::rgb2yuv(bmp->Canvas->Pixels[x][y]);
		yuv1   = Convert::rgb2yuv(bmp->Canvas->Pixels[x][y]);
		yuv2   = Convert::rgb2yuv(bmp->Canvas->Pixels[x+1][y]);
		yuv3   = Convert::rgb2yuv(bmp->Canvas->Pixels[x][y+1]);
		yuv4   = Convert::rgb2yuv(bmp->Canvas->Pixels[x+1][y+1]);
		yuvREZ.y = abs(yuv1.y - yuv4.y) + abs(yuv2.y - yuv3.y);
		//yuvREZ.y = abs(yuv1.y - yuv3.y) + abs(yuv2.y - yuv4.y);
		//yuvREZ.y = abs(yuv1.y - yuv2.y) + abs(yuv3.y - yuv4.y);
		if (isProgEnable(T)) {
			if (yuvREZ.y >= T ) {//kolor dla krawedzi
              if(b_krawedz){
				setColor(r,g,b,krawedz);
				}else{
                 r = yuvREZ.y; g = yuvREZ.y; b = yuvREZ.y;
				}

			}else {
			   if(b_tlo){
				setColor(r,g,b,tlo);
				}else{
				 setColor(r,g,b,bmp->Canvas->Pixels[x][y]);
				}
			}
		}
		else
		{
			setColor(r,g,b,RGB(yuvREZ.y,yuvREZ.y,yuvREZ.y));
			r = min(255, max(0, r));
			g = min(255, max(0, g));
			b = min(255, max(0, b));
		}
		bmpRez->Canvas->Pixels[x][y] = TColor(RGB(r,g,b));

	 }
	}
}
void COutlines::setProg(int &rgb,int T,TColor color,char c)
{
	if( rgb < T )
	{
		switch(c)
		{
			case 'r':
				rgb = GetRValue(color);
				break;

			case 'g':
            	rgb = GetGValue(color);
				break;

			case 'b':
            	rgb = GetBValue(color);
				break;
		}
     }
}
void COutlines::setWhite(int &rgb,int T)
{
	if( rgb < T )
		rgb = 0;
	else
    	rgb = 255;
}
