#pragma once

#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

namespace Kernel
{

#pragma region Parallel
#define PARALLEL_GENERAL		0x00000000
#define PARALLEL_OPENMP			0x00000001
#define PARALLEL_METHOD			PARALLEL_OPENMP
#pragma endregion

#pragma region Export/Import Definition for dll
#ifdef _HYEXT
#define RESHAPER3D_EXT_CLASS     __declspec(dllexport)
#define RESHAPER3D_EXT_API         __declspec(dllexport)
#define RESHAPER3D_EXT_DATA        __declspec(dllexport)
#define RESHAPER3D_EXT_DATADEF
#else
#define RESHAPER3D_EXT_CLASS       __declspec(dllimport)
#define RESHAPER3D_EXT_API         __declspec(dllimport)
#define RESHAPER3D_EXT_DATA        __declspec(dllimport)
#define RESHAPER3D_EXT_DATADEF
#endif

#define RsDEFINE_DLL_CLASS(classtype)		class RESHAPER3D_EXT_CLASS classtype
#define RsDEFINE_TEMPLATECLASS(classtype)	template<class _T> class classtype
#define RsDEFINE_TEMPLATECLASS_TYPENAME(type, classtype)	template<typename type> class classtype
#define RsDEFINE_DLL_STRUCT(structtype)		struct RESHAPER3D_EXT_CLASS structtype
#define RsDEFINE_CLASS(classtype)			class classtype
#define RsDEFINE_TYPEDEF_STRUCT(predefine, postdefine)	typedef struct predefine postdefine
#define RsDEFINE_STRUCT(define)				struct define
#define RsDEFINE_INTERFACE(classtype)		class classtype
#define RsINTERFACE(classtype)				class classtype
#define RsINHERITANCE(classtype)			public classtype
#define RsINHERITANCE2(accessright, classtype)		accessright classtype
#define RsIMPLEMENT(interfacetype)			public interfacetype
#define RsIMPLEMENT2(accessright, interfacetype)	accessright interfacetype
#pragma endregion

#define PROGRESS_EXECUTE_STEPNUMBER			1000
#define GENERAL_RESOLUTION					20

#define BEGIN_ENUM()						\
	typedef enum
#define END_ENUM(type, lastenum)			\
	type;									\
	enum{	type##_COUNT = lastenum	};

#define DECLARE_INLINE_ATTRIBUTE(type, name)									\
public:																			\
	inline const type	Get##name() const { return m_##name; }					\
	inline void			Set##name(const type & i##name) { m_##name = i##name; }	\
private:																		\
	type				m_##name;

	typedef enum
	{
		AXISTYPE_XAXIS ,
		AXISTYPE_YAXIS ,
		AXISTYPE_ZAXIS
	}AXISTYPE;
	typedef enum
	{
		AXIS2DTYPE_XYAXIS,
		AXIS2DTYPE_YZAXIS,
		AXIS2DTYPE_XZAXIS
	}AXIS2DTYPE;
	typedef enum
	{
		DIRECTION2DSIDE_LEFT,
		DIRECTION2DSIDE_RIGHT,
	}DIRECTION2DSIDE;

