//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.hpp"
#include <string>
using namespace std;
//---------------------------------------------------------------------------
typedef struct{
	size_t id;
	wstring url;
	wstring title;
	size_t visit_count;
	wstring last_visit_time;
} MyNodeType;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TVirtualStringTree *vst;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Status;
	TLabel *OutInfo;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall vstGetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
          TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
