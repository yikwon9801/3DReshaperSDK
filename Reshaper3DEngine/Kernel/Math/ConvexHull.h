#pragma once

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CSlicedPolygons2D);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGVertex);
			RsDEFINE_CLASS(CGMultiLine);

			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CQuaternion);

		using namespace Kernel;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Object::Geometry::Mesh;
		using namespace Kernel::Slice;
		using namespace Kernel::Util;
		using namespace Kernel::Collection;

RsDEFINE_DLL_CLASS(CConvexHull) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	CConvexHull(const CTableArray<CGVertex> & iPoints);
	CConvexHull(const CTableArray<CGPolyhedron *> & iPolyhedrons);
	CConvexHull(const CSlicedPolygons2D & iSlicedPolygons);
	CConvexHull(const vector<Coordinate2D> & iPoints);
	CConvexHull(const CConvexHull & iConvexHull);
	virtual ~CConvexHull();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
public:
	const BOOL				GetMultiLine(CGMultiLine & oConvexHull) const;
	const BOOL				Get(vector<Coordinate2D> & oPoints) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CConvexHull *	Clone() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CConvexHull &		operator = (const CConvexHull & iConvexHull);
#pragma endregion

#pragma region Static Function
private:
	struct Internal;
	auto_ptr<Internal>		m_Internal;
#pragma endregion
};

	}
}