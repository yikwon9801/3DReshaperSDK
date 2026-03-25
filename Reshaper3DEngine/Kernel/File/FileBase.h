#pragma once

namespace Kernel
{

	namespace File
	{

RsDEFINE_DLL_CLASS(CFileBase)
{
public:
	typedef enum{ OpenMode_ReadBinary, OpenMode_ReadAscii, OpenMode_WriteBinary, OpenMode_WriteAscii }OpenMode;

#pragma region Construction & Destruction
protected:
	CFileBase(LPCTSTR iFileName, const OpenMode iMode);
	virtual ~CFileBase();
#pragma endregion

#pragma region Setter & Getter function
protected:
	const CString		GetFileName() const;
	const CFileBase::OpenMode		GetMode() const;
	const BOOL			IsMode(const OpenMode iModeToCheck) const;
	const BOOL			IsRead() const;
	const BOOL			IsWrite() const;
	const BOOL			IsBinary() const;
	const BOOL			IsAscii() const;
#pragma endregion

protected:
	void				Close();

public:
	typedef enum {
		FILETYPE_UNKNOWN,
		FILETYPE_STL,
		FILETYPE_HVS,
		FILETYPE_SLC,
		FILETYPE_HYSLC,
		FILETYPE_HYJOB,
		FILETYPE_MAGICS_JOB,
		FILETYPE_XML,
		FILETYPE_COUNT,
	}FILETYPE;
protected:
	const INT OpenFile(const LPCTSTR iFileName, const OpenMode iMode);

#pragma region Static Function
public:
	static const CFileBase::FILETYPE	GetFileType(LPCTSTR iFileName);
	static const CString	GetCompletedPath(LPCTSTR iFileName, LPCTSTR iExtend);
	static const CString	GetExtend(const FILETYPE iType, const BOOL iExtendDot = FALSE);
	static void			Initialize();
#pragma endregion

#pragma region Memeber Variable
protected:
	FILE *				m_fp;
	static CString		m_Extend[FILETYPE_COUNT];

private:
	CString				m_FileName;
	OpenMode			m_Mode;
#pragma endregion
};

	}
}