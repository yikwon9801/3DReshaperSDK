#pragma once

namespace Display
{

	namespace Object
	{

		namespace Rendering
		{

RsDEFINE_DLL_CLASS(CVBOOpenGLTable)
{
#pragma region Type Definition
public:
	typedef enum
	{
		REP_LINES		,
		REP_TRIANGLES	,
	}RepresentationType;
	template <class _type> struct _InternalDataType
	{
		_InternalDataType() : m_Data(NULL), m_Count(0) {}

		_type *	m_Data;
		UINT	m_Count;
	};
#pragma endregion

#pragma region Construction & Destruction
protected:
	CVBOOpenGLTable();
public:
	virtual ~CVBOOpenGLTable();
#pragma endregion

#pragma region Setter & Getter function
protected:
	inline const BOOL	IsDone() const { return m_IsDone; }
	inline const RepresentationType	GetRepres() const { return m_Repres; }
public:
	inline void			SetRepres(const RepresentationType iRepres) { m_Repres = iRepres; }
	inline void			SetNumberToDraw(const UINT iNumberToDraw) { m_NumberToDraw = iNumberToDraw; }
private:
	inline void			SetDone(const BOOL bSet = TRUE) { m_IsDone = bSet; }
public:
	void				SetVerticesBuffer(const _InternalDataType<FLOAT> iVertices, const BOOL iClone = FALSE);
	void 				SetColorsBuffer(const _InternalDataType<BYTE> iColors, const BOOL iClone = FALSE);
	void				SetColorIdsBuffer(const _InternalDataType<BYTE> iColors, const BOOL iClone = FALSE);
#pragma endregion

#pragma region Display
public:
	virtual const INT	Display(const UCHAR iOption) const;
#pragma endregion

public:
	void				InitVBO();

protected:
	void				ReleaseVBO();

	void				AssignVBO();
	void				AttachVBO();

#pragma region Memeber Variable
private:
	BOOL				m_IsDone;

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

private:
	_InternalDataType<FLOAT>	m_Vertices;
	_InternalDataType<BYTE>		m_Colors;
	_InternalDataType<BYTE>		m_ColorIds;
	RepresentationType			m_Repres;

	UINT						m_NumberToDraw;
#pragma endregion
};

		}
	}
}