	typedef enum { AdjacentFieldTypeNoOverlap, AdjacentFieldTypeHorizontal, AdjacentFieldTypeVertical, AdjacentFieldTypeDiagonal }AdjacentFieldType;

// Definition struct
	typedef struct __coordinate3d
	{
		__coordinate3d() : _xx(0.), _yy(0.), _zz(0.) {}
		__coordinate3d(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) : _xx(iX), _yy(iY), _zz(iZ) {}
		inline void Init(const DOUBLE iX, const DOUBLE iY, const DOUBLE iZ) { _xx = iX;	_yy = iY; _zz = iZ; }
		void operator *= (const DOUBLE iValue) { _xx *= iValue; _yy *= iValue; _zz *= iValue; }
		void operator /= (const DOUBLE iValue) { _xx /= iValue; _yy /= iValue; _zz /= iValue; }
		const __coordinate3d operator * (const DOUBLE iValue) const { __coordinate3d tmp = *this; tmp *= iValue; return tmp; }
		const __coordinate3d operator / (const DOUBLE iValue) const { __coordinate3d tmp = *this; tmp /= iValue; return tmp; }
		void operator += (const __coordinate3d & iCoord) { _xx += iCoord._xx; _yy += iCoord._yy; _zz += iCoord._zz; }
		void operator -= (const __coordinate3d & iCoord) { _xx -= iCoord._xx; _yy -= iCoord._yy; _zz -= iCoord._zz; }
		const __coordinate3d operator + (const __coordinate3d & iCoord) const { __coordinate3d tmp = *this; tmp += iCoord; return tmp; }
		const __coordinate3d operator - (const __coordinate3d & iCoord) const { __coordinate3d tmp = *this; tmp -= iCoord; return tmp; }
		const BOOL operator == (const __coordinate3d & iCoord) const { return _xx == iCoord._xx && _yy == iCoord._yy && _zz == iCoord._zz; }
		const BOOL operator != (const __coordinate3d & iCoord) const { return _xx != iCoord._xx || _yy != iCoord._yy || _zz != iCoord._zz; }
		const DOUBLE Dot(const __coordinate3d & iCoord) const { return _xx * iCoord._xx + _yy * iCoord._yy + _zz * iCoord._zz; }
		const __coordinate3d Cross(const __coordinate3d & iCoord) const { return { _yy * iCoord._zz - _zz * iCoord._yy, _zz * iCoord._xx - _xx * iCoord._zz, _xx * iCoord._yy - _yy * iCoord._xx }; }
		union {
			struct { DOUBLE _xx, _yy, _zz; };
			DOUBLE _val[3];
		};
	}Coordinate3D, *pCoordinate3D;

	typedef struct __coordinate2d
	{
		__coordinate2d() : _xx(0.), _yy(0.) {}
		__coordinate2d(const DOUBLE iX, const DOUBLE iY) : _xx(iX), _yy(iY) {}
		inline void Init(const DOUBLE iX, const DOUBLE iY) { _xx = iX;	_yy = iY; }
		void operator *= (const DOUBLE iValue) { _xx *= iValue; _yy *= iValue; }
		void operator /= (const DOUBLE iValue) { _xx /= iValue; _yy /= iValue; }
		const __coordinate2d operator * (const DOUBLE iValue) const { __coordinate2d tmp = *this; tmp *= iValue; return tmp; }
		const __coordinate2d operator / (const DOUBLE iValue) const { __coordinate2d tmp = *this; tmp /= iValue; return tmp; }
		void operator += (const __coordinate2d & iCoord) { _xx += iCoord._xx; _yy += iCoord._yy; }
		void operator -= (const __coordinate2d & iCoord) { _xx -= iCoord._xx; _yy -= iCoord._yy; }
		const __coordinate2d operator + (const __coordinate2d & iCoord) const { __coordinate2d tmp = *this; tmp += iCoord; return tmp; }
		const __coordinate2d operator - (const __coordinate2d & iCoord) const { __coordinate2d tmp = *this; tmp -= iCoord; return tmp; }
		const BOOL operator == (const __coordinate2d & iCoord) const { return _xx == iCoord._xx && _yy == iCoord._yy; }
		const BOOL operator != (const __coordinate2d & iCoord) const { return _xx != iCoord._xx || _yy != iCoord._yy; }
		const DOUBLE Dot(const __coordinate2d & iCoord) const { return _xx * iCoord._xx + _yy * iCoord._yy; }
		const DOUBLE Cross(const __coordinate2d & iCoord) const { return _xx * iCoord._yy - _yy * iCoord._xx; }
		union {
			struct { DOUBLE _xx, _yy; };
			DOUBLE _val[2];
		};
	}Coordinate2D, *pCoordinate2D;

