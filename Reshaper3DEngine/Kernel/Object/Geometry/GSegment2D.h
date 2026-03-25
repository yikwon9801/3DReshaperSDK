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
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CGSegment2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGSegment2D(const DOUBLE iX1, const DOUBLE iY1, const DOUBLE iX2, const DOUBLE iY2);
	CGSegment2D(const CGSegment2D & iSegment);
	virtual ~CGSegment2D();
protected:
	CGSegment2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetDeparture() const { return m_Departure; }
	inline const CGPoint2DDouble &	GetArrival() const { return m_Arrival; }
	inline void				SetDeparture(const CGPoint2DDouble & iDeparture) { m_Departure = iDeparture; }
	inline void				SetArrival(const CGPoint2DDouble & iArrival) { m_Arrival = iArrival; }
#pragma endregion

protected:
	const BOOL				IsEqual(const CGSegment2D & iSegment) const;

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CGSegment2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGSegment2D &		operator = (const CGSegment2D & iSegment);
	const CGSegment2D		operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGSegment2D		operator - () const;
	const CGSegment2D		operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGSegment2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGSegment2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGSegment2D & iSegment) const;
	const BOOL				operator != (const CGSegment2D & iSegment) const;
#pragma endregion

#pragma region Static fuction
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_Departure;
	CGPoint2DDouble			m_Arrival;
#pragma endregion
};

	}
}