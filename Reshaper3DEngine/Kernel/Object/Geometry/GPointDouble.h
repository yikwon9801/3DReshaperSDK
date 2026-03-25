#pragma once

namespace tinyxml2
{
	RsDEFINE_CLASS(XMLElement);
}

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
		RsDEFINE_CLASS(CMemoryStreamRead);
		RsDEFINE_CLASS(CMemoryStreamWrite);

		namespace LightXML
		{
			RsDEFINE_CLASS(CLightXmlDocument);
		}
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector2D);
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

			RsDEFINE_CLASS(CGVertex);

			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;
			using namespace tinyxml2;
			using namespace Kernel::File::LightXML;


RsDEFINE_DLL_CLASS(CGPointDouble) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGPointDouble();
	CGPointDouble(const CPoint & iPoint);
	CGPointDouble(const CGPoint2DDouble & iPoint);
	CGPointDouble(const Coordinate2D & iCoordinate);
	CGPointDouble(const CGPointDouble & iPoint);
	CGPointDouble(const CGVertex & iVertex);
	CGPointDouble(const DOUBLE iPoint[]);
	CGPointDouble(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	CGPointDouble(const DOUBLE iX, const DOUBLE iY);
	virtual ~CGPointDouble();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetX() const	{ return _xx; }
	inline const DOUBLE		GetY() const	{ return _yy; }
	inline const DOUBLE		GetZ() const	{ return _zz; }
	inline void				Get(DOUBLE Coordinate[]) const { for (INT ii = 0; ii < 3; ii++) Coordinate[ii] = _val[ii]; }
	inline void				Get(INT Coordinate[], const DOUBLE iScale) const { for (INT ii = 0; ii < 3; ii++) Coordinate[ii] = (INT)((_val[ii] * iScale) + .5); }
public:
	inline void				SetX(const DOUBLE iX)	{ _xx = iX; }
	inline void				SetY(const DOUBLE iY)	{ _yy = iY; }
	inline void				SetZ(const DOUBLE iZ)	{ _zz = iZ; }
	inline void				SetCoordinate(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ)	{ _xx = iX;	_yy = iY;	_zz = iZ; }
#pragma endregion

public:
	void					Null();
private:
	void					_Init();

#pragma region Mathematic
public:
	const CGPointDouble		Crossed(const CGPointDouble & iPoint) const;
	const DOUBLE			Dot(const CGPointDouble & iPoint) const;
#pragma endregion

#pragma region CAD Function
public:
	const DOUBLE			GetLength() const;
	const DOUBLE			GetLengthSquare() const;
	const BOOL				InPolyhedron(const CGPolyhedron & iPolyhedron) const;
public:
	const INT				Project(const CGPointDouble & iPointToProject, const CVector & iDirection, const DOUBLE iRadius, CGPointDouble * oProjectedPoint = NULL) const;
	const INT				ProjectToPlane(const CGPointDouble & iPointToProject, const CVector & iDrection, const DOUBLE iRadius, CGPointDouble * oProjectedPoint = NULL) const;

	void					ProjectToPlane(const CVector & iDrection, const CGPointDouble & iCriteria);
protected:
	void					Translate(const CVector & iVector);
	void					Translate(const CVector2D & iVector);
	void					Translate(const DOUBLE dx, const DOUBLE dy, const DOUBLE dz);
#pragma endregion

#pragma region General Function
public:
	const BOOL				IsNull() const;
	const BOOL				IsEqual(const CGPointDouble & iPoint, const DOUBLE iAbsoluteAccuracy = CGPointDouble::AbsoluteAccuracyGet()) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGPointDouble *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;

	virtual const INT		ReadBinSimple(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBinSimple(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const INT		ReadBinSimple(CMemoryStreamRead & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBinSimple(CMemoryStreamWrite & file, CProgress * iProgress = NULL);

	virtual const INT		ReadXmlSimple(CLightXmlDocument & file, tinyxml2::XMLElement* pParentNode, CProgress * iProgress = NULL);
	virtual const INT		SaveXmlSimple(CLightXmlDocument & file, tinyxml2::XMLElement* pParentNode, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPointDouble &	operator = (const CGPoint2DDouble & iPoint);
	const CGPointDouble &	operator = (const CGPointDouble & iPoint);
	const CGPointDouble &	operator = (const CPoint & iPoint);
	const CGPointDouble &	operator = (const CGVertex & iVertex);
	const CGPointDouble		operator + (const DOUBLE iValue) const;
	const CGPointDouble		operator + (const CGPointDouble & iPoint) const;
	const CGPointDouble		operator + (const CVector & iVector) const;
	const CGPointDouble		operator + (const CVector2D & iVector) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CGPointDouble & iPoint);
	void					operator += (const CVector2D & iVector);
	void					operator += (const CVector & iVector);
	const CGPointDouble		operator - () const;
	const CGPointDouble		operator - (const DOUBLE iValue) const;
	const CGPointDouble		operator - (const CGPointDouble & iPoint) const;
	const CGPointDouble		operator - (const CVector & iVector) const;
	const CGPointDouble		operator - (const CVector2D & iVector) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CGPointDouble & iPoint);
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CVector & iVector);
	const CGPointDouble		operator * (const DOUBLE iValue) const;
	const CGPointDouble		operator * (const CMatrix3x3 & iMatrix) const;
	const CGPointDouble		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGPointDouble		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGPointDouble & iPoint) const;
	const BOOL				operator != (const CGPointDouble & iPoint) const;
	const BOOL				operator < (const CGPointDouble & iPoint) const;
	const BOOL				operator <= (const CGPointDouble & iPoint) const;
	const BOOL				operator > (const CGPointDouble & iPoint) const;
	const BOOL				operator >= (const CGPointDouble & iPoint) const;
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		AbsoluteAccuracyGet();
	static const DOUBLE		DistSquare(const CGPointDouble & P1, const CGPointDouble & P2);
	static const DOUBLE		DistSquare2D(const CGPointDouble & P1, const CGPointDouble & P2);
	static const DOUBLE		Distance(const CGPointDouble & P1, const CGPointDouble & P2);
	static const DOUBLE		Distance2D(const CGPointDouble & P1, const CGPointDouble & P2);
#pragma endregion

#pragma region Memeber Variable
protected:
	union  {
		struct { DOUBLE _xx, _yy, _zz; };
		DOUBLE _val[3];
	};
#pragma endregion
};

		}
	}
}