#pragma once

#include <vector>
using namespace std;

namespace Kernel
{

	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
		RsDEFINE_CLASS(CMemoryStreamRead);
		RsDEFINE_CLASS(CMemoryStreamWrite);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableList;
		template<typename _DataType> class CTableArray;
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
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygon);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDimension2D);
		RsDEFINE_CLASS(CDimension);
		RsDEFINE_CLASS(CBoundingBox);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPolygon2D);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGCloud);
			RsDEFINE_CLASS(CGRectangle2D);
			RsDEFINE_CLASS(CGRectangle);
		}

		using namespace Kernel;
		using namespace Kernel::File;
		using namespace Kernel::Collection;
		using namespace Kernel::Util;
		using namespace Kernel::Math;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Slice;

RsDEFINE_DLL_CLASS(CBoundingBox2D) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CBoundingBox2D();
	CBoundingBox2D(const CGPoint2DDouble & iUpper, const CGPoint2DDouble & iLower);
	CBoundingBox2D(const DOUBLE iMinX, const DOUBLE iMinY, const DOUBLE iMaxX, const DOUBLE iMaxY);
	CBoundingBox2D(const DOUBLE iX, const DOUBLE iY);
	CBoundingBox2D(const CGPoint2DDouble & iOrgin, const CDimension2D & iDimension);
	CBoundingBox2D(const CDimension2D & iDimension);
	CBoundingBox2D(const CDimension & iDimension);
	CBoundingBox2D(const CBoundingBox2D & iBoundingBox);
	CBoundingBox2D(const CBoundingBox & iBoundingBox);
	virtual ~CBoundingBox2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetUpperPoint() const	{ return m_UpperPoint; }
	inline const CGPoint2DDouble &	GetLowerPoint() const	{ return m_LowerPoint; }
	inline const DOUBLE		MinX() const { return m_LowerPoint._xx; }
	inline const DOUBLE		MinY() const { return m_LowerPoint._yy; }
	inline const DOUBLE		MaxX() const { return m_UpperPoint._xx; }
	inline const DOUBLE		MaxY() const { return m_UpperPoint._yy; }
	inline void				SetMinX(const DOUBLE iValue) { m_LowerPoint._xx = iValue; }
	inline void				SetMinY(const DOUBLE iValue) { m_LowerPoint._yy = iValue; }
	inline void				SetMaxX(const DOUBLE iValue) { m_UpperPoint._xx = iValue; }
	inline void				SetMaxY(const DOUBLE iValue) { m_UpperPoint._yy = iValue; }
	inline void				Get(FLOAT oData[]) const { oData[0] = (FLOAT)m_LowerPoint._xx; oData[1] = (FLOAT)m_LowerPoint._yy; oData[2] = (FLOAT)m_UpperPoint._xx; oData[3] = (FLOAT)m_UpperPoint._yy; }
	void					SetValue(LPCTSTR iString, LPCTSTR iDelimiter);
	void					Set(const CGPoint2DDouble & iOrgin, const CDimension2D & iDimension);
	void					Get(const UINT iIndex, CGPoint2DDouble & oPoint1, CGPoint2DDouble & oPoint2) const;
	void					Get(const UINT iIndex, Coordinate2D & oPoint1, Coordinate2D & oPoint2) const;
	void					Get(const UINT iIndex, DOUBLE & oPX1, DOUBLE & oPY1, DOUBLE & oPX2, DOUBLE & oPY2) const;

public:
	inline void				Init(const CGPoint2DDouble & iUpper, const CGPoint2DDouble & iLower) { m_UpperPoint = iUpper; m_LowerPoint = iLower; }
	inline void				Init(const DOUBLE iMinX, const DOUBLE iMinY, const DOUBLE iMaxX, const DOUBLE iMaxY) { m_UpperPoint.SetCoordinate(iMaxX, iMaxY);; m_LowerPoint.SetCoordinate(iMinX, iMinY); }
	inline void				Init() { m_UpperPoint.SetCoordinate(-DBL_MAX, -DBL_MAX); m_LowerPoint.SetCoordinate(DBL_MAX, DBL_MAX); }
#pragma endregion

#pragma region General Function
public:
	inline const DOUBLE		GetXLength() const { return abs(m_UpperPoint._xx - m_LowerPoint._xx); }
	inline const DOUBLE		GetYLength() const { return abs(m_UpperPoint._yy - m_LowerPoint._yy); }
public:
	void					AddPoint(const Coordinate2D & iPoint);
