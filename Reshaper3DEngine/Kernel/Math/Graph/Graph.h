#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Math
	{
		namespace Graph
		{
			using namespace Kernel::File;

RsDEFINE_DLL_CLASS(CGraph) : RsINHERITANCE(CMath)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
protected:
	CGraph();
	virtual ~CGraph();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CGraph & iGraph) const;
#pragma endregion

#pragma region Mathematic
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGraph &			operator = (const CGraph & iGraph);
	const BOOL				operator == (const CGraph & iGraph) const;
	const BOOL				operator != (const CGraph & iGraph) const;
#pragma endregion

#pragma region Static Function
public:
	static const INT		TravllingSalesmanProblem(const vector<vector<INT>> & graph, const UINT V, const UINT s, vector<INT> & vertex);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};
		}
	}
}