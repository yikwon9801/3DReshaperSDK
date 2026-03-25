#pragma once

#include <vector>
using namespace std;

namespace Kernel
{

	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableList;
		template<typename _DataType> class CTableArray;
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Math
	{
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
		RsDEFINE_CLASS(CVector);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDimension);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGSphere);
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGRectangle);
			RsDEFINE_CLASS(CGMultiLine);
		}

		using namespace Kernel;
		using namespace Kernel::Primitive;
		using namespace Kernel::File;
		using namespace Kernel::Collection;
		using namespace Kernel::Util;
		using namespace Kernel::Math;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CRay) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CRay();
	CRay(const CRay & iRay);
	CRay(const CGPointDouble & iOrigin, const CVector & iDirection);
	CRay(const DOUBLE ox, const DOUBLE oy, const DOUBLE oz, const DOUBLE dx, const DOUBLE dy, const DOUBLE dz);
	virtual ~CRay();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetOrigin() const { return m_Origin; }
	inline const CVector &	GetDirection() const { return m_Direction; }
public:
	inline void				SetOrigin(const CGPointDouble & iOrigin) { m_Origin = iOrigin; }
	inline void				SetDirection(const CVector & iDirection) { m_Direction = iDirection; }
	inline void				SetOrigin(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) { m_Origin.SetCoordinate(iX, iY, iZ); }
	inline void				SetDirection(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) { m_Direction.SetCoordinate(iX, iY, iZ); }
#pragma endregion

#pragma region General Function
public:
	const BOOL				IsEqual(const CRay & iRay) const;
#pragma endregion

#pragma region CAD Functions
public:
	const BOOL				Overlap(const CBoundingBox & iBoundingBox) const;
	const BOOL				Overlap(const CGSphere & iSphere) const;
	const BOOL				SolveQuadratic(const DOUBLE a, const DOUBLE b, const DOUBLE c, DOUBLE & x0, DOUBLE & x1) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CRay *			Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CRay &			operator = (const CRay & iRay);
	const BOOL				operator == (const CRay & iRay) const;
	const BOOL				operator != (const CRay & iRay) const;
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Origin;
	CVector					m_Direction;
#pragma endregion
};



	}
}