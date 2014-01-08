//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

using namespace std;
#include "Unit5.h"
#include "frmZdjecie.h"
#include "Filters.h"
#include "frmZdjecieRez.h"
#include "Outlines.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;

//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	if(!FileListBox1->FileName.IsEmpty()){
			formZdjecie->Image1->Picture->LoadFromFile(FileListBox1->FileName);
			formZdjecie->Width  = formZdjecie->Image1->Picture->Width  + 8;
			formZdjecie->Height = formZdjecie->Image1->Picture->Height + 34;
			formZdjecie->Show();
			formZdjecieRez->Image1->Picture->LoadFromFile(FileListBox1->FileName);
			formZdjecieRez->Width  = formZdjecieRez->Image1->Picture->Width  + 8;
			formZdjecieRez->Height = formZdjecieRez->Image1->Picture->Height + 34;
			formZdjecieRez->Show();
		}
		else
        	ShowMessage("You did not choose any image file.");
}
//---------------------------------------------------------------------------
vector<double> TForm5::EditsToVector()
{
	TEdit *edit;
	vector<double> values;
	int countOfEditBoxs = ComboBox1->Text.ToInt() * ComboBox1->Text.ToInt();

	for (int i = 1; i <= countOfEditBoxs; i++) {
		edit = (TEdit*)this->FindComponent("Edit" + (String)i);
		if(edit)
			values.push_back(edit->Text.Trim().ToDouble());
		else
			break;
	}
   return values;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{

	vector<double> window = EditsToVector();
	CFilters::windowFilter(formZdjecie->Image1->Picture->Bitmap,
					       formZdjecieRez->Image1->Picture->Bitmap,
						   window,
						   TrackBar3->Position,
						   ComboBox3->Text.ToInt(),
						   CheckBox1->Checked);
						   
}
//---------------------------------------------------------------------------
void TForm5::generateEdits()
{

//znajdz pozycje dla editsow
/*
  znajdz srodek danej kontrolki rodzica mp. Groupbox
  wyznacz dlugosc wszystkich kontrolek w rzedzie poziomo i pionowo
  zmniejsz srodek ukladu czyli tak naprawde nasz poczatek o polowe dlugosci kontrolek
*/
	int x_srodekUkladu = GroupBox3->Width / 2;
	int y_srodekUkladu = GroupBox3->Height / 2 ;
	int editWidth  = 25;
	int editHeight = 25;	
	int iloscEditBoxow = ComboBox1->Text.ToInt();
	int margines = 5 ; //odleglosc pomiedzy editbox'ami
	int top  = y_srodekUkladu;
	int left = x_srodekUkladu;

	//calkowita dlugosc ukladu editow
	int dlugoscEditow = editWidth * iloscEditBoxow + margines * (iloscEditBoxow - 1);
	dlugoscEditow /= 2;//musimy przesunac top and left srodka o polowe dlugosci editow
	top  -= dlugoscEditow;
	left -= dlugoscEditow;

	int row    = 0;
	int column = 0;

	for(int i = 0; i < iloscEditBoxow * iloscEditBoxow; ++i)
	{
		TEdit *edit = new TEdit(this);
		edit->Name = "Edit" + (String)(i+1);
		edit->Text = "1,0";		
		edit->Parent = GroupBox3;
		edit->Visible = true;
		edit->Width = editWidth;
		edit->Height = editHeight;
		edit->Top = top + row*(editHeight + margines);;
		edit->Left = left + column*(editWidth + margines);
		if( ((i+1) % iloscEditBoxow) == 0 )
		{
			row++;
			column = -1;
		}
		column++;
    }
}
void TForm5::freeEdits()
{
	//znajdz wszystkie editbox'y i je zwolnij
	int i = 1;
	while(true)
	{
		TEdit *edit = (TEdit*)this->FindComponent("Edit" + (String)i);
		if(!edit)
			break;

		edit->Visible = false;
		edit->Free();
		i++;
	}

}
void __fastcall TForm5::Button4Click(TObject *Sender)
{
	freeEdits();
	LockWindowUpdate(GroupBox3->Handle);
	generateEdits();
	LockWindowUpdate(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button3Click(TObject *Sender)
{
	LockWindowUpdate(formZdjecie->Handle);
	CFilters::medianFilter(formZdjecie->Image1->Picture->Bitmap,
						   formZdjecieRez->Image1->Picture->Bitmap,
						   ComboBox1->Text.ToInt());
	LockWindowUpdate(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button5Click(TObject *Sender)
{

	COutlines::robertsGradientYuv(formZdjecie->Image1->Picture->Bitmap,
							   formZdjecieRez->Image1->Picture->Bitmap,
							   TrackBar2->Position,
							   krawedz,
							   tlo,
							   CheckBox2->Checked,
							   CheckBox3->Checked							   
							   );

}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button6Click(TObject *Sender)
{
	if(ColorDialog1->Execute())
	   this->krawedz = ColorDialog1->Color;
	PaintBox1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button7Click(TObject *Sender)
{
	if(ColorDialog1->Execute())
	 this->tlo = ColorDialog1->Color;
	PaintBox2->Repaint();	 	
}
//---------------------------------------------------------------------------
void __fastcall TForm5::PaintBox1Paint(TObject *Sender)
{
	PaintBox1->Canvas->Brush->Color = this->krawedz;
	PaintBox1->Canvas->Rectangle(0,0,PaintBox1->Width,PaintBox1->Height);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::PaintBox2Paint(TObject *Sender)
{
	PaintBox2->Canvas->Brush->Color = this->tlo;
	PaintBox2->Canvas->Rectangle(0,0,PaintBox2->Width,PaintBox2->Height);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::TrackBar1Change(TObject *Sender)
{
    if(TrackBar1->Position != -1)
		Label5->Caption = TrackBar1->Position;
	else
    	Label5->Caption = "brak";
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Button8Click(TObject *Sender)
{
	CFilters::windowNine(  formZdjecie->Image1->Picture->Bitmap,
						   formZdjecieRez->Image1->Picture->Bitmap,
						   TrackBar1->Position,
					   	   this->krawedz,
					   	   this->tlo
					   	);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button9Click(TObject *Sender)
{
	if(ColorDialog1->Execute())
	   this->krawedz = ColorDialog1->Color;
	PaintBox3->Repaint();	
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button10Click(TObject *Sender)
{
	if(ColorDialog1->Execute())
	   this->tlo = ColorDialog1->Color;
	PaintBox4->Repaint();	
}
//---------------------------------------------------------------------------

void __fastcall TForm5::PaintBox3Paint(TObject *Sender)
{
	PaintBox3->Canvas->Brush->Color = this->krawedz;
	PaintBox3->Canvas->Rectangle(0,0,PaintBox3->Width,PaintBox3->Height);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::TrackBar2Change(TObject *Sender)
{
    if(TrackBar2->Position != -1)
		Label8->Caption = TrackBar2->Position;
	else
		Label8->Caption = "brak";
}
//---------------------------------------------------------------------------

void __fastcall TForm5::PaintBox4Paint(TObject *Sender)
{
	PaintBox4->Canvas->Brush->Color = this->tlo;
	PaintBox4->Canvas->Rectangle(0,0,PaintBox4->Width,PaintBox4->Height);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::TrackBar3Change(TObject *Sender)
{
	if(TrackBar3->Position > 0)
		Label10->Caption = TrackBar3->Position;
	else
		Label10->Caption = "brak";
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button11Click(TObject *Sender)
{
   Graphics::TBitmap *bmp = formZdjecie->Image1->Picture->Bitmap;
		//glowny loop dla siatki pixeli wyznaczajacy tzw pixel wyrozniony
	for(int x = 1;x < bmp->Width - 5;++x)
	{
	  for(int y = 1;y < bmp->Height - 5;++y)
	  {

		  bmp->Canvas->Pixels[x][y] = bmp->Canvas->Pixels[x+rand()%5][y+rand()%5];
	  }
	}
}
//---------------------------------------------------------------------------


