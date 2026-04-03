#pragma once

#include <vector>
using namespace std;

namespace Kernel
{

	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

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
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
		RsDEFINE_CLASS(CVector);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygon);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDimension);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGRectangle);
			RsDEFINE_CLASS(CGMultiLine);
			RsDEFINE_CLASS(CGTriangle);
			RsDEFINE_CLASS(CGCloud);
		}

		using namespace Kernel;
		using namespace Kernel::Primitive;
		using namespace Kernel::File;
		using namespace Kernel::Collection;
		using namespace Kernel::Util;
		using namespace Kernel::Math;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Slice;

RsDEFINE_DLL_CLASS(CBoundingBox) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CBoundingBox();
	CBoundingBox(const CGPointDouble & iUpper, const CGPointDouble & iLower);
	CBoundingBox(const DOUBLE iMinX, const DOUBLE iMinY, const DOUBLE iMinZ, const DOUBLE iMaxX, const DOUBLE iMaxY, const DOUBLE iMaxZ);
	CBoundingBox(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ);
	CBoundingBox(const CDimension & iDimension);
	CBoundingBox(const CBoundingBox2D & iBoundingBox);
	CBoundingBox(const CBoundingBox & iBoundingBox);
	virtual ~CBoundingBox();
#pragma endregion

#pragma region Setter & Getter function
public:
	template <class _type> inline void	Get(_type oData[]) const { oData[0] = (_type)m_LowerPoint._xx; oData[1] = (_type)m_LowerPoint._yy; oData[2] = (_type)m_LowerPoint._zz; oData[3] = (_type)m_UpperPoint._xx; oData[4] = (_type)m_UpperPoint._yy; oData[5] = (_type)m_UpperPoint._zz; }
	inline const CGPointDouble &	GetUpperPoint() const	{ return m_UpperPoint; }
	inline const CGPointDouble &	GetLowerPoint() const	{ return m_LowerPoint; }
	inline const DOUBLE		MinX() const { return m_LowerPoint._xx; }
	inline const DOUBLE		MinY() const { return m_LowerPoint._yy; }
	inline const DOUBLE		MinZ() const { return m_LowerPoint._zz; }
	inline const DOUBLE		MaxX() const { return m_UpperPoint._xx; }
	inline const DOUBLE		MaxY() const { return m_UpperPoint._yy; }
	inline const DOUBLE		MaxZ() const { return m_UpperPoint._zz; }
	inline const DOUBLE		CenterX() const { return (m_LowerPoint._xx + m_UpperPoint._xx) * .5; }
	inline const DOUBLE		CenterY() const { return (m_LowerPoint._yy + m_UpperPoint._yy) * .5; }
	inline const DOUBLE		CenterZ() const { return (m_LowerPoint._zz + m_UpperPoint._zz) * .5; }
	inline void				SetMinX(const DOUBLE iValue) { m_LowerPoint._xx = iValue; }
	inline void				SetMinY(const DOUBLE iValue) { m_LowerPoint._yy = iValue; }
	inline void				SetMinZ(const DOUBLE iValue) { m_LowerPoint._zz = iValue; }
	inline void				SetMaxX(const DOUBLE iValue) { m_UpperPoint._xx = iValue; }
	inline void				SetMaxY(const DOUBLE iValue) { m_UpperPoint._yy = iValue; }
	inline void				SetMaxZ(const DOUBLE iValue) { m_UpperPoint._zz = iValue; }
	inline void				SetMinMaxX(const DOUBLE iMin, const DOUBLE iMax) { m_LowerPoint._xx = iMin; m_UpperPoint._xx = iMax; }
	inline void				SetMinMaxY(const DOUBLE iMin, const DOUBLE iMax) { m_LowerPoint._yy = iMin; m_UpperPoint._yy = iMax; }
	inline void				SetMinMaxZ(const DOUBLE iMin, const DOUBLE iMax) { m_LowerPoint._zz = iMin; m_UpperPoint._zz = iMax; }
	inline void				SetUpperPoint(const CGPointDouble & iPoint) { m_UpperPoint = iPoint; }
	inline void				SetLowerPoint(const CGPointDouble & iPoint) { m_LowerPoint = iPoint; }
