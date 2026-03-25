#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Print
		{
RsDEFINE_DLL_CLASS(CMaterialPreference) : RsINHERITANCE(CBasePreference)
{
#pragma region Construction & Destruction
public:
	CMaterialPreference();
	virtual ~CMaterialPreference();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CMaterial *	GetPrefernce(const CKeyString iKey) const { return dynamic_cast<const CMaterial *>(CBasePreference::GetPrefernce(iKey)); }
	inline CMaterial *		First() { return dynamic_cast<CMaterial *>(CBasePreference::First()); }
	inline CMaterial *		Last() { return dynamic_cast<CMaterial *>(CBasePreference::Last()); }
#pragma endregion

public:
	const CMaterial *		GetCurPreference() const;

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}