	typedef struct __linecoordinate3d
	{
		__linecoordinate3d() {}
		__linecoordinate3d(const Coordinate3D & iDeparture, const Coordinate3D & iArrival) : _Departure(iDeparture), _Arrival(iArrival) {}
		__linecoordinate3d(const DOUBLE iDepartureX, const DOUBLE iDepartureY, const DOUBLE iDepartureZ, const DOUBLE iArrivalX, const DOUBLE iArrivalY, const DOUBLE iArrivalZ) : _Departure(iDepartureX, iDepartureY, iDepartureZ), _Arrival(iArrivalX, iArrivalY, iArrivalZ) {}
		inline void Init(const Coordinate3D & iDeparture, const Coordinate3D & iArrival) { _Departure = iDeparture;	_Arrival = iArrival; }
		static void ToLineLists(const vector<vector<Coordinate3D>> & iPolygons, vector<vector<__linecoordinate3d>> & oLineLists)
		{
			oLineLists.resize(iPolygons.size());
			for (UINT ii = 0; ii < (UINT)iPolygons.size(); ii++)
			{
				vector<__linecoordinate3d> & iLineList	= oLineLists[ii];
				const vector<Coordinate3D> & iPolygon	= iPolygons[ii];
				if (iPolygon.size() < 2) continue;

				iLineList.resize(iPolygon.size() - 1);
				for (UINT jj = 1; jj < (UINT)iPolygon.size(); jj++)
				{
					__linecoordinate3d & iLine = iLineList[jj - 1];

					iLine._Departure	= iPolygon[jj - 1];
					iLine._Arrival		= iPolygon[jj];
				}
			}
		}
		union {
			struct { Coordinate3D _Departure, _Arrival; };
			Coordinate3D _val[3];
		};
	}LineCoordinate3D, *pLineCoordinate3D;

	typedef struct __linecoordinate2d
	{
		__linecoordinate2d() {}
		__linecoordinate2d(const DOUBLE iDepartureX, const DOUBLE iDepartureY, const DOUBLE iArrivalX, const DOUBLE iArrivalY) : _Departure(iDepartureX, iDepartureY), _Arrival(iArrivalX, iArrivalY) {}
		inline void Init(const Coordinate2D & iDeparture, const Coordinate2D & iArrival) { _Departure = iDeparture;	_Arrival = iArrival; }
		static void ToLineLists(const vector<vector<Coordinate2D>> & iPolygons, vector<vector<__linecoordinate2d>> & oLineLists)
		{
			oLineLists.resize(iPolygons.size());
			for (UINT ii = 0; ii < (UINT)iPolygons.size(); ii++)
			{
				vector<__linecoordinate2d> & iLineList	= oLineLists[ii];
				const vector<Coordinate2D> & iPolygon	= iPolygons[ii];
				if (iPolygon.size() < 2) continue;

				iLineList.resize(iPolygon.size() - 1);
				for (UINT jj = 1; jj < (UINT)iPolygon.size(); jj++)
				{
					__linecoordinate2d & iLine = iLineList[jj - 1];

					iLine._Departure	= iPolygon[jj - 1];
					iLine._Arrival		= iPolygon[jj];
				}
			}
		}
		union {
			struct { Coordinate2D _Departure, _Arrival; };
			Coordinate2D _val[2];
		};
	}LineCoordinate2D, *pLineCoordinate2D;

#ifdef use_int32
	typedef int cInt;
	static cInt const loRange = 0x7FFF;
	static cInt const hiRange = 0x7FFF;
#else
	typedef signed long long cInt;
	static cInt const loRange = 0x3FFFFFFF;
	static cInt const hiRange = 0x3FFFFFFFFFFFFFFFLL;
	typedef signed long long long64;     //used by Int128 class
	typedef unsigned long long ulong64;

#endif

	struct IntPoint {
		cInt X;
		cInt Y;
#ifdef use_xyz
		cInt Z;
		IntPoint(cInt x = 0, cInt y = 0, cInt z = 0) : X(x), Y(y), Z(z) {};
#else
		IntPoint(cInt x = 0, cInt y = 0) : X(x), Y(y) {};
#endif

