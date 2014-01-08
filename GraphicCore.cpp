//---------------------------------------------------------------------------

#include <Graphics.hpp>
#pragma hdrstop

#include "GraphicCore.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TColor CGraphicCore::getProperPixel(Graphics::TBitmap *bmp,int x,int y)
{
   /*
   * Jedna z wazniejszych procek,ktora zwraca odpowiedni pixel to przetworzenia.
   * odpowiedni to znaczy jezeli pixel wystaje dwa pixele poza dostepno szerokosc na lewo
   * to pobierz pixel o pozycji x rownej (bmp.width - 2)
   */
	if(x < 0 || x > (bmp->Width - 1))
     	x = abs(bmp->Width - abs(x)); 
	
	if(y < 0 || y > (bmp->Height - 1))
		y = abs(bmp->Height - abs(y));

  return bmp->Canvas->Pixels[x][y];
}
bool CGraphicCore::isProgEnable(double T)
{
	return ( T > 0 );
}
void CGraphicCore::setColor(int &r,int &g,int &b,TColor color)
{
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);	 	
}
