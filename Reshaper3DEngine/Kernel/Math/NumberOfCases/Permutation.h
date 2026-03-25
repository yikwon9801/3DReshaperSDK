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

RsDEFINE_DLL_CLASS(CPermutation) : RsINHERITANCE(CDataObject)
{
public:
	typedef vector<vector<INT>>		PermutationResult;
#pragma region Construction & Destruction
public:
	CPermutation(const vector<INT> & iNumberList);
	virtual ~CPermutation();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Mathematic
public:
	const INT				Get(const UINT iR, PermutationResult & oResult) const;
#pragma endregion

protected:
	const BOOL				IsEqual(const CPermutation & iCombination) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPermutation *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CPermutation &	operator = (const CPermutation & iCombination);
	const BOOL				operator == (const CPermutation & iCombination) const;
	const BOOL				operator != (const CPermutation & iCombination) const;
#pragma endregion

public:
	static const INT		Permutation(const vector<INT> & iNumberList, const UINT iR, PermutationResult & oResult);

#pragma region Memeber Variable
protected:
	vector<INT>				m_NumberList;
#pragma endregion
};

		}
	}
}