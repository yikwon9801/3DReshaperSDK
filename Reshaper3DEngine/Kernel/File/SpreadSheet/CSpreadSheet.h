#pragma once

namespace Kernel
{
	namespace File
	{
		namespace SpreadSheet
		{
			RsDEFINE_CLASS(CSpreadSheetCell);
			RsDEFINE_CLASS(CSpreadSheetRow);

RsDEFINE_DLL_CLASS(CSpreadSheet)
{
public:
	CSpreadSheet();
	virtual ~CSpreadSheet();

private:
	char ConvertWideCharToChar(wchar_t c);
	int WideCharToInt(wchar_t character);
	int WideStringToInt(CString strText);

protected:
	CString m_strFilePath;
	vector<CSpreadSheetRow> m_CellData;

	int AddRow(CSpreadSheetRow rowItem);
	int AppendColumn(int nRowIdx, CString text = _T(""));
	BOOL GetIndexFromCellName(CString strCellName, int& nRowIdx, int& nColIdx);

public:
	CString GetLoadedFilePath();
	vector<CSpreadSheetRow>* GetCellDataPtr();
	CSpreadSheetCell& GetCell(int nCol, int nRow);
	CSpreadSheetCell& GetCell(CString strCellName);
	CSpreadSheetCell* GetCellPtr(int nCol, int nRow);
	CSpreadSheetCell* GetCellPtr(CString strCellName);


	CString GetText(int nCol, int nRow);
	int GetInt(int nCol, int nRow);
	double GetSingle(int nCol, int nRow);
	void ClearAllData();

	int GetRowCount();
	int GetColumnCount();

	virtual BOOL ReadFile(CString strFilePath) = 0;
	virtual BOOL WriteFile(CString strFilePath) = 0;
};
		}
	}
}