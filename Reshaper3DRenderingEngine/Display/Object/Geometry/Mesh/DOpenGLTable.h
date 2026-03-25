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

RsDEFINE_DLL_CLASS(CDOpenGLTable) : RsINHERITANCE(CDOpenGLDisplay)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CDOpenGLTable(const CTableArray<CGVertex> & vertices, const CTableArray<CGPoint2DDouble> & textures);
	CDOpenGLTable(const CTableArray<CGVertex *> & vertices, const CTableArray<UINT> & iSeperateVertices);
	CDOpenGLTable(const vector<Coordinate2D> & vertices, const vector<UINT> & iSeperateVertices);
	CDOpenGLTable(const vector<Coordinate2D> & vertices);
	CDOpenGLTable(const CTableArray<CGVertex *> & vertices);
	CDOpenGLTable(const CTableArray<CGVertex> & vertices);
	CDOpenGLTable(const CTableArray<CGVertex> & vertices, const CTableArray<CGFace> & faces, const CGOpenGLTable::DRAWCOLOR iDrawColor, const BOOL iUseNormalOfVertex = FALSE, LPARAM lParam = NULL);
	virtual ~CDOpenGLTable();
#pragma endregion

#pragma region Setter & Getter function
public:
private:
	inline const BOOL	IsDone() const { return m_IsDone; }
	inline void			SetDone(const BOOL bSet = TRUE) { m_IsDone = bSet; }
#pragma endregion

#pragma region Display
protected:
	virtual const INT	Display(const UCHAR iOption) const;
#pragma endregion

protected:
	void				Release();

protected:
	void				Init();
	void				AssignVBO();
	void				AttachVBO();

#pragma region Memeber Variable
private:
	CTableArray<UINT>   m_SeperateVertices;

	BOOL				m_IsDone;
	CGOpenGLTable		m_OpenGLTable;

	enum {
		VBO_VERTEX		= 0 ,
		VBO_NORMAL			,
		VBO_COLOR			,
		VBO_COLORID			,
		VBO_TEXCOORD		,
		VBO_INDEX			,
		VBO_MAX				,
	};
	UINT				m_vbo[VBO_MAX];
#pragma endregion
};

			}
		}
	}
}