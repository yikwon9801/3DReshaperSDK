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
			RsDEFINE_CLASS(CGMultiLines);
			RsDEFINE_CLASS(CGTriangles);
			RsDEFINE_CLASS(CGTriangles2D);
		}
	}

	namespace Meshing
	{
		using namespace Kernel::File;
		using namespace Kernel::Util;
		using namespace Kernel::Collection;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CTesselation) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	CTesselation(const CGMultiLines & iPolygons, const DOUBLE iZ, const UINT16 iType);
	CTesselation(const CTesselation & iTesselation);
	virtual ~CTesselation();
#pragma endregion

#pragma region Setter & Getter function
public:
	const CGMultiLines &	GetPolygons() const { return m_Polygons; }
#pragma endregion

public:
	const BOOL				Get(CTableArray<CGVertex> & oVertices, CTableArray<CGFace> & oFaces) const;
	const BOOL				Get(CGTriangles & oTriangles) const;
	const BOOL				Get(CGTriangles2D & oTriangles) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CTesselation *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CTesselation &	operator = (const CTesselation & iTesselation);
#pragma endregion

private:
	struct Internal;
	auto_ptr<Internal>		m_Internal;
private:
	const CGMultiLines &	m_Polygons;
	DOUBLE					m_Z;
	UINT16					m_Type;
};

	}
}