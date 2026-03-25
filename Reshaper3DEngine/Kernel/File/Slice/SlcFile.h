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

RsDEFINE_DLL_CLASS(CSlcFile) : RsINHERITANCE(CFileBase)
{
#pragma region Construction & Destruction
public:
	CSlcFile(LPCTSTR iFileName, const OpenMode iMode);
public:
	virtual ~CSlcFile();
#pragma endregion

#pragma region File
public:
	const BOOL				Read(vector<CSlicedPolygon2D> & oPolygons, CProgress * iProgress = NULL);
	const BOOL				Read(CSlicedPolygons2D & oSlicedPolygons, CProgress * iProgress = NULL);
	//const BOOL				Read(CLaserPolygons & oLaserPolygons, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Static Function
public:
	static const BOOL		GetHeadInfomation(LPCTSTR iFileName, SLCHEADINFORMATION & oInfomation);
	static const BOOL		GetHeadInfomation(const BYTE iContents[], SLCHEADINFORMATION & oInfomation);
	static const BOOL		GetHeights(const BYTE iContents[], const UINT64 iContentsLength, vector<FLOAT> & oHeights);
	//static const BOOL		Read(const BYTE iContents[], const UINT64 iContentsLength, CLaserPolygons & oLaserPolygons, CProgress * iProgress = NULL);
	static const BOOL		Read(const BYTE iContents[], const UINT64 iContentsLength, vector<CSlicedPolygon2D> & oPolygons, CProgress * iProgress = NULL);
#pragma endregion
};

		}
	}
}