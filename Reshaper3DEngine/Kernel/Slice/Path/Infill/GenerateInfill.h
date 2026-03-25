#pragma once

namespace Kernel
{

	namespace Slice
	{

		namespace Path
		{

			namespace Infill
			{

				using namespace Kernel::Object;
				using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CGenerateInfill) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	enum PathOrder
	{
		PathOrder_ZigZig			,
		PathOrder_ZigZag			,
		PathOrder_OptimizedSorting	,
	};
	enum FillType
	{
		FillType_Line,
		FillType_Offset,
		FillType_Cross,
	};
	enum HatchSortingType
	{
		HatchSortingType_None,
		HatchSortingType_Direction
	};
	struct GenParam
	{
		GenParam(const FillType iFillType = FillType_Line
				, const DOUBLE iDistance = 0.
				, const UINT iNumberOfOutline = 0
				, const DOUBLE iAngle = 0.
				, const PathOrder iOrder = PathOrder_ZigZig
				, const BOOL iSeparate = TRUE
				, const DOUBLE iShiftDistance = 0
				, const HatchSortingType iHatchSortingType = HatchSortingType_None
				, const DOUBLE iHatchSortingAngle = 0.)
			: m_FillType(iFillType)
			, m_Distance(iDistance)
			, m_ShiftDistance(iShiftDistance)
			, m_NumberOfOutline(iNumberOfOutline)
			, m_Angle(iAngle)
			, m_Order(iOrder)
			, m_Separate(iSeparate)
			, m_HatchSortingType(iHatchSortingType)
			, m_HatchSortingAngle(iHatchSortingAngle)
		{}
		FillType			m_FillType;
		DOUBLE				m_Distance;
		DOUBLE				m_ShiftDistance;
		UINT				m_NumberOfOutline;
		DOUBLE				m_Angle;
		BOOL				m_Separate;
		HatchSortingType	m_HatchSortingType;
		DOUBLE				m_HatchSortingAngle;
		PathOrder			m_Order;
	};
	typedef vector<Paths>				MultiPaths;
	typedef vector<MultiPaths>			MultiMultiPaths;
#pragma endregion

#pragma region Construction & Destruction
public:
	CGenerateInfill(const CGPolygons2D & iPolygons);
	CGenerateInfill(const CGenerateInfill & iInfill);
	virtual ~CGenerateInfill();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const FillType	GetFillType() const { return m_Parameter.m_FillType; }
	inline const DOUBLE		GetDistance() const { return m_Parameter.m_Distance; }
	inline const DOUBLE		GetShiftDistance() const { return m_Parameter.m_ShiftDistance; }
	inline const UINT		GetNumberOfOutline() const { return m_Parameter.m_NumberOfOutline; }
	inline const DOUBLE		GetAngle() const { return m_Parameter.m_Angle; }
	inline const PathOrder	GetOrder() const { return m_Parameter.m_Order; }
	inline const BOOL		IsSeparate() const { return m_Parameter.m_Separate; }
public:
	inline void				SetFillType(const FillType iFillType) { m_Parameter.m_FillType = iFillType; }
	inline void				SetDistance(const DOUBLE iDistance) { m_Parameter.m_Distance = iDistance; }
	inline void				SetNumberOfOutline(const UINT iNumber) { m_Parameter.m_NumberOfOutline = iNumber; }
	inline void				SetAngle(const DOUBLE iAngle) { m_Parameter.m_Angle = iAngle; }
	inline void				SetOrder(const PathOrder iOrder) { m_Parameter.m_Order = iOrder; }
	inline void				SetSeparate(const BOOL iSeparate) { m_Parameter.m_Separate = iSeparate; }
	inline void				SetGenParam(const GenParam & iParamer) { m_Parameter = iParamer; }

#pragma endregion

#pragma region General Function
public:
	const INT				MakeLineInfill(const Paths & iPath, const DOUBLE iDistance, const DOUBLE iShiftDistance, const DOUBLE iAngle, Paths & oInfillLines, const UINT iType) const;
protected:
	const INT				MakeLineInfill(const Paths & iPath, const DOUBLE iDistance, const DOUBLE iShiftDistance, Paths & oInfillLines, const UINT iType, const UINT8 iSortingOrder = 0) const;
public:
	virtual void			Execute(CGPolygons2D & oPolygons);
protected:
	void					ExecuteFillLine(CGPolygons2D & oPolygons);
	void					ExecuteFillOffset(CGPolygons2D & oPolygons);
	void					ExecuteFillCross(CGPolygons2D & oPolygons);

private:
	const BOOL				IsReverse(const DOUBLE iDirectionAngle, const DOUBLE iOrderingAngle) const;
#pragma endregion

#pragma region CAD Function
private:

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGenerateInfill *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CGenerateInfill &	operator = (const CGenerateInfill & iInfill);
#pragma endregion

#pragma region Static fuction
public:
	static void				GetOffsetPaths(MultiPaths & ioPaths, const DOUBLE iSpotSize, const UINT iNumberOfOffset, const UINT8 iOffsetType);
	static void				GetOffsetPaths(CPolygonNTree::MultiPathItems & ioPaths, const DOUBLE iSpotSize, const UINT iNumberOfOffset, const UINT8 iOffsetType);
	static const INT		GetOffsetPaths(const Paths & iPaths, MultiPaths & ioPaths, const DOUBLE iSpotSize, const UINT8 iOffsetType);
	static void				GetOffsetPaths(const Paths & iPaths, const DOUBLE iDistance, const UINT8 iOffsetType, Paths & oPaths);
#pragma endregion

#pragma region Memeber Variable
protected:
	const CGPolygons2D &	m_SrcPolygons;
private:
	GenParam				m_Parameter;
#pragma endregion
};

			}
		}
	}
}