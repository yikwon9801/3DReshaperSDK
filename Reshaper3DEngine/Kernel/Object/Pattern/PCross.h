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

RsDEFINE_DLL_CLASS(CPCross) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPCross();
	CPCross(const CGCross2D & iCross2D);
	CPCross(const CPCross & iCross);
	virtual ~CPCross();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCross2D &	GetCross() const { return m_Cross; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPCross & iCross) const;
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
	virtual CPCross *	Clone() const;
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
	const CPCross &			operator = (const CPCross & iCross);
	const CPCross			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPCross			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPCross			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPCross			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPCross & iCross) const;
	const BOOL				operator != (const CPCross & iCross) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGCross2D				m_Cross;
#pragma endregion
};

		}
	}
}