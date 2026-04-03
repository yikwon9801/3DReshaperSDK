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
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;
	}

	namespace Object
	{
		RsDEFINE_CLASS(CBaseObject);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPolygon2D);
			RsDEFINE_CLASS(CGTriangle2D);
			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGTriangles2D);
			RsDEFINE_CLASS(CGTriangles);
		}
	}

	namespace Meshing
	{
		using namespace Kernel::File;
		using namespace Kernel::Util;
		using namespace Kernel::Collection;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CMeshingPolygon) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	CMeshingPolygon(const CGPolygon2D & iPolygon2D, const DOUBLE iZ, const UINT16 iType);
	CMeshingPolygon(const CMeshingPolygon & iMeshingPolygon);
	virtual ~CMeshingPolygon();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolygon2D &		GetPolygon() const { return m_Polygon2D; }
public:
	const CGPolygon2D &		GetResult() const;
#pragma endregion

public:
	const BOOL				Get(CTableArray<CGVertex> & oVertices, CTableArray<CGFace> & oFaces) const;
	const BOOL				Get(CGTriangles & oTriangles) const;
	const BOOL				Get(CGTriangles2D & oTriangles) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMeshingPolygon *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CMeshingPolygon &	operator = (const CMeshingPolygon & iMeshingPolygon);
#pragma endregion

private:
	struct Internal;
	auto_ptr<Internal>		m_Internal;
private:
	const CGPolygon2D &		m_Polygon2D;
	DOUBLE					m_Z;
	UINT16					m_Type;
};

	}
}