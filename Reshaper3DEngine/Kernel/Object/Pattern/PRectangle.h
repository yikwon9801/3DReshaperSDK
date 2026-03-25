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

RsDEFINE_DLL_CLASS(CPRectangle) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPRectangle();
	CPRectangle(const CGRectangle2D & iRectangle);
	CPRectangle(const CPRectangle & iRectangle);
	virtual ~CPRectangle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGRectangle2D &	GetRectangle2D() const { return m_Rectangle; }
public:
	inline void				SetRectangle2D(const CGRectangle2D & iRectangle) { m_Rectangle = iRectangle; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPRectangle & iRectangle) const;
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
	virtual CPRectangle *	Clone() const;
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
	const CPRectangle &		operator = (const CPRectangle & iRectangle);
	const CPRectangle		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPRectangle		operator - () const;
	const CPRectangle		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPRectangle		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPRectangle		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPRectangle & iRectangle) const;
	const BOOL				operator != (const CPRectangle & iRectangle) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGRectangle2D			m_Rectangle;
#pragma endregion
};

		}
	}
}