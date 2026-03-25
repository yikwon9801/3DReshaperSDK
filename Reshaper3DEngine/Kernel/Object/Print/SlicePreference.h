#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Print
		{

RsDEFINE_DLL_CLASS(CSlicePreference) : RsINHERITANCE(CBasePreference)
{
#pragma region Construction & Destruction
public:
	CSlicePreference();
	virtual ~CSlicePreference();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CSlice *	GetPrefernce(const CKeyString iKey) const { return dynamic_cast<const CSlice *>(CBasePreference::GetPrefernce(iKey)); }
	inline CSlice *			First() { return dynamic_cast<CSlice *>(CBasePreference::First()); }
	inline CSlice *			Last() { return dynamic_cast<CSlice *>(CBasePreference::Last()); }
#pragma endregion

public:
	const CSlice *			GetCurPreference() const;

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}