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
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CVector);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDimension2D);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPoint2DInt);
			RsDEFINE_CLASS(CGVertex);
			RsDEFINE_CLASS(CGVertex2D);

			using namespace Kernel::File;
			using namespace Kernel::Util;
			using namespace Kernel::Math;
			using namespace tinyxml2;
			using namespace Kernel::File::LightXML;

RsDEFINE_DLL_CLASS(CGPoint2DDouble) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGPoint2DDouble();
	CGPoint2DDouble(const CPoint & iPoint);
	CGPoint2DDouble(const Coordinate2D & iPoint);
	CGPoint2DDouble(const Coordinate3D & iPoint);
	CGPoint2DDouble(const CGPoint2DDouble & iPoint);
	CGPoint2DDouble(const CGPoint2DInt & iPoint);
	CGPoint2DDouble(const CDimension2D & iDimension);
	CGPoint2DDouble(const DOUBLE iPoint[]);
	CGPoint2DDouble(const DOUBLE iPoint);
	CGPoint2DDouble(const INT iPoint);
	CGPoint2DDouble(const DOUBLE iX, const DOUBLE iY);
	CGPoint2DDouble(const CGPointDouble & iPoint);
	CGPoint2DDouble(const CGVertex & iVertex);
	virtual ~CGPoint2DDouble();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetX() const	{ return _xx; }
	inline const DOUBLE		GetY() const	{ return _yy; }
	inline void				Get(Coordinate2D & oCoordinbate) { oCoordinbate._xx = _xx;	oCoordinbate._yy = _yy; }
	inline void				Get(DOUBLE value[]) const {
		for (UINT ii = 0; ii < 2; ii++)
			value[ii] = _val[ii];
	}
	inline const Coordinate2D	ToCooridnate2D() const { return { _xx,_yy }; }
public:
	inline void				SetX(const DOUBLE iX)	{ _xx = iX; }
	inline void				SetY(const DOUBLE iY)	{ _yy = iY; }
	inline void				SetCoordinate(const DOUBLE iX, const DOUBLE iY)	{ _xx = iX;	_yy = iY; }

	void					SetValue(LPCTSTR iString, LPCTSTR iDelimiter);
#pragma endregion

public:
	void					Null();
private:
	void					_Init();

#pragma region Mathematic
public:
#pragma endregion

public:
	const BOOL				IsEqual(const CGPoint2DDouble & iPoint) const;
	const BOOL				IsNull() const;
	const DOUBLE			GetLengthSquare() const;
	const DOUBLE			GetLength() const;
protected:
	void					Translate(const CVector2D & iVector);
	void					Translate(const CVector & iVector);
	void					Translate(const DOUBLE dx, const DOUBLE dy);

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGPoint2DDouble *	Clone() const;
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
	const CGPoint2DDouble &	operator = (const CGPoint2DDouble & iPoint);
	const CGPoint2DDouble & operator = (const CPoint & iPoint);
	const CGPoint2DDouble & operator = (const CGPointDouble & iPoint);
	const CGPoint2DDouble & operator = (const Coordinate2D & iPoint);
	const CGPoint2DDouble & operator = (const Coordinate3D & iPoint);
	const CGPoint2DDouble & operator = (const CGVertex & iVertex);
	const CGPoint2DDouble & operator = (const CDimension2D & iDimension);
	const CGPoint2DDouble	operator + (const DOUBLE iValue) const;
	const CGPoint2DDouble	operator + (const CGPoint2DDouble & iPoint) const;
	const CGPoint2DDouble	operator + (const CVector2D & iVector) const;
	const CGPoint2DDouble	operator + (const CVector & iVector) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CGPoint2DDouble & iPoint);
	void					operator += (const CVector2D & iVector);
	void					operator += (const CVector & iVector);
	const CGPoint2DDouble	operator - () const;
	const CGPoint2DDouble	operator - (const DOUBLE iValue) const;
	const CGPoint2DDouble	operator - (const CGPoint2DDouble & iPoint) const;
	const CGPoint2DDouble	operator - (const CVector2D & iVector) const;
	const CGPoint2DDouble	operator - (const CVector & iVector) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CGPoint2DDouble & iPoint);
	void					operator -= (const CVector2D & iVector);
	void					operator -= (const CVector & iVector);
	const CGPoint2DDouble	operator * (const DOUBLE iValue) const;
	const CGPoint2DDouble	operator * (const CMatrix2x2 & iMatrix) const;
	const CGPoint2DDouble	operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CGPoint2DDouble	operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGPoint2DDouble & iPoint) const;
	const BOOL				operator != (const CGPoint2DDouble & iPoint) const;
	const BOOL				operator < (const CGPoint2DDouble & iPoint) const;
	const BOOL				operator <= (const CGPoint2DDouble & iPoint) const;
	const BOOL				operator > (const CGPoint2DDouble & iPoint) const;
	const BOOL				operator >= (const CGPoint2DDouble & iPoint) const;
#pragma endregion

#pragma region Static fuction
public:
	static const DOUBLE		AbsoluteAccuracyGet();
	static const BOOL		Contain(const DOUBLE iP, const DOUBLE iV1, const DOUBLE iV2);
	static const Coordinate2D	ProjectOnLineYAxis(const Coordinate2D & p, const Coordinate2D & v1, const Coordinate2D & v2, const DOUBLE iAccuracy = 0.);
	static const DOUBLE		DistSquare(const CGPoint2DDouble & P1, const CGPoint2DDouble & P2);
	static const DOUBLE		DistSquare(const DOUBLE iPX1, const DOUBLE iPY1, const DOUBLE iPX2, const DOUBLE iPY2);
	static const DOUBLE		Distance(const CGPoint2DDouble & P1, const CGPoint2DDouble & P2);
	static const DOUBLE		Distance(const DOUBLE iPX1, const DOUBLE iPY1, const DOUBLE iPX2, const DOUBLE iPY2);
	static const DOUBLE		IsLeft(const CGPoint2DDouble & P1, const CGPoint2DDouble & P2, const CGPoint2DDouble & iPointToTest);
	static const DOUBLE		IsLeft(const DOUBLE iP1_X, const DOUBLE iP1_Y, const DOUBLE iP2_X, const DOUBLE iP2_Y, const DOUBLE iP_X, const DOUBLE iP_Y);
#pragma endregion

#pragma region Memeber Variable
protected:
	union  {
		struct { DOUBLE _xx, _yy; };
		DOUBLE _val[2];
	};
#pragma endregion
};

typedef CGPoint2DDouble CGSizeDouble;

		}
	}
}