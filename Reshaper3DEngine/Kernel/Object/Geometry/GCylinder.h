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

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygon);
	}

	namespace Object
	{
		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;
			using namespace Kernel::Slice;

RsDEFINE_DLL_CLASS(CGCylinder) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGCylinder();
	CGCylinder(const CGPointDouble & iPoint, const CVector & iDirection, const DOUBLE iRadius, const DOUBLE iHeight);
	CGCylinder(const CGCylinder & iCylinder);
	virtual ~CGCylinder();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPoint() const { return m_Point; }
	inline const CVector &	GetDirection() const { return m_Direction; }
	inline const DOUBLE		GetRadius() const { return m_Radius; }
	inline const DOUBLE		GetHeight() const { return m_Height; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CGCylinder & iCylinder) const;
#pragma endregion

#pragma region CAD Functions
public:
	CGPolyhedron *			Reconstruct() const;
	const CGPolyhedron *	GetGeometry() const;
	const DOUBLE			GetVolume() const;
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region Slice
public:
	const BOOL				SectionZPlane(CSlicedPolygon & oSlicedPolygon, const DOUBLE iZ = 0.) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGCylinder *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGCylinder &		operator = (const CGCylinder & iCylinder);
	const CGCylinder		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGCylinder		operator - () const;
	const CGCylinder		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGCylinder		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGCylinder		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCylinder & iCylinder) const;
	const BOOL				operator != (const CGCylinder & iCylinder) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	struct Internal;
	auto_ptr<Internal>		m_Internal;
private:
	CGPointDouble			m_Point;
	CVector					m_Direction;
	DOUBLE					m_Height;
	DOUBLE					m_Radius;
#pragma endregion
};

		}
	}
}