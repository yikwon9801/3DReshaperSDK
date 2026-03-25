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

RsDEFINE_DLL_CLASS(CDOpenGLDataList) : RsINHERITANCE(CDOpenGLDisplay)
{
#pragma region Construction & Destruction
public:
	CDOpenGLDataList(const CTableArray<CGVertex> & vertices, const CTableArray<CGFace> & faces);
	virtual ~CDOpenGLDataList();
#pragma endregion

#pragma region Setter & Getter function
protected:
	void				SetModified(const BOOL iModified);
	void				SetDone(const BOOL iDone);
private:
	const BOOL			IsModified() const;
	const BOOL			IsDone() const;
#pragma endregion

protected:
	void				Release();
private:
	void				_Release();

protected:
	const BOOL			Init();

#pragma region Display
protected:
	virtual const INT	Display(const UCHAR iOption) const;
#pragma endregion

#pragma region Memeber Variable
private:
	const CTableArray<CGVertex> &	m_Vertices;
	const CTableArray<CGFace> &		m_Faces;

	UINT				m_DataList[2];

	BOOL				m_IsDone;
	BOOL				m_Modified;
#pragma endregion
};

			}
		}
	}
}