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

RsDEFINE_DLL_CLASS(CCombination) : RsINHERITANCE(CDataObject)
{
public:
	typedef vector<vector<INT>>		CombinationResult;
#pragma region Construction & Destruction
public:
	CCombination(const vector<INT> & iNumberList);
	virtual ~CCombination();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Mathematic
public:
	const INT				Get(const UINT iR, CombinationResult & oResult) const;
#pragma endregion

protected:
	const BOOL				IsEqual(const CCombination & iCombination) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CCombination *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CCombination &	operator = (const CCombination & iCombination);
	const BOOL				operator == (const CCombination & iCombination) const;
	const BOOL				operator != (const CCombination & iCombination) const;
#pragma endregion

public:
	static const INT		Combination(const vector<INT> & iNumberList, const UINT iR, CombinationResult & oResult);

#pragma region Memeber Variable
protected:
	vector<INT>				m_NumberList;
#pragma endregion
};

		}
	}
}