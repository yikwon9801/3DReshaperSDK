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

RsDEFINE_DLL_CLASS(CGVertex2D) : RsINHERITANCE(CGPoint2DDouble)
{
	friend class CGPolyhedron;
#pragma region Construction & Destruction
public:
	CGVertex2D();
	CGVertex2D(const DOUBLE iX, const DOUBLE iY);
	CGVertex2D(const CGPoint2DDouble & iPoint);
	CGVertex2D(const CGPointDouble & iPoint);
	CGVertex2D(const CGVertex2D & iVertex);
	virtual ~CGVertex2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	const CVector2D &		GetNormal() const;
public:
	void					SetVertex(const DOUBLE iX, const DOUBLE iY);
	void					SetNormal(const CVector2D & iNormal);
	void					SetNormal(const DOUBLE iX, const DOUBLE iY);
#pragma endregion

#pragma region Mathematic
public:
	const DOUBLE			Dot(const CGVertex2D & iVertex) const;
	const DOUBLE			Cross(const CGVertex2D & iVertex) const;
#pragma endregion

public:
	void					AddNormal(const CVector2D & iNormal);
	void					AddNormal(const DOUBLE iNormal[]);

	void					InvertNormal()	{ m_Normal.Invert(); }

public:
	void					Null();
protected:
	const BOOL				IsEqual(const CGVertex2D & iVertex) const;

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGVertex2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGVertex2D &		operator = (const CGVertex2D & iVertex);
	const CGVertex2D &		operator = (const CGPoint2DDouble & iPoint);
	const CGVertex2D &		operator = (const CGPointDouble & iPoint);
	const CGVertex2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGVertex2D		operator - () const;
	const CGVertex2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGVertex2D		operator * (const DOUBLE iValue) const;
	const CGVertex2D		operator * (const CMatrix2x2 & iMatrix) const;
	const CGVertex2D		operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGVertex2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGVertex2D & iVertex) const;
	const BOOL				operator != (const CGVertex2D & iVertex) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CVector2D				m_Normal;
#pragma endregion
};

		}
	}
}