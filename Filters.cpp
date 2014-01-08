//---------------------------------------------------------------------------

#include <cmath>
#include <Graphics.hpp>
#include <vector>
#include <numeric>
#include <algorithm>
#include <vcl.h>
#pragma hdrstop

using namespace std;

#include "Filters.h"
#include "Convert.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
void CFilters::windowFilter(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,vector<double> window,double T,int N,bool b_N)
{

	int windowSize = sqrt((double)window.size());
	TColor tmpColor;
	int totalR = 0;
	int totalG = 0;
	int totalB = 0;
	int index = 0;
	int r,g,b;
	int suma;

	
	//glowny loop dla siatki pixeli wyznaczajacy tzw pixel wyrozniony
	for(int x = 0;x < bmp->Width;++x)
	{
	  for(int y = 0;y < bmp->Height;++y)
	  {
		//loopy odpowiedzialne za operowanie w okolo pixela wyroznionego
		for(int j = -(windowSize/2); j < windowSize - 1; ++j)
		{
			for(int i = -(windowSize/2); i < windowSize - 1;++i)
			{
				//glowne miejsce zamieszania;]
				//pobierz odpowiedni pixel
				tmpColor = getProperPixel(bmp, x+i , y+j );
				r = GetRValue(tmpColor) * window[index];
				g = GetGValue(tmpColor) * window[index];
				b = GetBValue(tmpColor) * window[index];

				totalR += r;
				totalG += g;
				totalB += b;								
				index++;       
			}
		}

		suma = accumulate(window.begin(),window.end(),0);
		if(suma == 0)
        	suma = 1;
		if(b_N)
        	suma = N;
		//totalColor = (TColor)totalColor / suma;
		totalR /= suma;
		totalG /= suma;
		totalB /= suma;

		totalR = min(255, max(0, totalR));
		totalG = min(255, max(0, totalG));
		totalB = min(255, max(0, totalB));

		//wrzuc spowrotem do tablicy pixeli
		bmpRez->Canvas->Pixels[x][y] = RGB(totalR,totalG,totalB);		
		//zeruj index pozycji w oknie wspolczynnikow
		index = 0;
		//zeruj wartosci
		totalR = 0;
		totalG = 0;
		totalB = 0;
	  }
	}

}
void CFilters::medianFilter(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,int windowSize)
{

	vector<int> pixels;
	TColor color;
	//glowny loop dla siatki pixeli wyznaczajacy tzw pixel wyrozniony
	for(int x = 0;x < bmp->Width;++x)
	{
	  for(int y = 0;y < bmp->Height;++y)
	  {
		//loopy odpowiedzialne za operowanie na oknie filtrujacym
		for(int j = -(windowSize/2); j < windowSize - 1; ++j)
		{
			for(int i = -(windowSize/2); i < windowSize - 1;++i)
			{
				  color = getProperPixel(bmp,x+i,y+j);
				  pixels.push_back(color);
			}
		}

		sort(pixels.begin(),pixels.end());
		bmpRez->Canvas->Pixels[x][y] = (TColor)pixels[pixels.size()/2];
		pixels.clear();
	  }
	}

}
void CFilters::windowNine(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,double T,TColor krawedz,TColor tlo)
{
	int windowSize = 3;
	TColor tmpColor;
	int totalR = 0;
	int totalG = 0;
	int totalB = 0;
	int index = 0;
	int r,g,b;
	int suma;
	vector<double> window(9,-1);
	window[4] = 8;
	

	//glowny loop dla siatki pixeli wyznaczajacy tzw pixel wyrozniony
	for(int x = 0;x < bmp->Width;++x)
	{
	  for(int y = 0;y < bmp->Height;++y)
	  {
		//loopy odpowiedzialne za smiganie w okolo pixela wyroznionego
		for(int j = -(windowSize/2); j < windowSize - 1; ++j)
		{
			for(int i = -(windowSize/2); i < windowSize - 1;++i)
			{
				//glowne miejsce zamieszania;]
				//pobierz odpowiedni pixel
				tmpColor = getProperPixel(bmp, x+i , y+j );
				r = GetRValue(tmpColor) * window[index];
				g = GetGValue(tmpColor) * window[index];
				b = GetBValue(tmpColor) * window[index];

				totalR += r;
				totalG += g;
				totalB += b;								
				index++;       
			}
		}

		suma = accumulate(window.begin(),window.end(),0);
		if(suma == 0)
        	suma = 1;

		totalR /= suma;
		totalG /= suma;
		totalB /= suma;				

		if (isProgEnable(T)) {
			Cyuv yuv = Convert::rgb2yuv(TColor(RGB(totalR,totalG,totalB)));
			if (yuv.y >= T ) {//kolor dla krawedzi
			  setColor(totalR,totalG,totalB,krawedz);
			}else {
			  setColor(totalR,totalG,totalB,tlo);
			}
		}	
		//wrzuc spowrotem do tablicy pixeli
        bmpRez->Canvas->Pixels[x][y] = (TColor)RGB(totalR,totalG,totalB);
		//zeruj index pozycji w oknie wspolczynnikow
		index = 0;
		//zeruj wartosci
		totalR = 0;
		totalG = 0;
		totalB = 0;
	  }
	}

}
int CFilters::max(int a,int b)
{
	if(a > b)
		return a;
	else
		return b;
}
int CFilters::min(int a,int b)
{
	if(a < b)
		return a;
	else
		return b;
}
void CFilters::TESTwindowFilter(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,vector<int> window,double T,int N,bool b_N)
{
	Graphics::TBitmap *bmpTmp = new Graphics::TBitmap;
	bmpTmp->SetSize(bmp->Width,bmp->Height);
	bmpTmp->IgnorePalette = true;
	bmpRez->IgnorePalette = true;
	int windowSize = 3;
	TColor tmpColor;
	static int totalR = 0;
	static 	int totalG = 0;
	static 	int totalB = 0;
	static 	int window_value;
	static 	int index  = 0;
	static 	int r,g,b;


	
	//glowny loop dla siatki pixeli wyznaczajacy tzw pixel wyrozniony
	for(int x = 0;x < bmp->Width - 1;++x)
	{
	  for(int y = 0;y < bmp->Height - 1;++y)
	  {
		//loopy odpowiedzialne za smiganie w okolo pixela wyroznionego
		for(int j = -(windowSize/2); j < windowSize - 1; ++j)
		{
			for(int i = -(windowSize/2); i < windowSize - 1;++i)
			{
				//glowne miejsce zamieszania;]
				//pobierz odpowiedni pixel
				tmpColor = getProperPixel(bmp, x+i , y+j );
				window_value = window[index];
				r = GetRValue(tmpColor) * window_value;
				g = GetGValue(tmpColor) * window_value;
				b = GetBValue(tmpColor) * window_value;

				totalR += r;
				totalG += g;
				totalB += b;								
				index++;       
			}
		}

		int suma = accumulate(window.begin(),window.end(),0);
		if(suma == 0)
        	suma = 1;

		totalR /= suma;
		totalG /= suma;
		totalB /= suma;				

		//wrzuc spowrotem do tablicy pixeli
		bmpTmp->Canvas->Pixels[x][y] = RGB(totalR,totalG,totalB);		
		//zeruj index pozycji w oknie wspolczynnikow
		index = 0;
		//zeruj wartosci
		totalR = 0;
		totalG = 0;
		totalB = 0;
	  }
	}
	bmpRez->Canvas->Draw(0,0,bmpTmp);
}