public:
	const BOOL				IsCalculated() const;
	void					AddBoundingBox(const CBoundingBox2D & iBoundingBox);

	const DOUBLE			GetRadius() const;
	void					ToMultiLine(CGMultiLine & oMultiLine) const;
	void					ToPolygons2D(CGPolygons2D & oPolygons2D) const;

	const CGRectangle		GetRectangle(const DOUBLE iZ = 0.) const;
	const CGRectangle2D		GetRectangle2D() const;
	void					GetVerticalLine(Coordinate2D & oP1, Coordinate2D & oP2, const CBoundingBox2D * iLimit = NULL) const;
	void					GetHorizontalLine(Coordinate2D & oP1, Coordinate2D & oP2, const CBoundingBox2D * iLimit = NULL) const;
	void					GetCrossLine(Coordinate2D & oVertP1, Coordinate2D & oVertP2, Coordinate2D & oHorzP1, Coordinate2D & oHorzP2, const CBoundingBox2D * iLimit = NULL) const;

	const CGPoint2DDouble	GetCeneroid() const;
	const BOOL				Contain(const CGPoint2DDouble & iPointToCheck) const;
	const BOOL				Contains(const CBoundingBox2D & iBoundingBox) const;

	const BOOL				IsIntersected(const CBoundingBox2D & iBox) const;
protected:
	const BOOL				IsEqual(const CBoundingBox2D & iBoundingBox) const;

public:
	virtual const CGPoint2DDouble	GetCenterPoint() const;
protected:
	virtual void			Invert();
#pragma endregion

#pragma region CAD Functions
public:
	inline void				Offset(const DOUBLE iLength) { m_LowerPoint -= iLength; m_UpperPoint += iLength; }
	void					Intersect(const CBoundingBox2D & iBoundingBox);
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	const BOOL				CopyFrom(const CGPoint2DDouble & iOrgin, const CDimension2D & iDimension);
	const BOOL				CopyFrom(const CDimension2D & iDimension);
	const BOOL				CopyFrom(const CDimension & iDimension);

	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CBoundingBox2D *	Clone() const;
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
#pragma endregion

#pragma region Operator Declaration
public:
	const CBoundingBox2D &	operator = (const CBoundingBox2D & iBoundingBox);
	const CBoundingBox2D &	operator = (const CDimension2D & iDimension);
	const CBoundingBox2D &	operator = (const CDimension & iDimension);
	const CBoundingBox2D	operator + (const CBoundingBox2D & iBoundingBox) const;
	const CBoundingBox2D	operator + (const CVector2D & iVector) const;
	void					operator += (const CBoundingBox2D & iBoundingBox);
	void					operator += (const CVector2D & iVector);
	const CBoundingBox2D	operator - () const;
	const CBoundingBox2D	operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CBoundingBox2D	operator * (const DOUBLE iValue) const;
	const CBoundingBox2D	operator * (const CMatrix2x2 & iMatrix) const;
	const CBoundingBox2D	operator * (const CMatrix2x3 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix2x2 & iMatrix);
	void					operator *= (const CMatrix2x3 & iMatrix);
	const CBoundingBox2D	operator / (const DOUBLE iVvalue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CBoundingBox2D & iBoundingBox) const;
	const BOOL				operator != (const CBoundingBox2D & iBoundingBox) const;
	const CBoundingBox2D	operator ^ (const CBoundingBox2D & iBoundingBox) const;
	void					operator ^= (const CBoundingBox2D & iBoundingBox);
#pragma endregion

#pragma region Static fuction
public:
	static void				CalculateBoundingBox(const vector<Coordinate2D> & iCoordinates, CBoundingBox2D & oBoundingBox, CGPoint2DDouble & oCenteroid);
	static void				CalculateBoundingBox(const vector<CGPoint2DDouble> & iPoints, CBoundingBox2D & oBoundingBox, CGPoint2DDouble & oCenteroid);
	static void				CalculateBoundingBox(const CTableArray<CGVertex2D> & iPoints, CBoundingBox2D & oBoundingBox, CGPoint2DDouble & oCenteroid);
	static void				CalculateBoundingBox(const CGPoint2DDouble iPoints[], const UINT iArraySize, CBoundingBox2D & oBoundingBox, CGPoint2DDouble & oCenteroid);
	static void				CalculateBoundingBoxes(const vector<UINT> & iSeparators, const vector<Coordinate2D> & iCoordinates, vector<CBoundingBox2D> & oBoundingBoxes);
	static const CVector2D	Get2DVectorToFit(const CBoundingBox2D & iBoundingBox1, const CBoundingBox2D & iBoundingBox2);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_UpperPoint;
	CGPoint2DDouble			m_LowerPoint;
#pragma endregion
};



	}
}