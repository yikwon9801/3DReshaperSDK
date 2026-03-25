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

			RsDEFINE_CLASS(CGPointDouble);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CGVertex) : RsINHERITANCE(CGPointDouble)
{
	friend class CGPolyhedron;
#pragma region Type Definition
public:
	typedef vector<UINT>	_AdjacentFacesVector;
	typedef enum
	{
		VertexAttribute_None	= 0x00,
		VertexAttribute_Select	= 0x01,
	}VERTEXATTRIBUTE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGVertex();
	CGVertex(const CGPoint2DDouble & iPoint);
	CGVertex(const CGPointDouble & iPoint);
	CGVertex(const Coordinate2D & iPoint);
	CGVertex(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	CGVertex(const DOUBLE iX, const DOUBLE iY);
	CGVertex(const CGVertex & rhs);
	virtual ~CGVertex();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CVector &	GetNormal() const { return m_Normal; }
public:
	inline void				SetVertex(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) { SetCoordinate(iX, iY, iZ); }
	inline void				SetNormal(const CVector & iNormal) { m_Normal = iNormal; }
	inline void				SetNormal(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) { m_Normal.SetCoordinate(iX, iY, iZ); }
	inline void				SetAttribute(const UINT16 iAttri) { m_Attribute = iAttri; }
#pragma endregion

#pragma region Mathematic
public:
	void					AddAdjacentFace(const UINT iIndexOfFace);
	void					GetAdjacentFaces(_AdjacentFacesVector & oAdjacentFaces) const;
protected:
	void					ReleaseInternal();
#pragma endregion

#pragma region Mathematic
public:
	const CGVertex			Crossed(const CGVertex & iVertex) const;
	const DOUBLE			Dot(const CGVertex & iVertex) const;
#pragma endregion

#pragma region General Function
public:
	void					AddNormal(const CVector & iNormal);
	void					AddNormal(const DOUBLE iNormal[]);

	void					InvertNormal()	{ m_Normal.Invert(); }

public:
	void					Null();
protected:
	const BOOL				IsEqual(const CGVertex & iVertex) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGVertex *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGVertex &		operator = (const CGVertex & iVertex);
	const CGVertex &		operator = (const CGPoint2DDouble & iPoint);
	const CGVertex &		operator = (const CGPointDouble & iPoint);
	const CGVertex &		operator = (const Coordinate2D & iPoint);
	const CGVertex			operator + (const CVector & iVector) const;
	const CGVertex			operator + (const CVector2D & iVector) const;
	const CGVertex			operator + (const CGVertex & iVertex) const;
	void					operator += (const CVector & iVector);
	void					operator += (const CVector2D & iVector);
	void					operator += (const CGVertex & iVertex);
	const CGVertex			operator - () const;
	const CGVertex			operator - (const CVector & iVector) const;
	const CGVertex			operator - (const CVector2D & iVector) const;
	const CGVertex			operator - (const CGVertex & iVertex) const;
	void					operator -= (const CVector & iVector);
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CGVertex & iVertex);
	const CGVertex			operator * (const DOUBLE iValue) const;
	const CGVertex			operator * (const CMatrix3x3 & iMatrix) const;
	const CGVertex			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGVertex			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGVertex & iVertex) const;
	const BOOL				operator != (const CGVertex & iVertex) const;
#pragma endregion

#pragma region Memeber Variable
private:
	CVector					m_Normal;
	UINT16					m_Attribute;

private:
	struct Internal;
	Internal *				m_Internal;
#pragma endregion
};

		}
	}
}