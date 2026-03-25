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
		DIRECTION2DSIDE_LEFT,
		DIRECTION2DSIDE_RIGHT,
	}DIRECTION2DSIDE;

	typedef enum { AdjacentFieldTypeNoOverlap, AdjacentFieldTypeHorizontal, AdjacentFieldTypeVertical, AdjacentFieldTypeDiagonal }AdjacentFieldType;

// Definition struct
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
		union {
			struct { DOUBLE _xx, _yy; };
			DOUBLE _val[2];
		};
	}Coordinate2D, *pCoordinate2D;

	typedef struct __linecoordinate2d
	{
		__linecoordinate2d() {}
		__linecoordinate2d(const DOUBLE iDepartureX, const DOUBLE iDepartureY, const DOUBLE iArrivalX, const DOUBLE iArrivalY) : _Departure(iDepartureX, iDepartureY), _Arrival(iArrivalX, iArrivalY) {}
		union {
			struct { Coordinate2D _Departure, _Arrival; };
			Coordinate2D _val[2];
		};
	}LineCoordinate2D, *pLineCoordinate2D;

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