#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			RsDEFINE_CLASS(CGeometryObject);
		}
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygons2D);
	}

	namespace File
	{
		namespace Slice
		{
			using namespace Kernel::File;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;
			using namespace Kernel::Object::Geometry::Mesh;
			using namespace Kernel::Slice;

RsDEFINE_DLL_CLASS(CCliFile) : RsINHERITANCE(CFileBase)
{
#pragma region Construction & Destruction
public:
	CCliFile(LPCTSTR iFileName, const OpenMode iMode);
public:
	virtual ~CCliFile();
#pragma endregion

#pragma region File
public:
	const BOOL				Read(CSlicedPolygons2D & oSlicedPolygons, CProgress * iProgress = NULL);
private:
	const BOOL				_ReadAsciiPolygonAndHatch(CSlicedPolygons2D & oSlicedPolygons, const REAL iUnit, const UINT iFileSize, CProgress * iProgress = NULL);
	const BOOL				_ReadBinaryPolygonAndHatch(CSlicedPolygons2D & oSlicedPolygons, const REAL iUnit, const UINT iFileSize, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Static Function
public:
#pragma endregion
};

		}
	}
}