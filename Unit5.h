//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet5;
	TPanel *Panel1;
	TButton *Button1;
	TDriveComboBox *DriveComboBox1;
	TPanel *Panel3;
	TDirectoryListBox *DirectoryListBox1;
	TPanel *Panel4;
	TFileListBox *FileListBox1;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TComboBox *ComboBox1;
	TGroupBox *GroupBox2;
	TButton *Button2;
	TButton *Button3;
	TGroupBox *GroupBox3;
	TTabSheet *TabSheet4;
	TButton *Button4;
	TButton *Button5;
	TGroupBox *GroupBox4;
	TComboBox *ComboBox3;
	TCheckBox *CheckBox1;
	TTabSheet *TabSheet2;
	TColorDialog *ColorDialog1;
	TGroupBox *GroupBox5;
	TLabel *Label3;
	TLabel *Label2;
	TPaintBox *PaintBox2;
	TPaintBox *PaintBox1;
	TButton *Button6;
	TButton *Button7;
	TGroupBox *GroupBox6;
	TButton *Button8;
	TLabel *Label4;
	TTrackBar *TrackBar1;
	TLabel *Label5;
	TGroupBox *GroupBox7;
	TLabel *Label6;
	TLabel *Label7;
	TPaintBox *PaintBox3;
	TPaintBox *PaintBox4;
	TGroupBox *GroupBox8;
	TTrackBar *TrackBar2;
	TButton *Button9;
	TButton *Button10;
	TLabel *Label1;
	TLabel *Label8;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TGroupBox *GroupBox9;
	TTrackBar *TrackBar3;
	TLabel *Label9;
	TLabel *Label10;
	TTabSheet *TabSheet3;
	TButton *Button11;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall PaintBox2Paint(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall PaintBox3Paint(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall PaintBox4Paint(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
	std::vector<double> EditsToVector();
	void generateEdits();
	void freeEdits();
	TColor krawedz;
	TColor tlo;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
