#pragma once

namespace Kernel
{

	namespace Object
	{

RsDEFINE_DLL_CLASS(CResolution) : RsINHERITANCE(CBaseObject)
{
public:
	typedef enum
	{
		RESOLUTIONTYPE_1024x768,
		RESOLUTIONTYPE_1920x1080,
	}RESOLUTIONTYPE;

#pragma region Construction & Destruction
public:
	CResolution(const CResolution::RESOLUTIONTYPE iType);
	CResolution(const CResolution & iResolution);
	virtual ~CResolution();
#pragma endregion

#pragma region Setter & Getter function
	inline const CResolution::RESOLUTIONTYPE	GetType() const	{ return m_Type; }
	const UINT				GetWidth() const;
	const UINT				GetHeight() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CResolution *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CResolution &		operator = (const CResolution & iResolution);
#pragma endregion

public:
	const CString			ToString() const;

#pragma region Static Function
public:
	static const CResolution::RESOLUTIONTYPE	ConvertToEnum(const CString iResolution);
	static const CString	ConvertToString(const CResolution::RESOLUTIONTYPE iResolutionType);
	static void				GetResolution(const CResolution::RESOLUTIONTYPE iResolutionType, UINT & oWidth, UINT & oHeight);
#pragma endregion

#pragma region Memeber Variable
private:
	RESOLUTIONTYPE			m_Type;
#pragma endregion
};

	}
}