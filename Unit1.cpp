//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
 //---------------------------------------------------------------------------
#include "Unit1.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
using namespace std;
sqlite3 *ChromeDB = NULL;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	vst->NodeDataSize = sizeof(MyNodeType);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::vstGetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
          TVSTTextType TextType, UnicodeString &CellText)
{
	if(!Node) return;

	MyNodeType *nodeData = (MyNodeType*)vst->GetNodeData(Node);

	switch (Column) {
		case 0: CellText = nodeData->id; break;
		case 1: CellText = nodeData->url.c_str(); break;
		case 2: CellText = nodeData->title.c_str(); break;
		case 3: CellText = nodeData->visit_count; break;
        case 4: CellText = nodeData->last_visit_time.c_str(); break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	vst->Clear();

	if(sqlite3_open16(L"history.sqlite", &ChromeDB))
	{
		OutInfo->Caption = "Database loaded";
	}
	else
	{
		OutInfo->Caption = sqlite3_errmsg(ChromeDB);
	}

	sqlite3_stmt *pStat;

	const char *sqlSelect = "SELECT id, url, title, visit_count, datetime(last_visit_time / 1000000 + (strftime('%s', '1601-01-01')), 'unixepoch') FROM urls";

	int result = sqlite3_prepare_v2(ChromeDB,sqlSelect,-1,&pStat, NULL);

	if(result != SQLITE_OK)
	{
		OutInfo->Caption = sqlite3_errmsg(ChromeDB);
	}
	else
	{
		OutInfo->Caption = "Working with database";

		vst->BeginUpdate();

		while(sqlite3_step(pStat)==SQLITE_ROW)
		{
			PVirtualNode newNode = vst->AddChild(vst->RootNode);
			MyNodeType *nodeData = (MyNodeType*)vst->GetNodeData(newNode);
			nodeData->id = (size_t)sqlite3_column_int(pStat, 0);
			nodeData->url = (wchar_t *)sqlite3_column_text16(pStat, 1);
			nodeData->title = (wchar_t *)sqlite3_column_text16(pStat, 2);
			nodeData->visit_count = (size_t)sqlite3_column_int(pStat, 3);
			nodeData->last_visit_time = (wchar_t *)sqlite3_column_text16(pStat, 4);
		}
		vst->EndUpdate();
	}
	sqlite3_finalize(pStat);

	sqlite3_close(ChromeDB);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if (vst->FocusedNode != NULL) //
	{
		int rowID = ((MyNodeType*)vst->GetNodeData(vst->FocusedNode))->id;
		const char *delRow = ("delete from urls where id=" + std::to_string(rowID)).c_str();
		sqlite3_open("history.sqlite", &ChromeDB);
		char *err;
		sqlite3_exec(ChromeDB, delRow, NULL, NULL, &err); //
		sqlite3_close(ChromeDB);
		vst->DeleteSelectedNodes(); //
		OutInfo->Caption = "Selected row was successfully deleted";
	}
	else
		OutInfo->Caption = sqlite3_errmsg(ChromeDB);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	sqlite3_open("history.sqlite", &ChromeDB);
	const char *rmAll = "delete from urls";
	char *err;
	int result = sqlite3_exec(ChromeDB, rmAll, NULL, NULL, &err);
	sqlite3_close(ChromeDB);
	if (result == SQLITE_OK)
	{
		vst -> BeginUpdate();
		vst -> Clear();
		vst -> EndUpdate();
		OutInfo->Caption = "Database was successfully deleted";
	}
	else

	OutInfo->Caption = sqlite3_errmsg(ChromeDB);
}
//---------------------------------------------------------------------------

