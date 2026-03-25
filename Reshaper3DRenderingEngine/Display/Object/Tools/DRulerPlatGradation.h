#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);

		namespace Control
		{
			RsDEFINE_CLASS(CDText);
		}
	}

	namespace Object
	{

		namespace Tools
		{
			using namespace Display::View;
			using namespace Display::View::Control;

RsDEFINE_DLL_CLASS(CDRulerPlatGradation) : RsINHERITANCE(CDComponent2D)
{
public:
	typedef enum {
		LENGTH_UNIT_1mm,
		LENGTH_UNIT_10mm,
		LENGTH_UNIT_100mm,
		LENGTH_UNIT_1000mm,
	}LENGTH_UNIT;
	typedef enum {
		LOCATION_SIDE_NONE				= 0x00,
		LOCATION_SIDE_LEFT				= 0x01,
		LOCATION_SIDE_BOTTOM			= 0x02,
		LOCATION_SIDE_LEFTBOTTOM		= LOCATION_SIDE_LEFT | LOCATION_SIDE_BOTTOM,
	}LOCATION_SIDE;
#pragma region Construction & Destruction
public:
	CDRulerPlatGradation(CDOpenGLScene * iScene);
	virtual ~CDRulerPlatGradation();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGSizeDouble &	GetLength() const { return m_Length; }
	inline const LENGTH_UNIT	GetUnit() const { return m_Unit; }
	inline const LOCATION_SIDE	GetType() const { return m_Type; }
	inline const BOOL			GetNegative() const { return m_bNegative; }
	inline const UINT			GetHeight() const { return m_Height; }
public:
	inline void					SetLength(const CGSizeDouble iLength) { m_Length = iLength; }
	inline void					SetUnit(const LENGTH_UNIT iUnit) { m_Unit = iUnit; }
	inline void					SetType(const LOCATION_SIDE iType) { m_Type = iType; }
	inline void					SetNegative(const BOOL iSet) { m_bNegative = iSet; }
	inline void					SetHeight(const UINT iHeight) { m_Height = iHeight; }
#pragma endregion

#pragma region Display
public:
	typedef enum {
		REP_STANDARD ,
	}RepresentationType;
public:
	virtual const INT			Display() const;

#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDRulerPlatGradation *	Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
#pragma endregion

#pragma region Operator Declaration
public:
	const CDRulerPlatGradation &	operator = (const CDRulerPlatGradation & iRuler);
#pragma endregion

#pragma region Memeber Variable
private:
	CGSizeDouble				m_Length;
	LENGTH_UNIT					m_Unit;
	LOCATION_SIDE				m_Type;
	BOOL						m_bNegative;
	BOOL						m_Height;
private:
	struct  Internal;
	Internal *					m_Internal;
#pragma endregion
};


		}
	}
}