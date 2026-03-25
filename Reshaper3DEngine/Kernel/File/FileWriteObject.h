#pragma once

#include "HyDataTagType.h"

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileObject);

RsDEFINE_DLL_CLASS(CFileWriteObject) : RsINHERITANCE(CFileObject)
{
#pragma region Construction & Destruction
public:
	CFileWriteObject(LPCTSTR iFileName);
	virtual ~CFileWriteObject();
#pragma endregion

#pragma region Operator Declaration
public:
	template <class _type> const INT operator << (const _type iData)
	{
		ASSERT(File());
		if (!File())	return -2;
		fwrite(&iData, sizeof(_type), 1, File());
		return 0;
	}
#pragma endregion

#pragma region Binary Stream Writer with Tag Information
public:
	UINT Write_Tag(HyDataTagType tag);
	UINT Write_Buffer(HyDataTagType tag, BYTE * buff, UINT len);
	UINT Write_Byte(HyDataTagType tag, BYTE bValue);
	UINT Write_Uint(HyDataTagType tag, UINT uValue);
	UINT Write_Int(HyDataTagType tag, INT nValue);
	UINT Write_Float(HyDataTagType tag, FLOAT fValue);
	UINT Write_Float(HyDataTagType tag, FLOAT fValue[], UINT len);
	UINT Write_UINT64(HyDataTagType tag, UINT64 lValue);
	UINT Write_String(HyDataTagType tag, LPCTSTR iString);

	void Update_Marked_Position(UINT64 lMarkdPos, UINT64 lCurrentPosition);
	void UpdatePosition(UINT64 lMarkdPos, UINT64 lCurrentPosition);
#pragma endregion
};

	}
}