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

RsDEFINE_DLL_CLASS(CDPolygons2D) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDPolygons2D();
	CDPolygons2D(const CGPolygons2D & iPolygons);
	CDPolygons2D(CGPolygons2D * iPolygons, const BOOL iNoDeleteBuffer = FALSE);
	CDPolygons2D(const CDPolygons2D & iPolygons);
	virtual ~CDPolygons2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolygons2D *	GetPolygons() const	{ return m_Polygons; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
public:
	inline void				SetPolygons(CGPolygons2D * iPolygons, const BOOL iNoDeleteBuffer = FALSE) { Release(); m_Polygons = iPolygons; m_bNoDeleteBuffer = iNoDeleteBuffer; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
public:
	void					SetPolygons(const CSlicedPolygon & iSlicedPolygon);
#pragma endregion

public:
	void					Release();
private:
	void					ReleasePolygons();
	void					ReleaseOpenGLTable();

protected:
	const BOOL				IsEqual(const CDPolygons2D & iPolygons) const;

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
		REP_LINEANDSPHERE,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayLines() const;
	const INT				DisplayPoints() const;
	const INT				DisplayLinesWithPoints() const;
	const INT				DisplayLineAndSphere() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDPolygons2D *	Clone() const;
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
	const CDPolygons2D &	operator = (const CDPolygons2D & iPolygons);
	void					operator += (const CVector2D & iVector);
	void					operator -= (const CVector2D & iVector);
	const BOOL				operator == (const CDPolygons2D & iPolygons) const;
	const BOOL				operator != (const CDPolygons2D & iPolygons) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CGPolygons2D *			m_Polygons;
private:
	CDOpenGLDisplay *		m_OpenGLTable;
	BOOL					m_bNoDeleteBuffer;
	DOUBLE					m_LineWidth;
	DOUBLE					m_PointSize;
#pragma endregion
};

		}
	}
}