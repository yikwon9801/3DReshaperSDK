#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Print
		{
RsDEFINE_DLL_CLASS(CDevicePreference) : RsINHERITANCE(CBasePreference)
{
#pragma region Construction & Destruction
public:
	CDevicePreference();
	virtual ~CDevicePreference();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CDevice *	GetPrefernce(const CKeyString iKey) const { return dynamic_cast<const CDevice *>(CBasePreference::GetPrefernce(iKey)); }
	inline CDevice *		First() { return dynamic_cast<CDevice *>(CBasePreference::First()); }
	inline CDevice *		Last() { return dynamic_cast<CDevice *>(CBasePreference::Last()); }
#pragma endregion

public:
	const CDevice *			GetCurPreference() const;

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}