#pragma once

namespace Kernel
{
	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPolygons2D);
		}

		namespace Functions
		{
			namespace Polygon2D
			{
				using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CFPolygonsVector2DConnect) : RsINHERITANCE(CFPolygons2DConnect)
{
#pragma region Construction & Destruction
public:
	CFPolygonsVector2DConnect(CGPolygons2D & ioPolygons2D);
	virtual ~CFPolygonsVector2DConnect();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CFPolygonsVector2DConnect *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region General Functions
public:
	const BOOL				IsSatisfied(INT * oECode = NULL) const;
#pragma endregion

#pragma region CAD Functions
public:
	const INT				ChangePositiveDirection(const CVector2D & iDirection);
	const INT				ChangeVector2DOrdering(const CVector2D iDirection);

	const INT				ConnectVectorOverlapped(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet());
	const UINT				RemoveOverlapped(const DOUBLE iAccuracy);
#pragma endregion

#pragma region Memeber Variable
#pragma endregion
};

			}
		}
	}
}