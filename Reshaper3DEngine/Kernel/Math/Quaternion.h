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

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);

		using namespace Kernel::File;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CQuaternion) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CQuaternion();
	CQuaternion(const CMatrix3x3 & iMatrix);
	CQuaternion(const DOUBLE x, const DOUBLE y, const DOUBLE z, const DOUBLE w);
	CQuaternion(const CQuaternion & iQuaternion);
	virtual ~CQuaternion();
#pragma endregion

#pragma region Setter & Getter function
public:
	void					Init(const CMatrix3x3 & iMatrix);
#pragma endregion

#pragma region General Functions
public:
	const BOOL				IsNull() const;
	const BOOL				IsIdentity() const;

	const DOUBLE			GetLength() const;
	const DOUBLE			GetLengthSquare() const;
protected:
	const BOOL				IsEqual(const CQuaternion & iQuaternion) const;
#pragma endregion

#pragma region Mathematic
public:
	void					InitRotation(const CVector & iFixed, const CVector & iMoved);

	const CMatrix3x3		ToMatrix3x3() const;
	const CEuler			ToEuler() const;

	const DOUBLE			Magnitude() const;
	const CQuaternion &		Normalized();

	const DOUBLE			Dot(const CQuaternion & quaternion) const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CQuaternion *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CQuaternion &		operator = (const CQuaternion & iQuternion);
	const CQuaternion		operator + (const CQuaternion & iQuternion) const;
	void					operator += (const CQuaternion & iQuternion);
	const CQuaternion		operator - () const;
	const CQuaternion		operator - (const CQuaternion & iQuternion) const;
	void					operator -= (const CQuaternion & iQuternion);
	const CQuaternion		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CQuaternion		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CQuaternion & iQuternion) const;
	const BOOL				operator != (const CQuaternion & iQuternion) const;
#pragma endregion

#pragma region Static Function
#pragma endregion

#pragma region Memeber Variable
protected:
	union {
		struct { DOUBLE _x, _y, _z, _w; };
		DOUBLE _val[4];
	};
#pragma endregion
};

	}
}