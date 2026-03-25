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
			RsDEFINE_CLASS(CGRectangle2D);
		}

		namespace Pattern
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPTriangle) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPTriangle();
	CPTriangle(const CGTriangle2D & iTriangle);
	CPTriangle(const CPTriangle & iTriangle);
	virtual ~CPTriangle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGTriangle2D &	GetTriangle2D() const { return m_Triangle; }
public:
	inline void				SetTriangle2D(const CGTriangle2D & iTriangle) { m_Triangle = iTriangle; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPTriangle & iTriangle) const;
#pragma endregion

#pragma region CAD Functions
public:
#pragma endregion

#pragma region Abstract fuction
protected:
	virtual const BOOL		IsSolidType() const { return TRUE; }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPTriangle *	Clone() const;
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
	const CPTriangle &		operator = (const CPTriangle & iTriangle);
	const CPTriangle		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPTriangle		operator - () const;
	const CPTriangle		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPTriangle		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPTriangle		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPTriangle & iTriangle) const;
	const BOOL				operator != (const CPTriangle & iTriangle) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGTriangle2D			m_Triangle;
#pragma endregion
};

		}
	}
}