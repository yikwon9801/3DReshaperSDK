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
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		namespace Geometry
		{
			using namespace Kernel::File;
			using namespace Kernel::Math;
			using namespace Kernel::Util;

RsDEFINE_DLL_CLASS(CGEllipse) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGEllipse();
	CGEllipse(const CGPointDouble & iPoint, const CVector & iDirection, const DOUBLE iHorRadius, const DOUBLE iVerRadius);
	CGEllipse(const CGEllipse & iEllipse);
	virtual ~CGEllipse();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPoint() const { return m_Point; }
	inline const CVector &	GetDirection() const { return m_Direction; }
	inline const DOUBLE		GetHorRadius() const { return m_HorRadius; }
	inline const DOUBLE		GetVerRadius() const { return m_VerRadius; }
#pragma endregion

#pragma region General Function
public:
	void					ToMultiLine(CGMultiLine & oEllipseLine, const UINT iNumberOfPoint = 40) const;
	void					ToMultiLine(vector<Coordinate2D> & oCircleLine, const UINT iNumberOfPoint = 40) const;

protected:
	const BOOL				IsEqual(const CGEllipse & iEllipse) const;

public:
	virtual const CGPointDouble	GetCenterPoint() const;
#pragma endregion

#pragma region CAD Functions
public:
	const DOUBLE			GetArea() const;
	const DOUBLE			GetCircumference() const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
protected:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CGEllipse *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGEllipse &		operator = (const CGEllipse & iEllipse);
	const CGEllipse			operator + (const CVector & iVector) const;
	void					operator += (const CVector & iVector);
	const CGEllipse			operator - () const;
	const CGEllipse			operator - (const CVector & iVector) const;
	void					operator -= (const CVector & iVector);
	const BOOL				operator == (const CGEllipse & iEllipse) const;
	const BOOL				operator != (const CGEllipse & iEllipse) const;
#pragma endregion

#pragma region Static fuction
public:
	static void				CreateEllipse(const CGPointDouble & iCenterPoint, const CVector & iNormal, const DOUBLE iHorRadius, const DOUBLE iVerRadius, const UINT iNumberOfPoint, CGMultiLine & oEllipseLine);
	static void				CreateEllipse2D(const CGPointDouble & iCenterPoint, const DOUBLE iHorRadius, const DOUBLE iVerRadius, const UINT iNumberOfPoint, vector<Coordinate2D> & oEllipseLine);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Point;
	CVector					m_Direction;
	DOUBLE					m_HorRadius;
	DOUBLE					m_VerRadius;
#pragma endregion
};

		}
	}
}