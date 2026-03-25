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
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CGCube) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGCube();
	CGCube(const CGRectangle & iUpper, const CGRectangle & iLower);
	CGCube(const CGCube & rhs);
	virtual ~CGCube();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGRectangle &	GetUpper() const	{ return m_Upper; }
	inline const CGRectangle &	GetLower() const	{ return m_Lower; }
	void					Get(CGPointDouble oPoint[]) const;
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CGCube & iCube) const;
#pragma endregion

#pragma region CAD Functions
public:
	CGPolyhedron *			Reconstruct() const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGCube *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGCube &			operator = (const CGCube & iCube);
	const CGCube			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGCube			operator - () const;
	const CGCube			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGCube			operator * (const DOUBLE iValue) const;
	const CGCube			operator * (const CMatrix3x3 & iMatrix) const;
	const CGCube			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGCube			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGCube & iCube) const;
	const BOOL				operator != (const CGCube & iCube) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CGRectangle				m_Upper, m_Lower;
#pragma endregion
};

		}
	}
}