public:
	inline void				Init(const CGPointDouble & iUpper, const CGPointDouble & iLower) { m_UpperPoint = iUpper; m_LowerPoint = iLower; }
	inline void				Init() { m_UpperPoint.SetCoordinate(-DBL_MAX, -DBL_MAX, -DBL_MAX); m_LowerPoint.SetCoordinate(DBL_MAX, DBL_MAX, DBL_MAX); }
public:
	void					Set(const CGTriangle & iTriangle);
	void					Set(const CGPointDouble & iP1, const CGPointDouble & iP2, const CGPointDouble & iP3);
	void					Set(const CGPointDouble & iP1, const CGPointDouble & iP2);
	void					Set(const Coordinate3D & iP1, const Coordinate3D & iP2);
#pragma endregion

#pragma region General Function
public:
	inline const DOUBLE		GetXLength() const { return abs(m_UpperPoint._xx - m_LowerPoint._xx); }
	inline const DOUBLE		GetYLength() const { return abs(m_UpperPoint._yy - m_LowerPoint._yy); }
	inline const DOUBLE		GetZLength() const { return abs(m_UpperPoint._zz - m_LowerPoint._zz); }
public:
	const BOOL				GetPositionToLocate(const CBoundingBox & iBoundingBox, CVector & oTranslation) const;

	const BOOL				IsCalculated() const;
	const BOOL				InBox(const CGPointDouble & iPointToTest) const;
	const BOOL				InBox(const CBoundingBox & iBoundingBox, const BOOL iPosition = FALSE) const;
	const BOOL				InBox2D(const CGPointDouble & iPointToTest) const;
	const BOOL				InBoxSize(const CBoundingBox & iBoundingBox, const BOOL iPosition = FALSE) const;
	const BOOL				InBox2DSize(const CBoundingBox & iBoundingBox, const BOOL iPosition = FALSE) const;
	const BOOL				IsIntersected(const CBoundingBox & iBox, const BOOL iPosition = FALSE) const;
	const BOOL				IsIntersected2D(const CBoundingBox & iBox, const BOOL iPosition = FALSE) const;

	const BOOL				Overlaps(const CBoundingBox & iBoundingBox) const;
	const BOOL				Contains(const CBoundingBox & iBoundingBox) const;
	void					Union(const CBoundingBox & iBoundingBox);
	void					Intersect(const CBoundingBox & iBoundingBox);

	const CRectDouble		ToRectDouble() const;
	const CGRectangle2D		ToRectangle2D() const;
	const CGRectangle		GetBottom() const;
	const CGRectangle		GetTop() const;
	const CGRectangle		GetRectangle2D(const DOUBLE iZ = 0.) const;
	void					GetMultiLine(CGMultiLine & oMultiLine, const DOUBLE iZ = 0.) const;

	const CGPointDouble		GetCeneroid() const;
	const DOUBLE			GetLongestLength() const;

	void					GetCloud(CGCloud & oCloud) const;
protected:
	const BOOL				IsEqual(const CBoundingBox & iBoundingBox) const;
private:
	void 					Get2D(DOUBLE & oLowerX, DOUBLE & oLowerY, DOUBLE & oUpperX, DOUBLE & oUpperY) const;

public:
	virtual const CGPointDouble	GetCenterPoint() const;
protected:
	virtual void			Invert();
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetVolume() const;
	const DOUBLE			GetArea() const;
	void					AddBoundingBox(const CBoundingBox & iBoundingBox);
	void					AddBoundingBox(const CBoundingBox2D & iBoundingBox);
	const BOOL				Nesting2DBoxes(CTableList<CBoundingBox> & ioBoundingBoxes) const;
	const BOOL				IsPossible2D(const CTableList<CBoundingBox> & iBoundingBoxes, const DOUBLE iSpaceBetweenBoxes = 0.) const;
	void					Offset(const DOUBLE iOffsetDistance);
