#pragma once

namespace Display
{
	
	namespace Object
	{

		namespace Geometry
		{

			namespace Print
			{

RsDEFINE_DLL_CLASS(CDPrintObject) : RsINHERITANCE(CDCombination), RsIMPLEMENT(IKeyObject), RsIMPLEMENT(IEditedData)
{
#pragma region Construction & Destruction
protected:
	CDPrintObject();
	CDPrintObject(LPARAM lParam);
	virtual ~CDPrintObject();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion

#pragma region Memeber Variable
protected:
#pragma endregion
};


			}
		}
	}
}