#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(Kernel::Interface::IDataObject);
		RsDEFINE_INTERFACE(IFileObject);
	}

	namespace Object
	{
		using namespace Kernel::Interface;

RsDEFINE_DLL_CLASS(CDataObject) : RsIMPLEMENT(Kernel::Interface::IDataObject)
{
#pragma region Construction & Destruction
protected:
	CDataObject();
public:
	virtual ~CDataObject();
#pragma endregion
};


RsDEFINE_DLL_CLASS(CBaseObject) : RsINHERITANCE(CDataObject), RsIMPLEMENT(IFileObject)
{
#pragma region Construction & Destruction
protected:
	CBaseObject();
public:
	virtual ~CBaseObject();
#pragma endregion

};

	}
}