#pragma once

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointInt);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CSlicedSegment) : RsINHERITANCE(CSegment2D)
{
#pragma region Construction & Destruction
public:
	CSlicedSegment();
	CSlicedSegment(const INT iX1, const INT iY1, const INT iX2, const INT iY2, const INT iFaceIndex, const DOUBLE iScale = 1.);
	CSlicedSegment(const CSlicedSegment & iSegment);
	virtual ~CSlicedSegment();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointInt &	GetStartPosition() const { return m_StartPosition; }
	inline const CGPointInt &	GetEndPosition() const { return m_EndPosition; }
	inline const DOUBLE		GetScale() const { return m_Scale; }
	inline const BOOL		IsUsedToChain() const { return m_UseToChain; }
	inline void				SetUseToChain(const BOOL iUseToChain = TRUE) { m_UseToChain = iUseToChain; }
#pragma endregion

public:
	const BOOL				IsEqual(const CSlicedSegment & iSegment) const;

#pragma region Abstract fuction of IDataObject
public:
	virtual CSlicedSegment *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CSlicedSegment &	operator = (const CSlicedSegment & iSegment);
	const BOOL				operator == (const CSlicedSegment & iSegment) const;
	const BOOL				operator != (const CSlicedSegment & iSegment) const;
#pragma endregion

#pragma region Static fuction
#pragma endregion

#pragma region Memeber Variable
public:
	
	CGPointInt				m_StartPosition;
	CGPointInt				m_EndPosition;
private:
	DOUBLE					m_Scale;
	BOOL					m_UseToChain;
#pragma endregion
};

	}
}