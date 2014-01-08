//---------------------------------------------------------------------------

#ifndef GraphicCoreH
#define GraphicCoreH
//---------------------------------------------------------------------------
class CGraphicCore
{
	public:
   		static TColor getProperPixel(Graphics::TBitmap *bmp,int x,int y);    	
		static bool isProgEnable(double T);
		static void setColor(int &r,int &g,int &b,TColor color);		
};
#endif
