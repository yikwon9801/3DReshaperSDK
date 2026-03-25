#pragma once

namespace Kernel
{
	namespace Interface
	{
		RsDEFINE_INTERFACE(IPatternObject);
	}

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
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix2x3);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPolygons2D);
		}
	}

	namespace Object
	{
		namespace Pattern
		{
			using namespace Kernel::Interface;
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CPatternObject) : RsINHERITANCE(CManagedObject), RsIMPLEMENT(IPatternObject)
{
#pragma region Type Definition
public:
	typedef enum
	{
		INFILLMODE_NONE,
		INFILLMODE_VECTOR,
	}INFILLMODE;
	typedef struct __infillattribute
	{
		__infillattribute() : m_Mode(INFILLMODE_NONE), m_BorderNumber(0), m_HatchDistance(0.1), m_Angle(0.) {}
		INFILLMODE	m_Mode;
		UINT		m_BorderNumber;
		DOUBLE		m_HatchDistance;
		DOUBLE		m_Angle;
	}InfillAttribute;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CPatternObject();
public:
	virtual ~CPatternObject();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BOOL		IsInfill() const { return m_IsInfill; }
	inline const CPatternObject::InfillAttribute &	GetInfillAttribute() const { return m_InfillAttribute; }
public:
	inline void				SetInfill(const BOOL iInfill, const InfillAttribute & iAttribute) { SetInfill(iInfill);	SetInfillAttribute(iAttribute); }
private:
	inline void				SetInfill(const BOOL iInfill) { m_IsInfill = iInfill; }
	inline void				SetInfillAttribute(const InfillAttribute & iAttribute) { m_InfillAttribute = iAttribute; }
#pragma endregion

#pragma region General Function
public:

protected:
	virtual const BOOL		IsEqual(const CPatternObject & iObject) const;
#pragma endregion

#pragma region Abstract fuction
public:
	const INT				GetPattern(CGPolygons2D & oPolygons) const;
protected:
	virtual const BOOL		IsSolidType() const = 0;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
#pragma endregion

#pragma region Abstract fuction of IPatternObject
public:
#pragma endregion

#pragma region Operator Declaration
public:
#pragma endregion

#pragma region Static fuction
public:
#pragma endregion

#pragma region Memeber Variable
private:
	InfillAttribute			m_InfillAttribute;
	BOOL					m_IsInfill;
#pragma endregion
};

		}
	}
}