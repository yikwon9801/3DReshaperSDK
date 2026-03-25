#pragma once

namespace Kernel
{
	namespace File
	{
		namespace SpreadSheet
		{
RsDEFINE_DLL_CLASS(CSpreadSheetCell)
{
public:
	enum CSpreadSheetFormat
	{
		SpreadSheetFormat_Csv, 
		SpreadSheetFormat_Excel_97,
		SpreadSheetFormat_Excel_02
	};

public:
	CSpreadSheetCell(CString text = _T(""));
	virtual ~CSpreadSheetCell();

public:
	int nColIdx;
	int nRowIdx;
	CString strText;

	CString GetText();
	int GetInt();
	double GetSingle();
};

		}
	}
}