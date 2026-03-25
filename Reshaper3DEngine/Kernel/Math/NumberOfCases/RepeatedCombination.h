#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Math
	{

		namespace NumberOfCases
		{
			using namespace Kernel::Object;

RsDEFINE_DLL_CLASS(CRepeatedCombination) : RsINHERITANCE(CCombination)
{
public:
	typedef vector<vector<INT>>		CombinationResult;
#pragma region Construction & Destruction
public:
	CRepeatedCombination(const vector<INT> & iNumberList);
	virtual ~CRepeatedCombination();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Mathematic
public:
	const INT				Get(const UINT iR, CombinationResult & oResult) const;
#pragma endregion

protected:
	const BOOL				IsEqual(const CRepeatedCombination & iCombination) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CRepeatedCombination *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CRepeatedCombination &	operator = (const CRepeatedCombination & iCombination);
	const BOOL				operator == (const CRepeatedCombination & iCombination) const;
	const BOOL				operator != (const CRepeatedCombination & iCombination) const;
#pragma endregion

public:
	static const INT		Combination(const vector<INT> & iNumberList, const UINT iR, CombinationResult & oResult);

#pragma region Memeber Variable
private:
	vector<INT>				m_NumberList;
#pragma endregion
};

		}
	}
}