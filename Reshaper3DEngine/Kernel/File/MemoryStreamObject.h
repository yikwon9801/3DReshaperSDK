#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace File
	{
		using namespace Kernel::Util;
		/*
#pragma region Macro
#define FILEERROR_NOTEOB								-5
#define FILEERROR_HIGHERCURRENTVERSION					-3
#define	BEGIN_FILEREADBASE(file)											\
	INT version = -1;														\
	file >> version;														\
	if (version>currentVersion)	return FILEERROR_HIGHERCURRENTVERSION;		\
	INT ret = 0;								
#define BEGIN_FILEREAD(file,parentClass)									\
	BEGIN_FILEREADBASE(file)												\
	if (ret = parentClass::ReadBin(file))									\
		return ret;
#define BEGIN_FILEREADWITHPROGRESS(file,parentClass,iProgress)				\
	BEGIN_FILEREADBASE(file)												\
	if (ret = parentClass::ReadBin(file, iProgress))						\
		return ret;
#define END_FILEREAD(file)													\
	INT Block = -1;															\
	file >> Block;															\
	if (Block != BLOCKTYPE_EOB)												\
		return FILEERROR_NOTEOB;
#define BEGIN_FILEWRITEBASE(file)											\
	file << (INT)currentVersion;											\
	INT ret = 0;								
#define BEGIN_FILEWRITE(file,parentClass)									\
	BEGIN_FILEWRITEBASE(file)												\
	if (ret = parentClass::SaveBin(file))									\
		return ret;
#define BEGIN_FILEWRITEWITHPROGRESS(file,parentClass,iProgress)				\
	BEGIN_FILEWRITEBASE(file)												\
	if (ret = parentClass::SaveBin(file, iProgress))						\
		return ret;
#define END_FILEWRITE(file)													\
	file << (INT)BLOCKTYPE_EOB;

#define FileReadManagedObj(file,objToRead,progress)		file.ReadManagedObj(dynamic_cast<IFileObject *>(&objToRead),progress)
#define FileRead(file,objToRead,scale,count)			file.ReadByte(objToRead,scale,count)
#define FileReadString(file,str)						file.ReadString(str)
#define FileReadStringWithLength(file,str,len)					file.ReadString(str, len)
#define FileWriteManagedObj(file,objToWrite,progress)	file.WriteManagedObj(dynamic_cast<IFileObject *>(&objToWrite),progress)
#define FileWrite(file,objToWrite,scale,count)			file.WriteByte(objToWrite,scale,count)
#define FileWriteString(file,str)						file.WriteString(str)
#pragma endregion
*/
RsDEFINE_DLL_CLASS(CMemoryStreamObject)
{
public:
	typedef enum{ OpenMode_ReadBinary, OpenMode_WriteBinary }OpenMode;

#pragma region Construction & Destruction
protected:
	CMemoryStreamObject(BYTE iStreamBuffer[], const OpenMode iMode);
public:
	virtual ~CMemoryStreamObject();
#pragma endregion

public:
	const UINT64		GetSize() const;
	const BOOL			IsReady() const;
	const CMemoryStreamObject::OpenMode	GetOpenMode() const;
	BYTE *				StreamBuffer();
public:
	const INT			ReadString(CString & oString);
	const INT			ReadByte(BYTE iContents[], const UINT iLength);

	const INT			WriteString(const CString & iString);
	const INT			WriteByte(BYTE iContents[], const UINT iLength);
	void				SetPosition(UINT64 iPos);

#pragma region Memeber Variable
private:
	struct Internal;
	Internal *			m_Internal;
#pragma endregion
};

	}
}