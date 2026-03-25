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

RsDEFINE_DLL_CLASS(CDMultiLines) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDMultiLines();
	CDMultiLines(CGMultiLines * ioMultiLines, const BOOL iClone = TRUE);
	CDMultiLines(const CDMultiLines & iMultiLines);
	virtual ~CDMultiLines();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGMultiLines *	GetMultiLines() const	{ return m_MultiLines; }
	inline const DOUBLE		GetPointSize() const { return m_PointSize; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetMultiLines(const CGMultiLines & iMultiLines) { if (!m_MultiLines) return;	*m_MultiLines = iMultiLines; }
	inline void				SetMultiLines(CGMultiLines * iMultiLines) { Release();	m_MultiLines = iMultiLines; }
	inline void				SetPointSize(const DOUBLE iSize) { m_PointSize = iSize; }
	inline void				SetLineWidth(const DOUBLE iLineWidth) { m_LineWidth = iLineWidth; }
#pragma endregion

public:
	void					Release();
private:
	void					ReleaseMultiLines();
	void					ReleaseOpenGLTable();

#pragma region GPU Memory
private:
	CDOpenGLDisplay *		_GetRenderObject(const UINT16 iRepres);
#pragma endregion

protected:
	const BOOL				IsEqual(const CDMultiLines & iMultiLines) const;

public:
	virtual const CBoundingBox	GetBoundingBox() const;
	virtual const CGPointDouble	GetCenterPoint() const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_POINTS,
		REP_MULTILINESWITHPOINTS,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayLines() const;
	const INT				DisplayPoints() const;
	const INT				DisplayLinesWithPoints() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDMultiLines *	Clone() const;
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
	const CDMultiLines &	operator = (const CDMultiLines & iMultiLines);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CDMultiLines & iMultiLines) const;
	const BOOL				operator != (const CDMultiLines & iMultiLines) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CGMultiLines *			m_MultiLines;
private:
	CDOpenGLDisplay *		m_OpenGLTable;
	DOUBLE					m_PointSize;
	DOUBLE					m_LineWidth;
#pragma endregion
};

		}
	}
}