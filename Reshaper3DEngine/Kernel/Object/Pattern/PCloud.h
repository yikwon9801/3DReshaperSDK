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

RsDEFINE_DLL_CLASS(CPCloud) : RsINHERITANCE(CPatternObject)
{
#pragma region Construction & Destruction
public:
	CPCloud();
	CPCloud(const CGCloud2D & iCloud);
	CPCloud(const CPCloud & iCloud);
	virtual ~CPCloud();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGCloud2D &	GetCloud2D() const { return m_Cloud; }
public:
	inline void				SetCloud2D(const CGCloud2D & iCloud) { m_Cloud = iCloud; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPCloud & iCloud) const;
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
	virtual CPCloud *		Clone() const;
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
	const CPCloud &			operator = (const CPCloud & iCloud);
	const CPCloud			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CPCloud			operator - () const;
	const CPCloud			operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CPCloud			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CPCloud			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CPCloud & iCloud) const;
	const BOOL				operator != (const CPCloud & iCloud) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGCloud2D				m_Cloud;
#pragma endregion
};

		}
	}
}