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
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPolygon2D);
		}

		namespace Pattern
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPPolygon) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPPolygon();
	CPPolygon(const CGPolygon2D & iPolygon);
	CPPolygon(const CPPolygon & iPolygon);
	virtual ~CPPolygon();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolygon2D &	GetPolygon2D() const { return m_Polygon; }
public:
	inline void				SetPolygon2D(const CGPolygon2D & iPolygon) { m_Polygon = iPolygon; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPPolygon & iPolygon) const;
#pragma endregion

#pragma region CAD Functions
public:
#pragma endregion

#pragma region Abstract fuction
protected:
	virtual const BOOL		IsSolidType() const { return m_Polygon.IsClosed(); }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPPolygon *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Abstract fuction of IPatternObject
protected:
	virtual const INT		GetPolygons(CGPolygons2D & oPolygons) const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CPPolygon &		operator = (const CPPolygon & iPolygon);
	const CPPolygon			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPPolygon			operator - () const;
	const CPPolygon			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPPolygon			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPPolygon			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPPolygon & iPolygon) const;
	const BOOL				operator != (const CPPolygon & iPolygon) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGPolygon2D				m_Polygon;
#pragma endregion
};

		}
	}
}