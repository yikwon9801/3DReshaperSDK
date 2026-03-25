#pragma once

#include <list>
using namespace std;

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDPoint) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDPoint();
	CDPoint(const CGPointDouble & iPoint);
	CDPoint(const CDPoint & rhs);
	virtual ~CDPoint();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CGPointDouble &	GetPoint() const	{	return m_Point;	}
	inline const DOUBLE		GetPointSize() const	{	return m_PointSize;	}
public:
	inline void				SetPoint(const CGPointDouble & iPoint)	{ m_Point = iPoint; }
	inline void				SetPointSize(const DOUBLE iSize)	{ m_PointSize = iSize; }
#pragma endregion

protected:
	const BOOL				IsEqual(const CDPoint & iPoint) const;

#pragma region Fuction of CDComponent
public:
	virtual const BOOL		IsSelected(CDComponentSelect & ioComponentSelect) const;
#pragma endregion

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD	,
		REP_CIRCLE		,
		REP_SPHERE		,
		REP_CUBE		,
	}RepresentationType;
	virtual const INT			Display() const;
protected:
	const INT					DisplayRectangle() const;
	const INT					DisplayCircle() const;
	const INT					DisplaySphere() const;
	const INT					DisplayCube() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDPoint *			Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT			SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDPoint &				operator = (const CDPoint & iPoint);
	void						operator += (const CVector & iVector);
	void						operator -= (const CVector & iVector);
	void						operator *= (const CMatrix3x3 & iMatrix);
	void						operator *= (const CMatrix3x4 & iMatrix);
	const BOOL					operator == (const CDPoint & iPoint) const;
	const BOOL					operator != (const CDPoint & iPoint) const;
#pragma endregion

#pragma region Static Function
public:
	static const CGPointDouble	Get3DCoordnateFromWinPosition(const CGPointDouble & iWinPosition, const BOOL iPerspective);

	static const CGPointInt		GetWinPositionFrom3DCoordinate(const CGPointDouble & iCoordinate);
	static const CGPointDouble	Get3DCoordinateFromWinPosition(const CGPointInt & iWinPosition);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble				m_Point;
	DOUBLE						m_PointSize;
#pragma endregion
};

		}
	}
}