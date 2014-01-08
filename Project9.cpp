//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit5.cpp", Form5);
USEFORM("frmZdjecie.cpp", formZdjecie);
USEFORM("frmZdjecieRez.cpp", formZdjecieRez);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TformZdjecie), &formZdjecie);
		Application->CreateForm(__classid(TformZdjecieRez), &formZdjecieRez);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
