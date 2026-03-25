#pragma once

#include <vector>

using namespace std;

namespace Kernel
{

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Position
	{

		namespace Nesting
		{

			using namespace Kernel::Object;

// -------------------------------------------------------------------------------- 
// Name        : CRect2DPlacement.h 
// Description : A class that allocates subrectangles into power-of-2 rectangles 
//               (C) Copyright 2000-2002 by Javier Arevalo 
//               This code is free to use and modify for all purposes 
// -------------------------------------------------------------------------------- 
// modified to support sprite margins and VC8 
// (C) Copyright 2008 by Haaf 
// -------------------------------------------------------------------------------- 

#define MARGIN_DISTANCE	1

struct TPos
{
	INT x, y;
	TPos() {}
	TPos(const INT iX, const INT iY) : x(iX), y(iY) {}
	const BOOL operator == (const TPos & iPos) const { return x == iPos.x && y == iPos.y; }
};

struct TRect : TPos
{
	INT w, h;
	void * Data;
	TRect() : Data(NULL) {}
	TRect(const TRect & iRect) : TPos(iRect.x, iRect.y), w(iRect.w), h(iRect.h), Data(iRect.Data) {}
	TRect(const INT iX, const INT iY, const INT iW, const INT iH, void * iData = NULL) : TPos(iX, iY), w(iW > 0 ? iW : 0), h(iH > 0 ? iH : 0), Data(iData) {}
	const BOOL Contains(const TPos & iPos) const { return (iPos.x >= x && iPos.y >= y && iPos.x < (x + w) && iPos.y < (y + h)); }
	const BOOL Contains(const TRect & iRect) const { return (iRect.x - MARGIN_DISTANCE >= x && iRect.y - MARGIN_DISTANCE >= y && (iRect.x + iRect.w + MARGIN_DISTANCE) <= (x + w) && (iRect.y + iRect.h + MARGIN_DISTANCE) <= (y + h)); }
	const BOOL Intersect(const TRect & iRect) const { return w > 0 && h > 0 && iRect.w > 0 && iRect.h > 0 && ((iRect.x + iRect.w + MARGIN_DISTANCE) > x && (iRect.x - MARGIN_DISTANCE) < (x + w) && (iRect.y + iRect.h + MARGIN_DISTANCE) > y && (iRect.y - MARGIN_DISTANCE) < (y + h)); }
	static const BOOL Greater(const TRect & iRect1, const TRect & iRect2) {	return (iRect1.w > iRect2.w && iRect1.w > iRect2.h) || (iRect1.h > iRect2.w && iRect1.h > iRect2.h); }
	const TRect & operator = (const TRect & iRect) { if (this == &iRect) return *this;	x = iRect.x; y = iRect.y; w = iRect.w; h = iRect.h; Data = iRect.Data;	return *this; }
};

RsDEFINE_DLL_CLASS(CRect2DPlacement) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	typedef vector<TPos>  PosArray;
	typedef vector<TRect> RectArray;
#pragma endregion

#pragma region Construction & Destruction
public:
	CRect2DPlacement();
	CRect2DPlacement(const INT iW, const INT iH);
	CRect2DPlacement(const CRect2DPlacement & iPlacement);
	virtual ~CRect2DPlacement();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BOOL		IsOk() const { return m_Size.w > 0; }
	inline const INT		GetW() const { return m_Size.w; }
	inline const INT		GetH() const { return m_Size.h; }
	inline const LONG		GetArea() const { return m_Area; }
	inline const LONG		GetTotalArea() const { return m_Size.w * m_Size.h; }
	inline const RectArray &	GetRects() const { return m_Rects; }
#pragma endregion

public:
	void					Init(const INT iW = 1, const INT iH = 1);
	void					End();

	const BOOL				AddAtEmptySpotAutoGrow(const TRect & iRect, const INT iMaxW, const INT iMaxH);

private:
	const BOOL				IsFree(const TRect & iRect) const;
	void					AddPosition(const TPos & iPos);
	void					AddRect(const TRect & iRect);
	const BOOL				AddAtEmptySpot(const TRect & iRect);

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CRect2DPlacement *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CRect2DPlacement &	operator = (const CRect2DPlacement & iPlacement);
#pragma endregion

#pragma region Memeber Variable
private:
	TRect					m_Size;
	RectArray				m_Rects;
	PosArray				m_Positions;
	LONG					m_Area;
#pragma endregion
};

		}
	}
}