#pragma once

#include <unordered_map>
using namespace std;

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CHyString);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGeometryObject);

			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}
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
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;
			using namespace Kernel::Object::Geometry::Mesh;
			using namespace Kernel::String;

RsDEFINE_DLL_CLASS(C3DFileSTL) : RsINHERITANCE(C3DFile)
{
#pragma region Type Definition
private:
	typedef vector<INT32>	_VertexVector;
	typedef unordered_map<INT64, _VertexVector>	_VertexMapVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	C3DFileSTL(LPCTSTR iFileName, const OpenMode iMode);
	virtual ~C3DFileSTL();
#pragma endregion

#pragma region File Extension
protected:
	virtual const LPCTSTR		GetExtend() const	{ return m_Extend[FILETYPE_STL]; }
#pragma endregion

#pragma region Abstract function of C3DFile
public:
	typedef enum
	{
		STLTYPE_BINARY,
		STLTYPE_ASCII,
	}STLTYPE;
	virtual const BOOL			Read(CGeometryObject & iObjectToStore, CProgress * iProgress = NULL);
	virtual const BOOL			Write(const CGeometryObject & iObjectToStore, const INT iType, CProgress * iProgress = NULL);
private:
	const BOOL					_ReadBinary(CGPolyhedron * iPolyToStore, CProgress * iProgress = NULL);
	const BOOL					_ReadAscii(CGPolyhedron * iPolyToStore, CProgress * iProgress = NULL);
	const BOOL					_WriteBinary(const CGPolyhedron * iPolyToStore, CProgress * iProgress = NULL);
	const BOOL					_WriteAscii(const CGPolyhedron * iPolyToStore, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}