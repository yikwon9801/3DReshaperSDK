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

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedSegment);
	}

	namespace Object
	{

		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGFace);
			}

			RsDEFINE_CLASS(CGVertex);

			using namespace Kernel::File;
			using namespace Kernel::Util;
			using namespace Kernel::Object::Geometry::Mesh;
			using namespace Kernel::Slice;

RsDEFINE_DLL_CLASS(CGPointInt) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGPointInt();
	CGPointInt(const INT iX, const INT iY, const INT iZ = 0);
	CGPointInt(const CPoint & iPoint);
	CGPointInt(const CGPointInt & iPoint);
	virtual ~CGPointInt();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const INT		GetX() const	{ return _xx; }
	inline const INT		GetY() const	{ return _yy; }
	inline const INT		GetZ() const	{ return _zz; }
public:
	inline void				SetX(const INT iX)	{ _xx = iX; }
	inline void				SetY(const INT iY)	{ _yy = iY; }
	inline void				SetZ(const INT iZ)	{ _zz = iZ; }
	inline void				SetCoordinate(const INT iX, const INT iY, const INT iZ = 0) { _xx = iX;	_yy = iY; _zz = iZ; }
#pragma endregion

public:
	void					Null();
private:
	void					_Init();

#pragma region Mathematic
public:
#pragma endregion

public:
	const BOOL				IsEqual(const CGPointInt & iPoint) const;
	const BOOL				IsNull() const;

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGPointInt *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPointInt &		operator = (const CGPointInt & iPoint);
	const CGPointInt &		operator = (const CPoint & iPoint);
	const BOOL				operator == (const CGPointInt & iPoint) const;
	const BOOL				operator != (const CGPointInt & iPoint) const;
	const BOOL				operator < (const CGPointInt & iPoint) const;
	const BOOL				operator <= (const CGPointInt & iPoint) const;
	const BOOL				operator > (const CGPointInt & iPoint) const;
	const BOOL				operator >= (const CGPointInt & iPoint) const;
#pragma endregion

#pragma region Static fuction
public:
	static const INT64		DistSquare(const CGPointInt& P1, const CGPointInt & P2);
	static const INT64		Distance(const CGPointInt & P1, const CGPointInt & P2);
	static void				GetZRange(const CGPointInt & P1, const CGPointInt & P2, const CGPointInt & P3, INT & oMinZ, INT & oMaxZ);
	static const INT64		Length2DSquare(const INT iX, const INT iY);
	static const INT64		Length2D(const INT iX, const INT iY);
	static const BOOL		IsShorter(const INT iX, const INT iY, const INT iLength);
	static const BOOL		IsLonger(const INT iX, const INT iY, const INT iLength);
#pragma endregion

#pragma region Memeber Variable
protected:
	union  {
		struct { INT _xx, _yy, _zz; };
		INT _val[3];
	};
#pragma endregion
};

		}
	}
}