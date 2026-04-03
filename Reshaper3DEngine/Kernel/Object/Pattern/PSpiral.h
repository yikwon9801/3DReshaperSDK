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
			RsDEFINE_CLASS(CGSpiral2D);
		}

		namespace Pattern
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPSpiral) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPSpiral();
	CPSpiral(const CGSpiral2D & iSpiral);
	CPSpiral(const CPSpiral & iSpiral);
	virtual ~CPSpiral();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGSpiral2D &	GetSpiral2D() const { return m_Spiral; }
public:
	inline void				SetCircle2D(const CGSpiral2D & iSpiral) { m_Spiral = iSpiral; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPSpiral & iSpiral) const;
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
	virtual CPSpiral *		Clone() const;
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
	const CPSpiral &		operator = (const CPSpiral & iSpiral);
	const CPSpiral			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPSpiral			operator - () const;
	const CPSpiral			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPSpiral			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPSpiral			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPSpiral & iSpiral) const;
	const BOOL				operator != (const CPSpiral & iSpiral) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGSpiral2D				m_Spiral;
#pragma endregion
};

		}
	}
}