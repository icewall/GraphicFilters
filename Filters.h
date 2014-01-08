//---------------------------------------------------------------------------

#ifndef FiltersH
#define FiltersH
#include "GraphicCore.h"
//---------------------------------------------------------------------------
class CFilters : public CGraphicCore
{
	public:

	static void windowFilter(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,vector<double> window,double T,int N,bool b_N);
	static void medianFilter(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,int windowSize);
	static void windowNine(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,double T,TColor krawedz,TColor tlo);
	static int max(int a,int b);
	static int min(int a,int b);
	//tests
	
	static void TESTwindowFilter(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,vector<int> window,double T,int N,bool b_N);
	
};
#endif
