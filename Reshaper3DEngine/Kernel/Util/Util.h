#pragma once

#include <list>
using namespace std;

namespace Kernel
{
	namespace Util
	{

RsDEFINE_DLL_CLASS(CUtil)
{
#pragma region Construction & Destruction
private:
	CUtil();
	virtual ~CUtil();
#pragma endregion

#pragma region Static Function
public:
	template<class _type>
	static void				Swap(_type & ioVal1, _type & ioVal2)	{	_type tmp = ioVal1;	ioVal1 = ioVal2;	ioVal2 = tmp;	}
	static const CString	MakeCompletedPath(const UINT iNumOfArgs, ...);
	static const list<CString>	GetFiles(const CString & iFilePath, const BOOL bRecursive = FALSE);
	static const BOOL		IsType(const UINT iType, const UINT iTypeToCheck) { return (iType & iTypeToCheck) == iTypeToCheck; }
	static INT				GetUpper(const INT value) { return value >> 16; }
	static INT				GetLower(const INT value) { return value & 0xFFFF; }
	static const BOOL		IsInside(const DOUBLE iValue1, const DOUBLE iValue2, const DOUBLE iValue3, const DOUBLE iValueToTest);
	static void				Trace(TCHAR * szFormat, ...);
	static const CString	Format(TCHAR * szFormat, ...);
	static void				Compress(const BYTE * iSrcBuff, const UINT iSrcSize, BYTE *& oDesBuff, UINT & oDesSize);
	static void				Decompress(const BYTE * iSrcBuff, const UINT iSrcSize, BYTE *& oDesBuff, UINT & oDesSize);
	static const DOUBLE		Dist(const DOUBLE x1, const DOUBLE y1, const DOUBLE x2, const DOUBLE y2);
	static const DOUBLE		DistSquare(const DOUBLE x1, const DOUBLE y1, const DOUBLE x2, const DOUBLE y2);
	static CString			ToString(const int nValue);
	static CString			ToString(const bool bValue);
	static CString			ToString(const double dValue);
	static CString			ToString(LPCTSTR iFormat, const double dValue);
	static CString			ToString(const float fValue);
	static CString			ToString(LPCTSTR iFormat, const float fValue);
	static CString			ToString(const unsigned long lValue);
	static const vector<INT>	ToVectorIntList(LPCTSTR iString, LPCTSTR iDelimiter);
	static const CString	GetCurTime(const UINT iFormatType = 0);
	static const CString	GetDirectoryPath(CString & iFilePath);
	static const CString	GetFileName(CString& iFilePath, bool extension);
	static const CString	GetFileExtension(CString & iFilePath);
	static const BOOL		IsPreSuffixChecked(LPCTSTR iDataToCheck, LPCTSTR iCheckData, const UINT16 nType);
	static void				ConvertToPairVector(const vector<INT> & input, vector<pair<INT, INT>> & output);
	static string			ConvertWideCharToChar(CStringW& strText);
	static string			ConvertWideCharToChar(wstring& strText);
	static string			DecodeBase64Text(CString strText);
	static string			DecodeBase64Text(wstring strText);
	static string			DecodeBase64Text(string strText);
	static BOOL				SequentialEquals(const BYTE* pBuff, const BYTE* pBuff2, UINT64 nBuffSize);
	template<class _type>
	static const _type		Ratio(const _type iValueToCheck, const _type iValueCriteria) { return iValueToCheck / iValueCriteria; }
	static const INT		GetIndexAroundValue(const vector<DOUBLE> & iList, const DOUBLE iValue);
	static const INT		Random(const INT iStart, const INT iEnd);
	static const DOUBLE		Random(const DOUBLE iStart, const DOUBLE iEnd);
	static const INT		RandomWeight(const INT iStart, const INT iEnd, vector<UINT> & iWeights);
	static const vector<CString>	Split(LPCTSTR iString, LPCTSTR iDelim);
	static const LONG64		MakeLong64(const LONG iHiLong, const LONG iLoLong);
	static void				ExtractLong(const LONG64 iLong64, LONG & oHiLong, LONG & oLoLong);
	static const LONG		ExtractHiLong(const LONG64 iLong64);
	static const LONG		ExtractLoLong(const LONG64 iLong64);
	static const CString	GenerateUuid(const UINT iType);
	static const INT		GetNeigborIndices(const UINT iColumn, const UINT iRow, const UINT iNumberOfColumns, const UINT iNumberOfRows, INT oIndices[]);
#pragma endregion
};

	}
}