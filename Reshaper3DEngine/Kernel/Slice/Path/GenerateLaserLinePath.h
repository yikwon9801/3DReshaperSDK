#pragma once

namespace Kernel
{


	namespace Slice
	{

		namespace Path
		{
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CGenerateLaserLinePath) : RsINHERITANCE(CGenerateLaserPath)
{
#pragma region Construction & Destruction
public:
	CGenerateLaserLinePath(const CGPolygons2D & iPolygons,
		const CGPolygons2D & iPrevPolygons,
		const CGPolygons2D & iNextPolygons,
		const DOUBLE iSpotSize,
		const DOUBLE iOffsetDistanceForDLP,
		const BOOL iUpDownSkinOnlyLaser,
		const UINT iNumberOfInnerPath,
		const DOUBLE iDistanceOfOverlappedOutline,
		const DOUBLE iAngleToRotateLine,
		const DOUBLE iAreaPictureDoesnotDraw,
		const DOUBLE iDistanceToOffsetInnerOutLine,
		const DOUBLE iDensity,
		const BOOL iFullFill,
		const BOOL iZigZag);
	CGenerateLaserLinePath(const CGenerateLaserLinePath & iGLP);
	virtual ~CGenerateLaserLinePath();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPolygons2D &	GetPrevPolygons() const { return m_PrevPolygons; }
	inline const CGPolygons2D &	GetNextPolygons() const { return m_NextPolygons; }
	inline const DOUBLE	GetDistanceOfOverlappedOutline() const { return m_DistanceOfOverlappedOutline; }
	inline const DOUBLE	GetAngleToRotateLine() const { return m_AngleToRotateLine; }
	inline const DOUBLE	GetDistanceToOffsetInnerOutLine() const { return m_DistanceToOffsetInnerOutLine; }
	inline const BOOL	IsFullFill() const { return m_FullFill; }
	inline const BOOL	GetUpDownSkinOnlyLaser() const { return m_UpDownSkinOnlyLaser; }
	inline const BOOL	GetZigZag() const { return m_ZigZag; }
#pragma endregion

#pragma region General Function
protected:
	const INT			MakeLineInfill(const Paths & iPath, const DOUBLE iSpotSize, Paths & oInfillLines, const UINT iType) const;
public:
	virtual void		Execute(CGPolygons2D & oPolygons);
#pragma endregion

#pragma region CAD Function
private:

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGenerateLaserLinePath *	Clone() const;
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGenerateLaserLinePath &	operator = (const CGenerateLaserLinePath & iGLP);
#pragma endregion

#pragma region Memeber Variable
private:
	const CGPolygons2D &	m_PrevPolygons;
	const CGPolygons2D &	m_NextPolygons;
	DOUBLE				m_DistanceOfOverlappedOutline;
	DOUBLE				m_AngleToRotateLine;
	DOUBLE				m_DistanceToOffsetInnerOutLine;
	BOOL				m_FullFill;
	BOOL				m_UpDownSkinOnlyLaser;
	BOOL				m_ZigZag;
#pragma endregion
};

		}
	}
}