#pragma once

namespace Kernel
{
	namespace File
	{
		RsDEFINE_CLASS(CFileReadObject);
		RsDEFINE_CLASS(CFileWriteObject);
	}

	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		namespace Geometry
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGPlane) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGPlane(const DOUBLE iA, const DOUBLE iB, const DOUBLE iC, const DOUBLE iD);
	CGPlane(const CGPointDouble & iPointOnPlane, const CVector & iNormalPlane);
	CGPlane(const CGPlane & rhs);
	virtual ~CGPlane();
#pragma endregion

#pragma region Setter & Getter function
public:
	const CVector			GetNormal() const;
public:
	inline void				Init(const DOUBLE iA, const DOUBLE iB, const DOUBLE iC, const DOUBLE iD) { _A = iA; _B = iB; _C = iC; _D = iD; }
	void					Init(const CGPointDouble & iPointOnPlane, const CVector & iNormalPlane);
protected:
	void					SetNormal(const CVector & iNormal);
#pragma endregion

public:
	const CGPointDouble		Project(const CGPointDouble & iPointToProject) const;
	const INT				Project(const CGPointDouble & iDeparture, const CVector & iDirection, CGPointDouble & oProjectedPoint) const;
protected:
	const CGPointDouble		Interpolate(const DOUBLE iU, const DOUBLE iV) const;

	const BOOL				IsEqual(const CGPlane & iPlane) const;

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGPlane *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGPlane &			operator = (const CGPlane & iPlane);
	const CGPlane			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGPlane			operator - () const;
	const CGPlane			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const CGPlane			operator * (const DOUBLE iValue) const;
	const CGPlane			operator * (const CMatrix3x3 & iMatrix) const;
	const CGPlane			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const DOUBLE iValue);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const CGPlane			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGPlane & iPlane) const;
	const BOOL				operator != (const CGPlane & iPlane) const;
#pragma endregion

#pragma region Memeber Variable
private:
	union  {
		struct { DOUBLE _A, _B, _C, _D; };
		DOUBLE _val[4];
	};
#pragma endregion
};

		}
	}
}