#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CBaseObject);
	}

	namespace Unit
	{
		using namespace Kernel::Object;

#define TO_DOUBLE(value)				((DOUBLE)value)
#define TO_FLOAT(value)					((FLOAT)value)
#define TO_INT(value)					((INT)value)
#define TO_UINT(value)					((UINT)value)
#define TO_FLOAT_UM(value)				(TO_FLOAT(value) * 1000.f)
#define TO_FLOAT_MM(value)				(TO_FLOAT(value) * 001.f)
#define TO_DOUBLE_UM(value)				(TO_DOUBLE(value) * 1000.0)
#define TO_DOUBLE_MM(value)				(TO_DOUBLE(value) * 0.001)

RsDEFINE_DLL_CLASS(CUnit) : RsIMPLEMENT(CBaseObject)
{
#pragma region Construction & Destruction
public:
	CUnit(const DOUBLE iScale);
	CUnit(const CUnit & iUnit);
	virtual ~CUnit();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const DOUBLE		GetScale() const { return m_Scale; }
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjToCopy);
private:
	virtual CUnit *			Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
protected:
	const CUnit &			operator = (const CUnit & iUnit);
#pragma endregion

#pragma region Static fuction
public:
	template<class _type>
	static const _type		ConvertToUM(const _type & iValue) { return iValue * (_type)1000.0; }
	template<class _type>
	static const _type		ConvertToMM(const _type & iValue) { return iValue / (_type)1000.0; }
	template<class _type>
	static const _type		ConvertFromMM3ToL(const _type & iValue) { return iValue * (_type).000001; }
	template<class _type>
	static const _type		ConvertFromMM3ToML(const _type & iValue) { return iValue * (_type).001; }
	template<class _type>
	static const _type		ConvertToPercentage(const _type & iValue) { return iValue * (_type)100.0; }
	template<class _type>
	static const _type		ConvertToRaioFromPercentage(const _type & iValue) { return iValue / (_type)100.0; }
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_Scale;
#pragma endregion
};

	}
}