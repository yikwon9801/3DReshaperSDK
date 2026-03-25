#pragma once

namespace Kernel
{
	namespace Slice
	{
		namespace Path
		{
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CGenerateLaserOutlinePath) : RsINHERITANCE(CGenerateLaserPath)
{
#pragma region Construction & Destruction
public:
	CGenerateLaserOutlinePath(const CGPolygons2D & iPolygons,
		const DOUBLE iSpotSize,
		const DOUBLE iOffsetDistanceForDLP,
		const UINT iNumberOfInnerPath,
		const DOUBLE iAreaPictureDoesnotDraw,
		const DOUBLE iDensity);
	CGenerateLaserOutlinePath(const CGenerateLaserOutlinePath & iGLP);
	virtual ~CGenerateLaserOutlinePath();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
public:
	void					Execute(CGPolygons2D & oPolygons);
#pragma endregion

#pragma region CAD Function
private:

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGenerateLaserOutlinePath *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGenerateLaserOutlinePath &	operator = (const CGenerateLaserOutlinePath & iGLP);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}