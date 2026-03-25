#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

			namespace Mesh
			{
				using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CDOpenGLDisplay)
{
#pragma region Type Definition
public:
	typedef enum
	{
		REP_POINTS ,
		REP_LINES ,
		REP_TRIANGLES ,
		REP_SMOOTH_TRIANGLES,
	}RepresentationType;
	typedef enum
	{
		UPDATE_INTERNALDATA_NONE = 0x00,
		UPDATE_INTERNALDATA_VERTEX = 0x01,
		UPDATE_INTERNALDATA_NORMAL = 0x02,
		UPDATE_INTERNALDATA_VERTEXNORMAL = UPDATE_INTERNALDATA_VERTEX | UPDATE_INTERNALDATA_NORMAL,
	}UPDATE_INTERNALDATA;
#pragma endregion

#pragma region Construction & Destruction
public:
	CDOpenGLDisplay(LPARAM lParam = NULL);
	virtual ~CDOpenGLDisplay();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BOOL	IsRepres(const RepresentationType iRepres) const { return m_Repres == iRepres; }
public:
	inline void			AddUpdateInternalData(const UPDATE_INTERNALDATA iUpdate) { m_UpdateInternalData = (UPDATE_INTERNALDATA)((UINT)m_UpdateInternalData | (UINT)iUpdate); }
	inline void			SetUpdateInternalData(const UPDATE_INTERNALDATA iUpdate) { m_UpdateInternalData = iUpdate; }
	inline LPARAM		GetParam() const { return m_lParam; }
protected:
	inline const RepresentationType	GetRepres() const { return m_Repres; }
	inline const BOOL	IsUpdateInternalData(const UPDATE_INTERNALDATA iUpdate) const { return CUtil::IsType(m_UpdateInternalData, iUpdate); }
public:
	inline void			SetRepres(const RepresentationType iRepres) { m_Repres = iRepres; }
#pragma endregion

#pragma region Display
public:
	virtual const INT	Display(const UCHAR iOption) const = 0;
#pragma endregion

#pragma region Memeber Variable
private:
	RepresentationType	m_Repres;
	UPDATE_INTERNALDATA	m_UpdateInternalData;
	LPARAM				m_lParam;
#pragma endregion
};

			}
		}
	}
}