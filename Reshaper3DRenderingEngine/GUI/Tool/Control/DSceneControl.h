#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}
}

namespace GUI
{

	namespace Tool
	{

		namespace Control
		{

			using namespace Display::View;

RsDEFINE_DLL_CLASS(CDSceneControl) : RsINHERITANCE(CDSceneTool)
{
#pragma region Construction & Destruction
protected:
	CDSceneControl(CDOpenGLScene * iScene);
	virtual ~CDSceneControl();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion
};

		}
	}

}