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

RsDEFINE_DLL_CLASS(CGEllipse2D) : RsINHERITANCE(CGeometryObject)
{
#pragma region Construction & Destruction
public:
	CGEllipse2D();
	CGEllipse2D(const CGPoint2DDouble & iPoint, const DOUBLE iHorRadius, const DOUBLE iVerRadius);
	CGEllipse2D(const CGEllipse2D & iEllipse);
	virtual ~CGEllipse2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPoint2DDouble &	GetPoint() const { return m_Point; }
	inline const DOUBLE		GetHorRadius() const { return m_HorRadius; }
	inline const DOUBLE		GetVerRadius() const { return m_VerRadius; }

	void					Get(CGPolygons2D & oPolygons) const;
#pragma endregion

#pragma region General Function
public:
	void					ToMultiLine(vector<Coordinate2D> & oCircleLine, const UINT iNumberOfPoint = 40) const;

protected:
	const BOOL				IsEqual(const CGEllipse2D & iEllipse) const;

public:
	virtual const CGPoint2DDouble	GetCenterPoint() const;
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
	virtual CGEllipse2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CGEllipse2D &		operator = (const CGEllipse2D & iEllipse);
	const CGEllipse2D		operator + (const CVector2D & iVector) const;
	void					operator += (const CVector2D & iVector);
	const CGEllipse2D		operator - () const;
	const CGEllipse2D		operator - (const CVector2D & iVector) const;
	void					operator -= (const CVector2D & iVector);
	const CGEllipse2D		operator * (const DOUBLE iValue) const;
	void					operator *= (const DOUBLE iValue);
	const CGEllipse2D		operator / (const DOUBLE iValue) const;
	void					operator /= (const DOUBLE iValue);
	const BOOL				operator == (const CGEllipse2D & iEllipse) const;
	const BOOL				operator != (const CGEllipse2D & iEllipse) const;
#pragma endregion

#pragma region Static fuction
public:
	static void				CreateEllipse2D(const CGPoint2DDouble & iCenterPoint, const DOUBLE iHorRadius, const DOUBLE iVerRadius, const UINT iNumberOfPoint, vector<Coordinate2D> & oEllipseLine);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPoint2DDouble			m_Point;
	DOUBLE					m_HorRadius;
	DOUBLE					m_VerRadius;
#pragma endregion
};

		}
	}
}