#pragma once

namespace Display
{
	namespace Object
	{
		RsDEFINE_CLASS(CDComponent);
	}

	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}
}

namespace GUI
{

	namespace Tool
	{

		using namespace Display::Object;
		using namespace Display::View;

RsDEFINE_DLL_CLASS(CDSceneTool) : RsINHERITANCE(CDComponent)
{
#pragma region Construction & Destruction
protected:
	CDSceneTool(CDOpenGLScene * iScene);
	virtual ~CDSceneTool();
#pragma endregion

#pragma region Setter & Getter function
protected:
	CDOpenGLScene *		GetScene();
#pragma endregion

#pragma region Font
protected:
	const UINT			GetBitMapFontListBase() const;
	const UINT			GetBitMapFontListBaseVertically() const;
	const INT			GetSizeBitMapFontListBase() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

	}
}