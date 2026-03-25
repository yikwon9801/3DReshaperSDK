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

RsDEFINE_DLL_CLASS(CPLine) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPLine();
	CPLine(const CGLine2D & iLine);
	CPLine(const CPLine & iLine);
	virtual ~CPLine();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGLine2D &	GetLine2D() const { return m_Line; }
public:
	inline void				SetLine2D(const CGLine2D & iLine) { m_Line = iLine; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPLine & iLine) const;
#pragma endregion

#pragma region CAD Functions
public:
#pragma endregion

#pragma region Abstract fuction
protected:
	virtual const BOOL		IsSolidType() const { return FALSE; }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPLine *		Clone() const;
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
	const CPLine &			operator = (const CPLine & iLine);
	const CPLine			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPLine			operator - () const;
	const CPLine			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPLine			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPLine			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPLine & iLine) const;
	const BOOL				operator != (const CPLine & iLine) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGLine2D				m_Line;
#pragma endregion
};

		}
	}
}