#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);

RsDEFINE_DLL_CLASS(CDViewObject) : RsINHERITANCE(CDObject)
{
#pragma region Construction & Destruction
protected:
	CDViewObject();
	CDViewObject(CDOpenGLScene * iScene);
	virtual ~CDViewObject();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline void				SetScene(CDOpenGLScene * ioScene) { m_Scene = ioScene; }
protected:
	inline CDOpenGLScene *	GetScene() { return m_Scene; }
#pragma endregion

protected:
	const UINT				GetBitMapFontListBase() const;
	const UINT				GetBitMapFontListBaseVertically() const;
	const INT				GetSizeBitMapFontListBase() const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file);
	virtual const INT		SaveBin(CFileWriteObject & file);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Memeber Variable
private:
	CDOpenGLScene *			m_Scene;
#pragma endregion
};

	}
}