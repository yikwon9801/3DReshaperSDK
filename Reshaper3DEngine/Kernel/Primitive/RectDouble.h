#pragma once

namespace Kernel
{
	namespace Math
	{
		RsDEFINE_CLASS(CVector2D);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGRectangle);
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGMultiLine);
		}
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygon2D);
	}

	namespace Primitive
	{
		using namespace Kernel::Math;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CRectDouble) : RsINHERITANCE(CPrimitive)
{
#pragma region Construction & Destruction
public:
	CRectDouble(const DOUBLE iXPos = 0., const DOUBLE iYPos = 0., const DOUBLE iWidth = 0., const DOUBLE iHeight = 0.);
	CRectDouble(const CRectDouble & iRectDouble);
	CRectDouble(const INT iValue);
	virtual ~CRectDouble();
#pragma endregion
	
#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetXPos() const { return _xPos; }
	inline const DOUBLE		GetYPos() const { return _yPos; }
	inline const DOUBLE		GetWidth() const { return _Width; }
	inline const DOUBLE		GetHeight() const { return _Height; }
	inline void				Init(const DOUBLE iXPos = 0., const DOUBLE iYPos = 0., const DOUBLE iWidth = 0., const DOUBLE iHeight = 0.) { _xPos = iXPos; _yPos = iYPos; _Width = iWidth; _Height = iHeight; }
	inline void				SetXPos(const DOUBLE iPos) { _xPos = iPos; }
	inline void				SetYPos(const DOUBLE iPos) { _yPos = iPos; }
	inline void				SetWidth(const DOUBLE iSize) { _Width = iSize; }
	inline void				SetHeight(const DOUBLE iSize) { _Height = iSize; }
	inline void				Set(const DOUBLE iValues[]) { for (INT ii = 0; ii < 4; ii++) _val[ii] = iValues[ii]; }
	inline void				Get(DOUBLE oValues[]) const { for (INT ii = 0; ii < 4; ii++) oValues[ii] = _val[ii]; }
public:
	void					Get(CGMultiLine & oMultiLine) const;
	void					Get(CGRectangle & oRect) const;
#pragma endregion

#pragma region General Function
public:
	const CGRectangle		GetRectangle2D(const DOUBLE iZ) const;

	CGPolygons2D *			ToPolygons2D() const;
	void					GetPolygons2D(CGPolygons2D & oPolygons) const;
protected:
	const BOOL				IsEqual(const CRectDouble & iRectDouble) const;
#pragma endregion

#pragma region CAD Functions
public:
	void					ExtractPolygons(CGPolygons2D & ioPolygons) const;
	const DOUBLE			Area() const { return _Width * _Height; }
#pragma endregion

#pragma region Abstract fuction of IPrimitive
protected:
	virtual const BOOL		CopyFrom(const CPrimitive & iObjToCopy);
	virtual CRectDouble *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CRectDouble &		operator = (const CRectDouble & iRectDouble);
	const CRectDouble &		operator = (const INT iValue);
	const CRectDouble		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CRectDouble		operator - () const;
	const CRectDouble		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CRectDouble		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CRectDouble		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CRectDouble & iRectDouble) const;
	const BOOL				operator != (const CRectDouble & iRectDouble) const;

#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
protected:
	union {
		struct { DOUBLE _xPos, _yPos, _Width, _Height; };
		DOUBLE _val[4];
	};
#pragma endregion
};



	}
}