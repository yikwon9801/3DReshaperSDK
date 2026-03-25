#pragma once

#include <list>
#include <vector>

using namespace std;

namespace Kernel
{

	namespace String
	{

RsDEFINE_DLL_CLASS(CHyString) : RsINHERITANCE(CString)
{
#pragma region Construction & Destruction
public:
	CHyString();
	CHyString(BYTE * Bytes);
	CHyString(LPCSTR lpString);
	CHyString(LPCTSTR lpString);
	CHyString(const UINT16 uint16);
	CHyString(const UINT uint);
	CHyString(const INT integer);
	CHyString(const DOUBLE value);
	CHyString(const FLOAT value);
	virtual ~CHyString();
#pragma endregion

public:
	const UINT				GetCount(const LPCTSTR iStringToFind, const LPCTSTR iEndString = NULL) const;
	const UINT				Split(const LPCTSTR iStringToFind, CHyString oSplitString[], const UINT iLength) const;
	const CHyString &		FromFloat(const CHyString iFormat, const FLOAT iValue);

	const UINT				ToINT() const;
	const UINT64			ToINT64() const;
	const UINT				ToUINT() const;
	const UINT64			ToUINT64() const;
	const DOUBLE			ToDOUBLE() const;
	const FLOAT				ToFLOAT() const;
	const BOOL				ToBOOL() const;

#pragma region Operator Declaration
public:
	const CHyString &		operator = (LPCTSTR lpString);
	const CHyString &		operator = (const UINT16 uint16);
	const CHyString &		operator = (const UINT uint);
	const CHyString &		operator = (const INT integer);
	const CHyString &		operator = (const DOUBLE value);
	const CHyString &		operator = (const FLOAT value);
#pragma endregion

#pragma region Static Function
public:
	static const UINT		Split(const CHyString & iString, const CHyString iDelim, list<CHyString> & oSplitString);
	static const UINT		Split(const CHyString & iString, const CHyString iDelim, vector<CHyString> & oSplitString);
	static const INT		ExtractString(const CHyString & iString, const CHyString iDelim, const INT iStartIndex, CHyString & oString);
	static const CHyString	CompletedString(const list<CHyString> & iStrings, const CString iDelim);
	static const CHyString	FloatToString(const FLOAT iValue, const UINT iScaleNumber);
	static const BOOL		IsDigit(LPCTSTR lpstrString);
	static const INT		FindReverse(LPCTSTR iTarget, LPCTSTR iSearch, const INT iPos);
	static const CStringA	UTF16ToUTF8(LPCWSTR iContent);
	static const CStringW	UTF8ToUTF16(LPCSTR iContent);
	static const CStringA	UTF16ToMultibyte(LPCWSTR iContent);
	static const CStringW	MultibyteToUTF16(LPCSTR iContent);
	static const CString	CurrentTimeToString(LPCTSTR format);
#pragma endregion
};

	}
}