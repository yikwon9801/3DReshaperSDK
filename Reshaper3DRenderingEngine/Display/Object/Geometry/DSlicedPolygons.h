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

RsDEFINE_DLL_CLASS(CDSlicedPolygons) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDSlicedPolygons();
	CDSlicedPolygons(CSlicedPolygons * ioPolygons, const BOOL iClone = TRUE);
	CDSlicedPolygons(const CDSlicedPolygons & iSlicedPolygons);
	virtual ~CDSlicedPolygons();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CSlicedPolygons *	GetSlicedPolygons() const	{ return m_SlicedPolygons; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetSlicedPolygons(const CSlicedPolygons & iSlicedPolygons) { if (!m_SlicedPolygons) return;	*m_SlicedPolygons = iSlicedPolygons; }
	inline void				SetSlicedPolygons(CSlicedPolygons * iSlicedPolygons) { Release();	m_SlicedPolygons = iSlicedPolygons; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
#pragma endregion

public:
	void					Release();
private:
	void					ReleaseSlicedPolygons();
	void					ReleaseOpenGLTable();

#pragma region GPU Memory
private:
	CDOpenGLDisplay *		_GetRenderObject(const UINT16 iRepres);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDSlicedPolygons & iSlicedPolygons) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayLines() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDSlicedPolygons *	Clone() const;
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
	const CDSlicedPolygons &	operator = (const CDSlicedPolygons & iSlicedPolygons);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CDSlicedPolygons & iSlicedPolygons) const;
	const BOOL				operator != (const CDSlicedPolygons & iSlicedPolygons) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CSlicedPolygons *		m_SlicedPolygons;
private:
	CDOpenGLDisplay *		m_OpenGLTable;
	DOUBLE					m_PointSize;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}