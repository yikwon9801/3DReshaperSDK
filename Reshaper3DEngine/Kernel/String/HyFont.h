#pragma once

#include <list>
#include <vector>

using namespace std;

namespace Kernel
{

	namespace String
	{

RsDEFINE_DLL_CLASS(CHyFont) : RsINHERITANCE(CFont)
{
public:
	struct __Font {
		CString		FullPath;
		CString		Name;
		CString		Family;
		LONG		FaceIndex;
	};
	typedef map<CString, __Font>	FontTtfList;
#pragma region Construction & Destruction
public:
	CHyFont();
	virtual ~CHyFont();
#pragma endregion

#pragma region Operator Declaration
#pragma endregion

#pragma region Static Function
public:
	static const INT			ObtainAllTTFFileList(FontTtfList & oFontTtfList);
#pragma endregion
};

	}
}