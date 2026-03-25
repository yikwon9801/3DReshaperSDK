#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Object
	{
	
		namespace Print
		{

			using namespace Kernel::File;

RsDEFINE_DLL_CLASS(CPrintCase) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CPrintCase();
	CPrintCase(const CPrintCase & iCase);
	virtual ~CPrintCase();
#pragma endregion

#pragma region Setter & Getter function
public:
public:
#pragma endregion

private:
	void					Release();

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CPrintCase *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CPrintCase &		operator = (const CPrintCase & iCase);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}