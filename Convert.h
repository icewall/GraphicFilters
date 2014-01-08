//---------------------------------------------------------------------------

#ifndef ConvertH
#define ConvertH
//---------------------------------------------------------------------------
class Cyuv
{
  public:
	  Cyuv(char inY,char inU,char inV)
	  :y(inY),u(inU),v(inV)
	  {}
	  Cyuv(){}  
	  unsigned char y;
	  unsigned char u;
	  unsigned char v;
};
//global overloaded operator
Cyuv operator+(const Cyuv &lhs,const Cyuv &rhs)
{
	char y = lhs.y + rhs.y;
	char u = lhs.u + rhs.u;
	char v = lhs.v + rhs.v;
	return Cyuv(y,u,v);
}

class Convert
{
	public:
	
	static TColor yuv2rgb(char y, char u,  char v);
	static Cyuv rgb2yuv(char r, char g, char b);
	static TColor yuv2rgb(Cyuv yuv);
	static Cyuv rgb2yuv(TColor rgb);
	static Cyuv Prgb2yuv(int r,int g,int b);
	static TColor Pyuv2rgb(int y, int u, int v);
};
#endif
