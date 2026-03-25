#pragma once

#include <list>
using namespace std;

namespace Kernel
{

	namespace String
	{

RsDEFINE_DLL_CLASS(CKeyString) : RsINHERITANCE(CString)
{
public:
	typedef list<CString>	StringList;
#pragma region Construction & Destruction
public:
	CKeyString();
	CKeyString(const CKeyString & rhs);
	CKeyString(const CString & val);
	CKeyString(LPCTSTR val);
	CKeyString(const INT val);
	virtual ~CKeyString();
#pragma endregion

public:
	static const CKeyString::StringList	Split(const CString iStringToSplit, const CString iDelim);

#pragma region Operator Declaration
public:
	const CKeyString &		operator = (const CKeyString & rhs);
	const CKeyString &		operator = (const INT val);
	const CKeyString &		operator = (const CString & val);
	const CKeyString &		operator += (const INT val);
	const CKeyString		operator + (const INT val) const;
#pragma endregion
};

	}
}