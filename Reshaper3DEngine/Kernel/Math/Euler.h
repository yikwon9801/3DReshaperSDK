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
		RsDEFINE_CLASS(CQuaternion);

		using namespace Kernel::File;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CEuler) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CEuler();
	CEuler(const CEuler & iEuler);
	CEuler(const CGPointDouble & iPoint);
	CEuler(const CVector & iVector);
	CEuler(const DOUBLE iEuler[]);
	CEuler(const DOUBLE iRoll,const DOUBLE iPitch, const DOUBLE iYaw);
	virtual ~CEuler();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetPitch() const { return _Pitch; }
	inline const DOUBLE		GetRoll() const { return _Roll; }
	inline const DOUBLE		GetYaw() const { return _Yaw; }
public:
	void					Init(const DOUBLE iRoll, const DOUBLE iPitch, const DOUBLE iYaw);
#pragma endregion

#pragma region Mathematic
public:
	const CMatrix3x3		ToMatrix3x3() const;
	const CQuaternion		ToQuaternion() const;
#pragma endregion

protected:
	const BOOL				IsEqual(const CEuler & iEuler) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CEuler *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CEuler &			operator = (const CEuler & iEuler);
	const CEuler			operator + (const DOUBLE iValue) const;
	const CEuler			operator + (const CEuler & iEuler) const;
	void					operator += (const DOUBLE iValue);
	void					operator += (const CEuler & iEuler);
	const CEuler			operator - () const;
	const CEuler			operator - (const DOUBLE iValue) const;
	const CEuler			operator - (const CEuler & iEuler) const;
	void					operator -= (const DOUBLE iValue);
	void					operator -= (const CEuler & iEuler);
	const CEuler			operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CEuler			operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CEuler & iEuler) const;
	const BOOL				operator != (const CEuler & iEuler) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	union {
		struct { DOUBLE _Roll, _Pitch, _Yaw; };
		DOUBLE _val[3];
	};
#pragma endregion
};

	}
}