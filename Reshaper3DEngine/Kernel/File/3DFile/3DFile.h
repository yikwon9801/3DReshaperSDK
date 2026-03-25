#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Geometry
		{
			namespace Mesh
			{

			}

			RsDEFINE_CLASS(CGeometryObject);
		}
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace File
	{
		namespace File3D
		{
			using namespace Kernel::File;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;
			using namespace Kernel::Object::Geometry::Mesh;

#pragma region Macro
#define BEGIN_3DFILEGEOMETRY(fileName,type,ret)						\
	C3DFile * loader = C3DFile::Loader(fileName, type);				\
	ASSERT(loader);													\
	BOOL ret = loader != NULL ? TRUE : FALSE;
#define BEGIN_READGEOMETRY(obj,fileName,Progress,ret)				\
	BEGIN_3DFILEGEOMETRY(fileName,0,ret)							\
	if (bRet){ ret = loader->Read(obj, iProgress); }
#define BEGIN_WRITEGEOMETRY(obj,fileName,filetype,Progress,ret)		\
	BEGIN_3DFILEGEOMETRY(fileName, 1, ret)							\
	if (bRet){ ret = loader->Write(obj, filetype, iProgress); }
#define END_GEOMETRY()												\
	delete loader;
#pragma endregion

RsDEFINE_DLL_CLASS(C3DFile) : RsINHERITANCE(CFileBase)
{
#pragma region Construction & Destruction
protected:
	C3DFile(LPCTSTR iFileName, const OpenMode iMode);
public:
	virtual ~C3DFile();
#pragma endregion

protected:
	virtual const LPCTSTR		GetExtend() const = 0;

#pragma region File
public:
	virtual const BOOL			Read(CGeometryObject & iObjectToStore, CProgress * iProgress = NULL) = 0;
	virtual const BOOL			Write(const CGeometryObject & iObjectToStore, const INT iType, CProgress * iProgress = NULL) = 0;
#pragma endregion

#pragma region Static Function
public:
	static C3DFile *			Loader(LPCTSTR iFileName, const UINT16 iType);
#pragma endregion
};

		}
	}
}