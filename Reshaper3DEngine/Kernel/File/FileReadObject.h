#pragma once

namespace Kernel
{
	namespace String
	{
		RsDEFINE_CLASS(CHyString);
	}

	namespace File
	{
		RsDEFINE_CLASS(CFileObject);

		using namespace Kernel::String;

RsDEFINE_DLL_CLASS(CFileReadObject) : RsINHERITANCE(CFileObject)
{
#pragma region Construction & Destruction
public:
	CFileReadObject(LPCTSTR iFileName);
	virtual ~CFileReadObject();
#pragma endregion

#pragma region General Function
public:
	CHAR *			Gets(CHAR * oBuffer, const INT iMaxCount);
	const INT		GetRowDatas(vector<std::string> & oRowDatas);

#pragma endregion

#pragma region Operator Declaration
public:
	template <class _type> const INT operator >> (_type & iData)
	{
		ASSERT(File());
		if (!File())	return -2;
		size_t t = fread(&iData, sizeof(_type), 1, File());
		return t == 1 ? 0 : -1;
	}
#pragma endregion

#pragma region Binary Stream Reader with Tag Information
	INT32 Read_U8(OUT UINT8 * value);
	INT32 Read_U16(OUT UINT16 * value);
	INT32 Read_U32(OUT UINT32 * value);
	INT32 Read_U64(OUT UINT64 * value);
	INT32 Read_I8(OUT INT8 * value);
	INT32 Read_I16(OUT INT16 * value);
	INT32 Read_I32(OUT INT32 * value);
	INT32 Read_Float(OUT FLOAT * value);
	INT32 Read_Buff(OUT BYTE * buff, IN UINT32 length);
#pragma endregion
};

	}
}