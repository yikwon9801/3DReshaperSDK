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

RsDEFINE_DLL_CLASS(CGPipe) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGPipe();
	CGPipe(const CGPointDouble & iPoint, const CVector & iDirection, const DOUBLE iHorRadius, const DOUBLE iVerRadius, const DOUBLE iHeight);
	CGPipe(const CGPipe & iPipe);
	virtual ~CGPipe();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPoint() const { return m_Point; }
	inline const CVector &	GetDirection() const { return m_Direction; }
	inline const DOUBLE		GetHorRadius() const { return m_HorRadius; }
	inline const DOUBLE		GetVerRadius() const { return m_VerRadius; }
	inline const DOUBLE		GetHeight() const { return m_Height; }
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CGPipe & iPipe) const;

public:
	CGPolyhedron *			Reconstruct() const;
	const CGPolyhedron *	GetGeometry() const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetVolume() const;
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
	virtual CGPipe *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPipe &			operator = (const CGPipe & iPipe);
	const CGPipe			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGPipe			operator - () const;
	const CGPipe			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const BOOL				operator == (const CGPipe & iPipe) const;
	const BOOL				operator != (const CGPipe & iPipe) const;
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
	DOUBLE					m_HorRadius;
	DOUBLE					m_VerRadius;
#pragma endregion
};

		}
	}
}