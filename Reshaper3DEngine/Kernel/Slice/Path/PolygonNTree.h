#pragma once

namespace Kernel
{
	namespace Slice
	{
		namespace Path
		{
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPolygonNTree)
{
public:
	typedef struct __pathitem
	{
		__pathitem() : nItem(0) {}
		UINT	nItem;
		Paths	path;
	}PathItem;
	typedef vector<PathItem>			MultiPathItems;
	typedef vector<MultiPathItems>		MultiMultiPathItems;
	typedef vector<Paths>				MultiPaths;
	typedef vector<MultiPaths>			OutlinePaths;
	typedef list<CPolygonNTreeNode>		_ChildNodes;

#pragma region Construction & Destruction
public:
	CPolygonNTree(OutlinePaths & iOutlines, const UINT8 iContainType = 0);
	CPolygonNTree(MultiMultiPathItems & iOutlines, const UINT8 iContainType = 0);
	virtual ~CPolygonNTree();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
public:
	const INT				Get(Paths & oResult, const BOOL iClose = FALSE) const;

	void					ShortestPaths(const IntPoint iDeparture = IntPoint());
private:
	void					BestPathHighestNode(const IntPoint iDeparture);

	void					_InsertTreeNodes(MultiPaths & iMultiLine, CPolygonNTreeNode & ioRoot, const UINT8 iContainType);
	void					_InsertTreeNodes(MultiPathItems & iMultiLine, CPolygonNTreeNode & ioRoot, const UINT8 iContainType);
	CPolygonNTreeNode *		_CreateNode(Kernel::Path * iPath, const BOOL iClosed = TRUE);
	void					_Regist(OutlinePaths & iOutlines, const UINT8 iContainType);
	void					_Regist(MultiMultiPathItems & iOutlines, const UINT8 iContainType);
#pragma endregion

#pragma region CAD Function
private:

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
#pragma endregion

#pragma region Operator Declaration
public:
#pragma endregion

#pragma region Static fuctions
public:
	static void				BestPaths(Paths & ioPaths);
#pragma endregion

#pragma region Memeber Variable
private:
	_ChildNodes				m_Childs;
	CPolygonNTreeNode		m_Root;
#pragma endregion
};

		}
	}
}