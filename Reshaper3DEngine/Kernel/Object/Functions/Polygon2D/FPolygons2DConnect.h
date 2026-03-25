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

RsDEFINE_DLL_CLASS(CFPolygons2DConnect) : RsINHERITANCE(CDataObject)
{
#pragma region Construction & Destruction
public:
	CFPolygons2DConnect(CGPolygons2D & ioPolygons2D);
	CFPolygons2DConnect(const CFPolygons2DConnect & iFunction);
	virtual ~CFPolygons2DConnect();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CFPolygons2DConnect *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region General Functions
public:
	const BOOL				IsOnlyVector() const;
#pragma endregion

#pragma region Memeber Variable
protected:
	CGPolygons2D &			m_Polygons2D;
#pragma endregion
};

			}
		}
	}
}