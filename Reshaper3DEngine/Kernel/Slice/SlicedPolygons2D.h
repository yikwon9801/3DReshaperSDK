#pragma once

namespace Kernel
{
	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
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

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
		RsDEFINE_CLASS(CDimension);

		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGMultiLines);
			RsDEFINE_CLASS(CGCloud);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Primitive;
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CSlicedPolygons2D) : RsINHERITANCE(CPolygonLayers<CSlicedPolygon2D>)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CSlicedPolygons2D();
	CSlicedPolygons2D(const CSlicedPolygons2D & iSlicedPolygons);
	virtual ~CSlicedPolygons2D();
#pragma endregion

#pragma region Setter & Getter function
public:

#pragma endregion

#pragma region General Function
public:
	void					ClearPolygons();
	void					ClearOnlyPolygons();
	void					ClearPolygons(const UINT iType);

	void					GetLayerThickness(vector<DOUBLE> & oLayerThickness) const;
	void					GetLayerThickness(vector<vector<DOUBLE>> & oLayerThickness) const;

protected:
	const BOOL				IsEqual(const CSlicedPolygons2D & iSlicedPolygons) const;
#pragma endregion

#pragma region CAD Functions
public:
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	const CBoundingBox		GetVolumeBoundingBox() const;
public:
	virtual const CBoundingBox	GetBoundingBox() const;
#pragma endregion

#pragma region Read & Write 3D File
public:
	const BOOL				ReadSLC(const LPCTSTR lpStrFilePath, CProgress * iProgress = NULL);
	const BOOL				ReadCLI(const LPCTSTR lpStrFilePath, CProgress * iProgress = NULL);
	const BOOL				ReadSliceFile(const LPCTSTR lpStrFilePath, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CSlicedPolygons2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CSlicedPolygons2D &	operator = (const CSlicedPolygons2D & iSlicedPolygons);
	const CSlicedPolygons2D	operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	void					operator += (const CSlicedPolygons2D & iSlicedPolygons);
	const CSlicedPolygons2D	operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CSlicedPolygons2D	operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CSlicedPolygons2D	operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CSlicedPolygons2D & iSlicedPolygons) const;
	const BOOL				operator != (const CSlicedPolygons2D & iSlicedPolygons) const;
	CSlicedPolygon2D &		operator [] (const UINT iIndex);
#pragma endregion

#pragma region Static Functions
public:
	static void				GetLayerThickness(const list<const CSlicedPolygons2D *> & iSlicedPolygonsList, vector<DOUBLE> & oLayerThickness);
#pragma endregion

#pragma region Memeber Variable
protected:
#pragma endregion
};

	}
}