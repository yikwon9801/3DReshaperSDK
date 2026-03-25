#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Collection
	{
		namespace Object
		{
			RsDEFINE_CLASS(CManagedObject);
		}
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Geometry
		{
			using namespace Kernel::File;
			using namespace Kernel::Collection::Object;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGeometryObject) : RsINHERITANCE(CManagedObject)
{
#pragma region Construction & Destruction
protected:
	CGeometryObject();
public:
	virtual ~CGeometryObject();
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert() = 0;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion
};

		}
	}
}