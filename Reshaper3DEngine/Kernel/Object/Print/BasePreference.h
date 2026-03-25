#pragma once

#include <map>
using namespace std;

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Print
		{

RsDEFINE_DLL_CLASS(CBasePreference)
{
public:
	typedef map<CKeyString, CDataObject *>	_PreferenceMap;
	typedef list<CKeyString>				_KeyList;
#pragma region Construction & Destruction
protected:
	CBasePreference();
public:
	virtual ~CBasePreference();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CDataObject *		GetPrefernce(const CKeyString iKey) const { return FindPreference(iKey); }
	inline const CBasePreference::_PreferenceMap &	GetPreferenceList() const { return m_Preferences; }
#pragma endregion

public:
	void					Release();

public:
	const CKeyString		UniqueModelKey(const CKeyString & iKey) const;

	const CBasePreference::_KeyList	GetKeyList() const;
	void					GetKeyList(list<CString> & oKeyList) const;

	CDataObject *			First();
	CDataObject *			Last();

	const BOOL				AddPreference(CDataObject * iPreference, const BOOL iCurrent = FALSE);
	const BOOL				RemovePreference(CDataObject * iPreference);
	const BOOL				ChangeKey(const CKeyString iOldKey, CDataObject * iPreference);
protected:
	const CDataObject *		FindPreference(const CKeyString iKey) const;
	const BOOL				Contain(const CKeyString iKey) const;

public:
	const CDataObject *		GetCurrent() const;
	void					SetCurrent(const CKeyString iKey);

public:
	static const INT		LoadPreference(const map<CString, IXMLObject *> & ioObjects, const CString iPathTo, const CString iPathFrom);

#pragma region Memeber Variable
protected:
	CKeyString				m_Current;
private:
	_PreferenceMap			m_Preferences;
#pragma endregion
};

		}
	}
}