		friend inline bool operator== (const IntPoint& a, const IntPoint& b)
		{
			return a.X == b.X && a.Y == b.Y;
		}
		friend inline bool operator!= (const IntPoint& a, const IntPoint& b)
		{
			return a.X != b.X || a.Y != b.Y;
		}
		friend inline IntPoint operator - (const IntPoint& a, const IntPoint& b)
		{
			return IntPoint(a.X - b.X, a.Y - b.Y);
		}
		friend inline IntPoint operator * (const IntPoint& a, const UINT64 iValue)
		{
			return IntPoint(a.X * iValue, a.Y * iValue);
		}
		friend inline IntPoint operator / (const IntPoint& a, const UINT64 iValue)
		{
			return IntPoint(a.X / iValue, a.Y / iValue);
		}
	};
	typedef std::vector<IntPoint> Path;
	typedef std::vector<Path> Paths;
	struct IntRect { cInt left; cInt top; cInt right; cInt bottom; };

	typedef struct __ImageInfo
	{
		__ImageInfo() : pImage(NULL) {}
		__ImageInfo(const __ImageInfo & info) : pImage(NULL) { operator = (info); }
		~__ImageInfo() { RemoveImage(); }
		BYTE *	GetImage() { return pImage; }
		void SetImage(BYTE * iImage) { RemoveImage(); pImage = iImage; }
		void RemoveImage()
		{
			if (pImage)
				delete[] pImage;
			pImage		= NULL;
		}
		const __ImageInfo & operator = (const __ImageInfo & info)
		{
			if (this == &info) return *this;

			RemoveImage();

			ImageWidth	= info.ImageWidth;
			ImageHeight	= info.ImageHeight;
			ImageFormat	= info.ImageFormat;
			ImageSize	= info.ImageSize;

			if (ImageSize && info.pImage)
			{
				pImage = new BYTE[ImageSize];
				memcpy(pImage, info.pImage, ImageSize);
			}

			return *this;
		}

		UINT			ImageWidth;
		UINT			ImageHeight;
		PixelFormat		ImageFormat;
		UINT			ImageSize;
	private:
		BYTE *			pImage;
	}ImageInfo;

	typedef struct __supportinglinetoaddonsupportlayers
	{
		UINT		m_Type;
		UINT		m_NumberOfLayerToAdd;
		DOUBLE		m_CriteriaLength;
		DOUBLE		m_AdditionalLength;
		UINT		m_GuideType;
	}SupportingLineToAddOnSupportLayers;

	typedef struct __outermosttwist
	{
		__outermosttwist() : m_Type(0), m_Length(0.02), m_Angle(0.) {}
		UINT		m_Type;
		DOUBLE		m_Length;
		DOUBLE		m_Angle;
	}OutermostTwist;

	typedef struct __optionstoaddfromslicedfile
	{
		__optionstoaddfromslicedfile() : m_AddingExposureCountForOutermostBoarderLine(0), m_RemoveNegativeBorders(FALSE) {}
		SupportingLineToAddOnSupportLayers	m_RaftAndSupporting;
		OutermostTwist			m_Twist;
		UINT					m_AddingExposureCountForOutermostBoarderLine;
		BOOL					m_RemoveNegativeBorders;
	}OptionsToAddFromSlicedFile;

	typedef enum { UNITTYPE_UNKNOWN, UNITTYPE_MM, UNITTYPE_INCH } UNITTYPE;
	typedef enum { OBJECTTYPE_UNKNOWN, OBJECTTYPE_PART, OBJECTTYPE_SUPPORT_NONSOLID, OBJECTTYPE_SUPPORT_SOLID, OBJECTTYPE_COUNT } OBJECTTYPE;
	typedef struct __headinformation
	{
		INT			Version;
		UNITTYPE	Unit;
		OBJECTTYPE	Type;
		TCHAR		Package[256];
		struct BoundaryBox
		{
			Coordinate2D x;
			Coordinate2D y;
			Coordinate2D z;
		} Extents;
	}SLCHEADINFORMATION;
}