//---------------------------------------------------------------------------

#ifndef OutlinesH
#define OutlinesH
#include "GraphicCore.h"
//---------------------------------------------------------------------------

class COutlines : public CGraphicCore
{
	public:
	static void discretGradient(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez);
	static void robertsGradient(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,double T,TColor krawedz,TColor tlo);
	static void robertsGradientYuv(Graphics::TBitmap *bmp,Graphics::TBitmap *bmpRez,double T,TColor krawedz,TColor tlo,bool b_krawedz,bool b_tlo);
	protected:
	static void setProg(int &rgb,int T,TColor color,char c);
	static void setWhite(int &rgb,int T);

};
#endif
