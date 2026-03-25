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
			RsDEFINE_CLASS(CGCross2D);
		}

		namespace Pattern
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPPaddyField) : RsINHERITANCE(CPCross)
{
#pragma region Construction & Destruction
public:
	typedef enum
	{
		BOUNDARYTYPE_NONE		= CGCross2D::BOUNDARYTYPE::BOUNDARYTYPE_NONE,
		BOUNDARYTYPE_RECTANGLE	= CGCross2D::BOUNDARYTYPE::BOUNDARYTYPE_RECTANGLE,
		BOUNDARYTYPE_ELLIPSE	= CGCross2D::BOUNDARYTYPE::BOUNDARYTYPE_ELLIPSE,
	}BOUNDARYTYPE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CPPaddyField();
	CPPaddyField(const CGCross2D & iCross2D, const BOUNDARYTYPE iBoundaryType = BOUNDARYTYPE_NONE);
	CPPaddyField(const CPPaddyField & iPaddyField);
	virtual ~CPPaddyField();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CPPaddyField::BOUNDARYTYPE	GetBoundaryType() const { return m_BoundaryType; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPPaddyField & iPaddyField) const;
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
	virtual CPPaddyField *	Clone() const;
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
	const CPPaddyField &	operator = (const CPPaddyField & iPaddyField);
	const CPPaddyField		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPPaddyField		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPPaddyField		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPPaddyField		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPPaddyField & iPaddyField) const;
	const BOOL				operator != (const CPPaddyField & iPaddyField) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	BOUNDARYTYPE			m_BoundaryType;
#pragma endregion
};

		}
	}
}