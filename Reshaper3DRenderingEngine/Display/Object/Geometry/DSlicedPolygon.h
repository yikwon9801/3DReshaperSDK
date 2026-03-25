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

RsDEFINE_DLL_CLASS(CDSlicedPolygon) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDSlicedPolygon();
	CDSlicedPolygon(CSlicedPolygon * ioPolygon, const BOOL iClone = TRUE);
	CDSlicedPolygon(const CDSlicedPolygon & iSlicedPolygon);
	virtual ~CDSlicedPolygon();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CSlicedPolygon *	GetSlicedPolygon() const	{ return m_SlicedPolygon; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
	inline CMatrix3x4		GetLocalMatrix() const { return m_LocalMatrix; }
public:
	inline void				SetSlicedPolygon(const CSlicedPolygon & iSlicedPolygon) { if (!m_SlicedPolygon) return;	*m_SlicedPolygon = iSlicedPolygon; }
	inline void				SetSlicedPolygon(CSlicedPolygon * iSlicedPolygon) { Release();	m_SlicedPolygon = iSlicedPolygon; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
	inline void				SetTranslationToLocalMatrix(const CVector & iTranslation) { m_LocalMatrix.InitTranslation(iTranslation); }
#pragma endregion

public:
	void					Release();
private:
	void					ReleaseSlicedPolygon();
	void					ReleaseOpenGLTable();

#pragma region GPU Memory
private:
	CDOpenGLDisplay *		_GetRenderObject(const UINT16 iRepres);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDSlicedPolygon & iSlicedPolygons) const;

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
	virtual CDSlicedPolygon *	Clone() const;
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
	const CDSlicedPolygon &	operator = (const CDSlicedPolygon & iSlicedPolygon);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CDSlicedPolygon & iSlicedPolygon) const;
	const BOOL				operator != (const CDSlicedPolygon & iSlicedPolygon) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CSlicedPolygon *		m_SlicedPolygon;
	CMatrix3x4				m_LocalMatrix;
private:
	CDOpenGLDisplay *		m_OpenGLTable;
	DOUBLE					m_PointSize;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}