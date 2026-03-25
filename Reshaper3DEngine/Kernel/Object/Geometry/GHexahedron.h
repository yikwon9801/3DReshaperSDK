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

	namespace Object
	{
		namespace Geometry
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGHexahedron) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGHexahedron();
	CGHexahedron(const CGRectangle & iRectangle, const CVector & iDirection, const DOUBLE iHeight);
	CGHexahedron(const CBoundingBox & iBoundingBox);
	CGHexahedron(const CGHexahedron & iHexahedron);
	virtual ~CGHexahedron();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGRectangle &	GetRectangle() const { return m_Rectangle; }
	inline const CVector &	GetDirection() const { return m_Direction; }
	inline const DOUBLE		GetHeight() const { return m_Height; }
public:
	void					Get(CGPointDouble oPoint[]) const;
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CGHexahedron & iHexahedron) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Function
public:
	const DOUBLE			GetVolume() const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGHexahedron *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGHexahedron &	operator = (const CGHexahedron & iCube);
	const CGHexahedron		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGHexahedron		operator - () const;
	const CGHexahedron		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGHexahedron		operator * (const DOUBLE iValue) const;
	const CGHexahedron		operator * (const CMatrix3x3 & iMatrix) const;
	const CGHexahedron		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGHexahedron		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGHexahedron & iHexahedron) const;
	const BOOL				operator != (const CGHexahedron & iHexahedron) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGRectangle				m_Rectangle;
	CVector					m_Direction;
	DOUBLE					m_Height;
#pragma endregion
};

		}
	}
}