#pragma once

#include <list>
#include <vector>
using namespace std;

namespace Kernel
{
	namespace Collection
	{
		template<typename _DataType> class CTableArray;
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGVertex);
			RsDEFINE_CLASS(CGMultiLine2D);
			RsDEFINE_CLASS(CGMultiLine);
		}
	}

	namespace Selection
	{
		using namespace Kernel::Collection;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CSelectionPoint) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	typedef vector<CGPoint2DDouble>	_Point2DVector;
	typedef vector<UINT>			_IndexVector;
	typedef list<UINT>				_IndexList;
#pragma endregion

#pragma region Construction & Destruction
public:
	CSelectionPoint(const CTableArray<CGVertex> & iVertices);
	CSelectionPoint(const CSelectionPoint & iSelectionPoint);
	virtual ~CSelectionPoint();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
protected:
	const BOOL				IsEqual(const CSelectionPoint & iSelectionPoint) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

public:
	const CSelectionPoint::_IndexVector	GetSelectedPoints(const CVector & iDirection, const CGMultiLine & iPolygon) const;
private:
	virtual const BOOL	_IsInLine(const CGPoint2DDouble & iPointToTest, const CGMultiLine2D & iMultiLineToSelect) const = 0;

#pragma region Operator Declaration
public:
	const CSelectionPoint &	operator = (const CSelectionPoint & iSelectionPoint);
	const BOOL				operator == (const CSelectionPoint & iSelectionPoint) const;
	const BOOL				operator != (const CSelectionPoint & iSelectionPoint) const;
#pragma endregion

#pragma region Static Function
public:
	static const INT		PointInPolygon(const Coordinate2D & iPointToTest, vector<Coordinate2D> & iPolygon);
#pragma endregion

#pragma region Memeber Variable
protected:
	const CTableArray<CGVertex> &	m_Vertices;
#pragma endregion
};

	}
}