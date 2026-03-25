#pragma once

namespace Kernel
{
namespace Util
{

RsDEFINE_DLL_CLASS(CBitConverter)
{

public:
	static BOOL		ToBool(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian=TRUE);
	static SHORT	ToShort(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static USHORT	ToUShort(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static WORD		ToWord(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static INT32	ToInt32(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static INT64	ToInt64(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static UINT32	ToUInt32(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static DWORD	ToDWord(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static UINT64	ToUInt64(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static FLOAT	ToFloat(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);
	static DOUBLE	ToDouble(BYTE* pData, INT nOffset = 0, BOOL bLittleEndian = TRUE);

	static INT		GetBoolBytes(BOOL value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetShortBytes(SHORT value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetUShortBytes(USHORT value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetWordBytes(WORD valuer, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetInt32Bytes(INT32 value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetInt64Bytes(INT64 value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetUInt32Bytes(UINT32 value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetDWordBytes(DWORD value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetUInt64Bytes(UINT64 value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetFloatBytes(FLOAT value, BYTE* pBuff, BOOL bLittleEndian = TRUE);
	static INT		GetDoubleBytes(DOUBLE value, BYTE* pBuff, BOOL bLittleEndian = TRUE);

};
}
}