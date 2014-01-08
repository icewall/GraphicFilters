//---------------------------------------------------------------------------

#ifndef frmZdjecieH
#define frmZdjecieH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformZdjecie : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall TformZdjecie(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformZdjecie *formZdjecie;
//---------------------------------------------------------------------------
#endif
