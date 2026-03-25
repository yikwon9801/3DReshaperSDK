#pragma once

#include <unordered_map>
using namespace std;

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
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
	}

	namespace Object
	{

		namespace Geometry
		{

			namespace Mesh
			{
				RsDEFINE_CLASS(CGFace);
				RsDEFINE_CLASS(CGPolyhedron);

				using namespace Kernel::File;
				using namespace Kernel::Math;
				using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CTopoStructForPolyhedron)
{
#pragma region Type Definition
private:
	typedef vector<INT32>	_VertexVector;
	typedef unordered_map<INT64, _VertexVector>	_VertexMapVector;
#pragma endregion

#pragma region Construction & Destruction
public:
	CTopoStructForPolyhedron(CTableArray<CGVertex> & ioTableVertex, CTableArray<CGFace> & ioTableFace);
	virtual ~CTopoStructForPolyhedron();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Execution
public:
	void						Execute(CProgress * iProgress = NULL);
	void						ExecuteBinarySTL(FILE * ifp, CProgress * iProgress = NULL);
	void						ExecuteASCIISTL(FILE * ifp, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Geometry
private:
	const INT					_FindVertexIndex(const CGVertex & iVertex);
	const INT					_FindFaceIndex(const INT iIndex1, const INT iIndex2, const INT iExceptFace);
	const INT					_AddFace(const CGVertex & v1, const CGVertex & v2, const CGVertex & v3, const CVector * const n = NULL);
	void						_PutGeometry();
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	_VertexMapVector			m_VertexMap;
	UINT						m_nRealCountOfVertex;
	UINT						m_nRealCountOfFace;

private:
	CTableArray<CGFace>			m_TmpTableFace;
	CTableArray<CGVertex>		m_TmpTableVertex;

	CTableArray<CGFace>	&		m_TableFace;
	CTableArray<CGVertex> &		m_TableVertex;
#pragma endregion
};

			}
		}
	}
}