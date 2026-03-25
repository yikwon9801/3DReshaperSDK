#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(IFileObject);
		RsDEFINE_INTERFACE(IDeviceObject);
	}

	namespace Device
	{
		using namespace Kernel::Interface;

RsDEFINE_DLL_CLASS(CDeviceObject) : RsIMPLEMENT(IDeviceObject), RsIMPLEMENT(IFileObject)
{
#pragma region Construction & Destruction
public:
	CDeviceObject();
	virtual ~CDeviceObject();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
protected:
#pragma endregion

#pragma region Abstract fuction of IDeviceObject
public:
#pragma endregion

#pragma region File Declaration
public:
#pragma endregion

#pragma region Operator Declaration
public:
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

	}
}