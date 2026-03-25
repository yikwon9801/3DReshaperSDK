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

	namespace Collection
	{
		namespace Object
		{
			RsDEFINE_CLASS(CManagedObject);
		}
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointDouble);
		}

		RsDEFINE_CLASS(CBoundingBox);

		namespace Vision
		{
			using namespace Kernel::File;
			using namespace Kernel::Object;
			using namespace Kernel::Object::Geometry;
			using namespace Kernel::Math;
			using namespace Kernel::Collection::Object;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CCamera) : RsINHERITANCE(CManagedObject)
{
#pragma region Construction & Destruction
public:
	CCamera();
	CCamera(const CCamera & rhs);
	virtual ~CCamera();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const USHORT		GetWidth() const	{ return m_Width; }
	inline const USHORT		GetHeight() const	{ return m_Height; }
	inline const CRect		GetVisibleRect() const { return CRect(m_RestrictionXMin, m_RestrictionYMin, m_Width - m_RestrictionXMax, m_Height - m_RestrictionYMax); }
	inline const DOUBLE		GetZoomFactor() const	{ return m_Zoom; }
	inline const CGPointDouble &	GetOriginPosition() const	{ return m_Origin; }
	inline const CGPointDouble &	GetPosition() const	{ return m_Position; }
	inline const CVector &	GetUpDirection() const	{ return m_Up; }
	inline const CVector &	GetViewDirection() const	{ return m_View; }
	inline const CVector	GetViewDirection(const BOOL bNormalize) const { if (bNormalize) { CVector viewDirection(GetViewDirection()); viewDirection.Normalized(); return viewDirection; }	return GetViewDirection(); }
	inline const CVector	GetRightDirection() const;
public:
	inline void				SetWindowSize(const USHORT iWidth, const USHORT iHeight)	{ m_Width = iWidth;	m_Height = iHeight;	}
	inline void				SetZoomFactor(const DOUBLE iFactor)	{ m_Zoom = iFactor; }
	inline void				SetPosition(const CGPointDouble & iPosition)	{ m_Position = iPosition; }
	inline void				SetOriginPosition(const CGPointDouble & iPosition)	{ m_Origin = iPosition; }
	inline void				SetRestriction(const USHORT iXmin, const USHORT iYmin, const USHORT iXmax, const USHORT iYmax) { m_RestrictionXMin = iXmin; m_RestrictionXMax = iXmax; m_RestrictionYMin = iYmin; m_RestrictionYMax = iYmax; }
#pragma endregion

public:
	const CMatrix3x4		GetLocalMatrix() const;
	void					InitCamera();
	void					InitTopView();
	void					InitBottomView();
	void					InitFrontView();
	void					InitBackView();
	void					InitRightView();
	void					InitLeftView();
	void					InitCameraPosition(const CGPointDouble & iPosition, const CVector & iUp, const CVector & iView, const DOUBLE iZoom);
	void					SetCameraRotation(const CMatrix3x3 & iMatrix) { m_Up *= iMatrix; m_View *= iMatrix;	}
protected:
	const BOOL				IsEqual(const CCamera & iCamera) const;

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CCamera *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CCamera &			operator = (const CCamera & iCamera);
	const CCamera			operator + (const CVector & iVector) const;
	const CCamera			operator + (const CVector2D & iVector) const;
	void					operator += (const CVector & iVector);
	void					operator += (const CVector2D & iVector);
	const CCamera			operator * (const CMatrix3x3 & iMatrix) const;
	const CCamera			operator * (const CMatrix3x4 & iMatrix) const;
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CCamera & iCamera) const;
	const BOOL				operator != (const CCamera & iCamera) const;
#pragma endregion

#pragma region Memeber Variable
private:
	USHORT					m_Width;
	USHORT					m_Height;

	USHORT					m_RestrictionXMin, m_RestrictionYMin, m_RestrictionXMax, m_RestrictionYMax;
private:
	DOUBLE					m_Zoom;
private:
	CGPointDouble			m_Origin;
	CGPointDouble			m_Position;
	CVector					m_Up;
	CVector					m_View;
#pragma endregion
};
		}
	}
}