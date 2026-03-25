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

	namespace Object
	{

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointInt);

			using namespace Kernel::File;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGPoint2DInt) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGPoint2DInt();
	CGPoint2DInt(const INT iX, const INT iY);
	CGPoint2DInt(const CPoint & iPoint);
	CGPoint2DInt(const CGPoint2DInt & iPoint);
	virtual ~CGPoint2DInt();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const INT		GetX() const	{ return _xx; }
	inline const INT		GetY() const	{ return _yy; }
public:
	inline void				SetX(const INT iX)	{ _xx = iX; }
	inline void				SetY(const INT iY)	{ _yy = iY; }
	inline void				SetCoordinate(const INT iX, const INT iY)	{ _xx = iX;	_yy = iY; }
#pragma endregion

public:
	void					Null();
private:
	void					_Init();

#pragma region Mathematic
public:
#pragma endregion

public:
	const BOOL				IsEqual(const CGPoint2DInt & iPoint) const;
	const BOOL				IsNull() const;
protected:
	void					Translate(const INT dx, const INT dy);

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGPoint2DInt *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPoint2DInt &	operator = (const CGPoint2DInt & iPoint);
	const CGPoint2DInt &	operator = (const CPoint & iPoint);
	const CGPoint2DInt &	operator = (const CGPointInt & iPoint);
	const CGPoint2DInt		operator + (const INT iValue) const;
	const CGPoint2DInt		operator + (const CGPoint2DInt & iPoint) const;
	void					operator += (const INT iValue);
	void					operator += (const CGPoint2DInt & iPoint);
	const CGPoint2DInt		operator - () const;
	const CGPoint2DInt		operator - (const INT iValue) const;
	const CGPoint2DInt		operator - (const CGPoint2DInt & iPoint) const;
	void					operator -= (const INT iValue);
	void					operator -= (const CGPoint2DInt & iPoint);
	const CGPoint2DInt		operator * (const INT iValue) const;
	void					operator *= (const INT iValue);
	const CGPoint2DInt		operator / (const INT iValue) const;
	void					operator /= (const INT iValue);
	const BOOL				operator == (const CGPoint2DInt & iPoint) const;
	const BOOL				operator != (const CGPoint2DInt & iPoint) const;
	const BOOL				operator < (const CGPoint2DInt & iPoint) const;
	const BOOL				operator <= (const CGPoint2DInt & iPoint) const;
	const BOOL				operator > (const CGPoint2DInt & iPoint) const;
	const BOOL				operator >= (const CGPoint2DInt & iPoint) const;
#pragma endregion

#pragma region Static fuction
public:
	static const INT64		DistSquare(const CGPoint2DInt& P1, const CGPoint2DInt & P2);
	static const INT64		Distance(const CGPoint2DInt & P1, const CGPoint2DInt & P2);
#pragma endregion

#pragma region Memeber Variable
protected:
	union  {
		struct { INT _xx, _yy; };
		INT _val[2];
	};
#pragma endregion
};

typedef CGPoint2DInt CGSizeInt;

		}
	}
}