#pragma once

namespace Display
{
	namespace Object
	{
		namespace Vision
		{
			RsDEFINE_CLASS(CDCamera);
		}
	}

	namespace View
	{
		using namespace Display::Object::Vision;

RsDEFINE_DLL_CLASS(CDScene) : RsINHERITANCE(CDOpenGLScene)
{
#pragma region Construction & Destruction
public:
	CDScene();
	virtual ~CDScene();
#pragma endregion
};

	}
}