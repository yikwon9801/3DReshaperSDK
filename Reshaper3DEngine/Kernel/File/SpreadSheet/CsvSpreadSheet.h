#pragma once
#include "CSpreadSheet.h"

using namespace std;

namespace Kernel
{
	namespace File
	{
		namespace SpreadSheet
		{

			RsDEFINE_DLL_CLASS(CsvSpreadSheet): RsINHERITANCE(CSpreadSheet)
			{
			public:
				CsvSpreadSheet(CString strFile=_T(""));
				virtual ~CsvSpreadSheet();

			public:
				virtual BOOL ReadFile(CString strFilePath);
				virtual BOOL WriteFile(CString strFilePath);

				void SetNewLineChar(wchar_t chNewLineChar) { m_chNewLineChar = chNewLineChar; }
				wchar_t GetNewLineChar() { return m_chNewLineChar; }

			private:
				wchar_t m_chNewLineChar = '|';
			};
		}
	}
}