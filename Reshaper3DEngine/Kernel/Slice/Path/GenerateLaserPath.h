#pragma once

namespace Kernel
{
	namespace Slice
	{
		namespace Path
		{
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CGenerateLaserPath) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	typedef vector<Paths>				MultiPaths;
	typedef vector<MultiPaths>			MultiMultiPaths;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CGenerateLaserPath(const CGPolygons2D & iPolygons);
	CGenerateLaserPath(const CGPolygons2D & iPolygons,
		const DOUBLE iSpotSize,
		const DOUBLE iOffsetDistanceForDLP,
		const UINT iNumberOfInnerPath,
		const DOUBLE iAreaPictureDoesnotDraw,
		const DOUBLE iDensity);
	CGenerateLaserPath(const CGenerateLaserPath & iGLP);
public:
	virtual ~CGenerateLaserPath();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const UINT		GetNumberOfOutline() const { return m_NumberOfOutline; }
	inline const DOUBLE		GetSpotSize() const { return m_SpotSize; }
	inline const DOUBLE		GetOffsetDistanceForDLP() const { return m_OffsetDistanceForDLP; }
	inline const DOUBLE		GetAreaPictureDoesnotDraw() const { return m_AreaPictureDoesnotDraw; }
	inline const DOUBLE		GetDensity() const { return m_Density; }
protected:
	inline const UINT8		GetOffsetType() const { return m_OffsetType; }
	inline const CGPolygons2D &	GetSrcPolygons() const { return m_SrcPolygons; }
public:
	void					GetPolygons2DExceptFull(CGPolygons2D & oPolygons) const;
#pragma endregion

#pragma region General Function
protected:
	void					Intersect(const Paths & iPaths1, const Paths & iPaths2, Paths & oPaths) const;
public:
	virtual void			Execute(CGPolygons2D & oPolygons) = 0;
#pragma endregion

#pragma region CAD Function
private:

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGenerateLaserPath &	operator = (const CGenerateLaserPath & iGLP);
#pragma endregion

#pragma region Static fuction
public:
	static void				GetOffsetPaths(MultiPaths & ioPaths, const DOUBLE iSpotSize, const UINT iNumberOfOffset, const UINT8 iOffsetType);
	static void				GetOffsetPaths(CPolygonNTree::MultiPathItems & ioPaths, const DOUBLE iSpotSize, const UINT iNumberOfOffset, const UINT8 iOffsetType);
	static const INT		GetOffsetPaths(const Paths & iPaths, MultiPaths & ioPaths, const DOUBLE iSpotSize, const UINT8 iOffsetType);
	static void				GetOffsetPaths(const Paths & iPaths, const DOUBLE iSpotSize, const UINT8 iOffsetType, Paths & oPaths);

	static const DOUBLE		Area(const Paths & iPaths);
#pragma endregion

#pragma region Memeber Variable
protected:
	const CGPolygons2D &	m_SrcPolygons;
	Paths					m_PolygonsExceptFull;
private:
	UINT					m_NumberOfOutline;
	DOUBLE					m_SpotSize;
	DOUBLE					m_OffsetDistanceForDLP;
	DOUBLE					m_AreaPictureDoesnotDraw;
	DOUBLE					m_Density;
	UINT8					m_OffsetType;
#pragma endregion
};

		}
	}
}