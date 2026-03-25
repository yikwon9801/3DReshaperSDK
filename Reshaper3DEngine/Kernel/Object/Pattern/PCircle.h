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
			RsDEFINE_CLASS(CGCircle2D);
		}

		namespace Pattern
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPCircle) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPCircle();
	CPCircle(const CGCircle2D & iCircle);
	CPCircle(const CPCircle & iCircle);
	virtual ~CPCircle();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCircle2D &	GetCircle2D() const { return m_Circle; }
public:
	inline void				SetCircle2D(const CGCircle2D & iCircle) { m_Circle = iCircle; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPCircle & iCircle) const;
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
	virtual CPCircle *		Clone() const;
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
	const CPCircle &		operator = (const CPCircle & iCircle);
	const CPCircle			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPCircle			operator - () const;
	const CPCircle			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPCircle			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPCircle			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPCircle & iCircle) const;
	const BOOL				operator != (const CPCircle & iCircle) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGCircle2D				m_Circle;
#pragma endregion
};

		}
	}
}