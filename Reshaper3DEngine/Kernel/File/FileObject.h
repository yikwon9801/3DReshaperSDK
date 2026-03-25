#pragma once

#include "../Reshaper3DDefine.h"

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(IFileObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace File
	{
		using namespace Kernel::Interface;
		using namespace Kernel::Util;

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

RsDEFINE_DLL_CLASS(CFileObject)
{
public:
	typedef enum{ OpenMode_ReadBinary, OpenMode_WriteBinary }OpenMode;

#pragma region Construction & Destruction
protected:
	CFileObject(LPCTSTR iFileName, const OpenMode iMode);
public:
	virtual ~CFileObject();
#pragma endregion

public:
	const CString		GetFileName() const;
	const BOOL			IsReady() const;
	const BOOL			IsEOF() { return (BOOL)feof(File()); }
	const CFileObject::OpenMode	GetOpenMode() const;
	const UINT64		GetCurrentPosition() { return _ftelli64(File()); }
	const INT			SetPosition(UINT64 pos);
public:
	const INT			ReadManagedObj(IFileObject * obj, CProgress * iProgress = NULL);
	const INT			ReadString(CString & oString);
	const INT			ReadString(CString & readString, UINT32 length);
	const INT			ReadByte(void * objToRead, const UINT64 nScale, const UINT nCount = 1);

	const INT			WriteManagedObj(IFileObject * obj, CProgress * iProgress = NULL);
	const INT			WriteString(const CString & iString);
	const INT			WriteString(const CString & iString, const BOOL iCR);
	const INT			WriteByte(void * objToWrite, const UINT64 nScale, const UINT nCount = 1);
	const UINT64		GetFileSize();
protected:
	FILE *				File();

public:
	static const BOOL	IsFileExist(LPCTSTR iFileName);
	static const vector<CString> GetFilesInFolder(LPCTSTR iDirectory, LPCTSTR iFilter, const BOOL bRecursive = TRUE);
	static const INT	GetFilesInFolder(LPCTSTR iDirectory, list<CString> & olistFiles);
	static const BOOL	GetFilesInFolder(LPCTSTR iDirectory, vector<CString>& oFiles, vector<CString>& oDirectories, const BOOL iRecusive = TRUE, const BOOL iOnlyName = FALSE);
	static const INT	CopyFolder(const CString To, const CString From);
	static const CString	ExtractFileName(const CString iFileName, const UINT iType);
	static const BOOL	DeleteFile(const CString iFileName);
	static const BOOL	DeleteDirectory(LPCTSTR iDirectory);
	static const BOOL	DeleteDirectoriesContainsInDirectory(const CString iDirectory, const CString iContainsText);
	static BOOL			CreateDirectory(const CString iPath);
	static const CString	NewFileName(const CString iFileName, const UINT16 iType);
	static const BOOL	LoadCreatedTime(LPCTSTR iFileName, CTime & oTime);
#pragma region Memeber Variable
private:
	struct Internal;
	Internal *			m_Internal;
#pragma endregion
};

	}
}