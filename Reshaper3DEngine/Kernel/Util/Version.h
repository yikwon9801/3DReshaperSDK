#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);

		using namespace Kernel::File;
		using namespace Kernel::String;

RsDEFINE_DLL_CLASS(CVersion) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CVersion();
	CVersion(const UINT iMajor, const UINT iMinor, const UINT iRevision, const UINT iBuildNumber);
	CVersion(const CVersion & iVersion);
	virtual ~CVersion();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetMajor() const		{ return m_Major; }
	inline const UINT		GetMinor() const		{ return m_Minor; }
	inline const UINT		GetRevision() const		{ return m_Revision; }
	inline const UINT		GetBuildNumber() const	{ return m_BuildNumber; }
public:
	inline void				SetVersion(const UINT iMajor, const UINT iMinor, const UINT iRevision, const UINT iBuildNumber) { m_Major = iMajor; m_Minor = iMinor; m_Revision = iRevision; m_BuildNumber = iBuildNumber; }
#pragma endregion
	void					SetVersion(LPCTSTR iVersion);
	const CString			ToString() const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CVersion *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;

	const INT				ReadBin2(CFileReadObject & file, CProgress * iProgress = NULL);
	const INT				ReadString(CFileReadObject & file, const INT iLength, CProgress * iProgress = NULL);
	const INT				SaveBin2(CFileWriteObject & file, CProgress * iProgress = NULL);

#pragma endregion

#pragma region Operator Declaration
public:
	const CVersion &		operator = (const CVersion & iVersion);
	const BOOL				operator == (const CVersion & iVersion) const;
	const BOOL				operator != (const CVersion & iVersion) const;
	const BOOL				operator < (const CVersion & iVersion) const;
	const BOOL				operator <= (const CVersion & iVersion) const;
	const BOOL				operator > (const CVersion & iVersion) const;
	const BOOL				operator >= (const CVersion & iVersion) const;
#pragma endregion

#pragma region Static Function
public:
	static const CVersion	GetVersion(const CString & iVersion);
	static const INT		GetModuleVersion(const CString & iFileName, CVersion & oFileVersion, CVersion & oProductVersion);
#pragma endregion

#pragma region Memeber Variable
private:
	union  {
		struct { UINT m_Major, m_Minor, m_Revision, m_BuildNumber; };
		UINT m_Val[4];
	};
#pragma endregion
};

	}
}