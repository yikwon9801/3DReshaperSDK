#pragma once

#include <algorithm>

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
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Math
	{

#pragma region Definition Values
#define MATRIX_2X2			4
#define MATRIX_3X3			9
#define MATRIX_4X4			16
#define PI					(double)3.1415926535897932384626433832795
#define PI2					PI*2.
#define RADIAN_1			57.295779513082320876798154814105	// 360/2*PI
#define HyINFINITY			999999.999
#define HyEPSILON			1.e-5
#define HyEPSILON_3			1.e-3

#define TO_RADIAN(degree)   ((degree)*(PI/180.0f))
#define TO_HALF_RADIAN		PI/360.
#define PIOVER180			PI/180.
#define TO_DEGREE(radian)   ((radian)*(180.0f/PI))

#define DBL_MAX				1.7976931348623158e+308 /* max value */
// #define INT8_MAX			127
// #define INT8_MIN			-128
// #define UINT8_MAX			255
// #define INT16_MAX			32767
// #define INT16_MIN			-32768
// #define UINT16_MAX			65535
//#define INT32_MAX			2147483647
//#define INT32_MIN			-2147483648
// #define UINT32_MAX			4294967295
// #define INT64_MAX			9223372036854775807
// #define INT64_MIN			-9223372036854775808
// #define UINT64_MAX			18446744073709551615
#define ISOUTSIDE(v1, v2, v3, v, accuracy)	((v-v1) > accuracy && (v-v2) > accuracy && (v-v3) > accuracy) || ((v-v1) < accuracy && (v-v2) < accuracy && (v-v3) < accuracy)
#define ROUND

#pragma endregion

		using namespace Kernel::File;
		using namespace Kernel::Object;
		using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CMath) : RsINHERITANCE(CBaseObject)
{
#pragma region Construction & Destruction
protected:
	CMath();
	CMath(const CMath & rhs);
	virtual ~CMath();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CMath *			Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
protected:
	const CMath &			operator = (const CMath & iMath);
#pragma endregion

#pragma region Static Function
public:
	static const INT		CombinationC2(const vector<INT> & iNumberList, vector<pair<INT, INT>> & oResult);
	static const DOUBLE		Round(const DOUBLE r, const UINT16 precision);
	static const DOUBLE		RoundAbs(const DOUBLE r, const UINT16 precision);
	static const FLOAT		Round(const FLOAT r, const UINT16 precision);
	static const FLOAT		RoundAbs(const FLOAT r, const UINT16 precision);
	static const DOUBLE		ToPositiveDegree(const DOUBLE iAngle);
	static const DOUBLE		ToPositiveRadian(const DOUBLE iRadian);
	static const DOUBLE		Mean(const vector<DOUBLE> & iList);
	static const DOUBLE		StandardDeviation(const vector<DOUBLE> & iList);
	static void				GetMeanAndStandardDeviation(const vector<DOUBLE> & iList, DOUBLE & oMean, DOUBLE & oSTDEV);
	static const UINT		NoiseFilter(const vector<DOUBLE> & iList, vector<DOUBLE> & oList, const DOUBLE iThresHold);
	template<class _type> static const _type MAX(const _type & a, const _type & b)	{ return std::max(a, b); }
	template<class _type> static const _type MIN(const _type & a, const _type & b)	{ return std::min(a, b); }
#pragma endregion
};

	}
}