#pragma endregion

#pragma region Nesting
public:
	const BOOL				NestingBoxes2DPlacement(CTableList<CBoundingBox> & ioBoundingBoxes, const DOUBLE iSpaceBetweenBoxes = 0.) const;
private:
	const BOOL				NestingRect2DPlacement(CTableList<CBoundingBox> & ioBoundingBoxes) const;
#pragma endregion

#pragma region Slice
public:
	const BOOL				SectionZPlane(CSlicedPolygon & oSlicedPolygon, const DOUBLE iZ = 0.) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CBoundingBox *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
protected:
	virtual void			CopyFrom(const CDimension & iDimension);
	virtual void			CopyFrom(const CBoundingBox2D & iBoundingBox);
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
	const CBoundingBox &	operator = (const CBoundingBox & iBoundingBox);
	const CBoundingBox &	operator = (const CBoundingBox2D & iBoundingBox);
	const CBoundingBox &	operator = (const CDimension & iDimension);
	const CBoundingBox		operator + (const CBoundingBox & iBoundingBox) const;
	const CBoundingBox		operator + (const CBoundingBox2D & iBoundingBox) const;
	const CBoundingBox		operator + (const CVector & iVector) const;
	void					operator += (const CBoundingBox & iBoundingBox);
	void					operator += (const CBoundingBox2D & iBoundingBox);
	void					operator += (const CVector & iVector);
	const CBoundingBox		operator - () const;
	const CBoundingBox		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CBoundingBox		operator * (const DOUBLE iValue) const;
	const CBoundingBox		operator * (const CMatrix3x3 & iMatrix) const;
	const CBoundingBox		operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CBoundingBox		operator / (const DOUBLE iVvalue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CBoundingBox & iBoundingBox) const;
	const BOOL				operator != (const CBoundingBox & iBoundingBox) const;
#pragma endregion

#pragma region Static fuction
public:
	static const INT		CalculateBoundingBox(const vector<Coordinate2D> & iCoordinates, CBoundingBox & oBoundingBox, CGPoint2DDouble & oCenteroid);
	static const INT		CalculateBoundingBox(const vector<Coordinate3D> & iCoordinates, CBoundingBox & oBoundingBox, CGPointDouble & oCenteroid);
	static const INT		CalculateBoundingBox(const vector<CGVertex> & iVertices, CBoundingBox & oBoundingBox, CGPointDouble & oCenteroid);
	static const INT		CalculateBoundingBox(const CTableArray<CGVertex> & iVertices, CBoundingBox & oBoundingBox, CGPointDouble & oCenteroid);
	static const INT		CalculateBoundingBox(const CTableArray<CGVertex> & iVertices, CBoundingBox & oBoundingBox, const CMatrix3x4 & iMatrix);
	static void				CalculateBoundingBox(const CGPointDouble iPoints[], const UINT iArraySize, CBoundingBox & oBoundingBox, CGPointDouble & oCenteroid);
	static void				CalculateBoundingBoxes(const vector<UINT> & iSeparators, const vector<Coordinate3D> & iCoordinates, vector<CBoundingBox> & oBoundingBoxes);
	static const CVector2D	Get2DVectorToFit(const CBoundingBox & iBoundingBox1, const CBoundingBox & iBoundingBox2);
	static const DOUBLE		GetMarginDistance();
	static const CBoundingBox	Union(const CBoundingBox & iBoundingBox1, const CBoundingBox & iBoundingBox2);
	static const CBoundingBox	Intersect(const CBoundingBox & iBoundingBox1, const CBoundingBox & iBoundingBox2);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_UpperPoint;
	CGPointDouble			m_LowerPoint;
#pragma endregion
};



	}
}