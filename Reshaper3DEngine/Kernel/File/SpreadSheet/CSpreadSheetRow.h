#pragma once
#include "CSpreadSheetCell.h"

namespace Kernel
{
	namespace File
	{
		namespace SpreadSheet
		{

RsDEFINE_DLL_CLASS(CSpreadSheetRow)
{
public:
	CSpreadSheetRow();
	virtual ~CSpreadSheetRow();

private:
	vector<CSpreadSheetCell> m_Columns;

public:
	CSpreadSheetCell* GetCellPtr(int nIdx = -1);
	int GetColumnCount();

	// added stl like functions
	size_t size();
	CSpreadSheetCell& at(int nIdx);
	CSpreadSheetCell& at(size_t nIdx);
	CSpreadSheetCell* at_ptr(size_t nIdx);
	CSpreadSheetCell* at_ptr(int nIdx);

	void AllocateColumn(int nCount);
	int AppendColumn(CString text = _T(""));

	std::wstring ToString(CSpreadSheetCell::CSpreadSheetFormat fmt);

};
		}
	}
}