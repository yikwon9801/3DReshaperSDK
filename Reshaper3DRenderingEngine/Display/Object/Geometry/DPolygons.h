#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CDOpenGLDisplay);
			}

			using namespace Display::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CDPolygons) : RsINHERITANCE(CDComponent3D)
{
#pragma region Type Definitions
protected:
	typedef vector<COLORREF>	COLORTABLE;
#pragma endregion

#pragma region Construction & Destruction
public:
	CDPolygons();
	CDPolygons(const CGPolygons & iPolygons);
	CDPolygons(CGPolygons * iPolygons, const BOOL iNoDeleteBuffer = FALSE);
	CDPolygons(const CDPolygons & iPolygons);
	virtual ~CDPolygons();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolygons *	GetPolygons() const	{ return m_Polygons; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const UCHAR		GetDisplayMode() const { return m_DisplayMode; }
	inline const BOOL		IsRandomColor() const { return m_ShowRandomColor; }
	inline const BOOL		IsShowTextForIndex() const { return m_ShowText; }
public:
	inline void				SetPolygons(CGPolygons * iPolygons, const BOOL iNoDeleteBuffer = FALSE) { Release(); m_Polygons = iPolygons; m_bNoDeleteBuffer = iNoDeleteBuffer; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
	inline void				SetDisplayMode(const UCHAR iMode) { m_DisplayMode; }
	inline void				SetShowTextForIndex(const BOOL iSet) { m_ShowText = iSet; }
public:
	void					SetRandomColor(const BOOL iSet);
	void					SetPolygons(const CSlicedPolygon & iSlicedPolygon);
#pragma endregion

public:
	void					Release();
private:
	void					ReleasePolygons();
	void					ReleaseOpenGLTable();

protected:
	const BOOL				IsEqual(const CDPolygons & iPolygons) const;

#pragma region GPU Memory
private:
	CDOpenGLDisplay *		_GetRenderObject(const UINT16 iRepres);
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_POINTS,
		REP_MULTILINEWITHPOINTS,
		REP_MULTILINEWITHARROWS,
		REP_LINEANDSPHERE,
	}RepresentationType;

	typedef enum {
		DISPLAYMODE_STANDARD,
		DISPLAYMODE_DOPENGLTABLE,
	}DisplayMode;

	virtual const INT		Display() const;
protected:
	const INT				DisplayLines() const;
	const INT				DisplayLinesStandard() const;
	const INT				DisplayLinesDOpenGLTable() const;
	const INT				DisplayPoints() const;
	const INT				DisplayArrows() const;
	const INT				DisplayLinesWithPoints() const;
	const INT				DisplayLinesWithArrows() const;
	const INT				DisplayLineAndSphere() const;
	const INT				DisplayTextForIndex() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDPolygons *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDPolygons &		operator = (const CDPolygons & iPolygons);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDPolygons & iPolygons) const;
	const BOOL				operator != (const CDPolygons & iPolygons) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CGPolygons *			m_Polygons;
private:
	COLORTABLE				m_ColorTable;
private:
	CDOpenGLDisplay *		m_OpenGLTable;
	BOOL					m_bNoDeleteBuffer;
	DOUBLE					m_LineWidth;
	DOUBLE					m_PointSize;

	BOOL					m_ShowText;
	BOOL					m_ShowRandomColor;
	UCHAR					m_DisplayMode;
#pragma endregion
};

		}
	}
}