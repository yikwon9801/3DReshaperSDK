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
			RsDEFINE_CLASS(CGEllipse2D);
		}

		namespace Pattern
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPEllipse) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPEllipse();
	CPEllipse(const CGEllipse2D & iEllipse);
	CPEllipse(const CPEllipse & iEllipse);
	virtual ~CPEllipse();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGEllipse2D &	GetEllipse2D() const { return m_Ellipse; }
public:
	inline void				SetEllipse2D(const CGEllipse2D & iEllipse) { m_Ellipse = iEllipse; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPEllipse & iEllipse) const;
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
	virtual CPEllipse *		Clone() const;
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
	const CPEllipse &		operator = (const CPEllipse & iEllipse);
	const CPEllipse			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPEllipse			operator - () const;
	const CPEllipse			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPEllipse			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPEllipse			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPEllipse & iEllipse) const;
	const BOOL				operator != (const CPEllipse & iEllipse) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGEllipse2D				m_Ellipse;
#pragma endregion
};

		}
	}
}