#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}

	namespace Object
	{

		namespace Geometry
		{

			using namespace Display::View;

RsDEFINE_DLL_CLASS(CDCoordinateSystem2D) : RsINHERITANCE(CDComponent2D)
{
#pragma region Construction & Destruction
public:
	CDCoordinateSystem2D(const DOUBLE iLineLength, LPARAM lParam);
	CDCoordinateSystem2D(const CDCoordinateSystem2D & rhs);
	virtual ~CDCoordinateSystem2D();
#pragma endregion

#pragma region Setter & Getter function
private:
	inline const CGPoint2DDouble &	GetOrigin() const { return m_Origin; }
	inline const DOUBLE		GetCoordLineLength() const { return m_CoordLineLength; }
	inline const DOUBLE		GetLineWidth() const { return m_LineWidth; }
public:
	inline void				SetOrigin(const CGPointDouble & iOrigin) { m_Origin = iOrigin; }
	inline void				SetCoordLineLength(const DOUBLE iLineLength) { m_CoordLineLength = iLineLength; }
	inline void				SetLineWidth(const DOUBLE width) { m_LineWidth = width; }
#pragma endregion

private:
	void					_Init();

#pragma region Display
public:
	typedef enum {
		REP_STANDARD,
	}RepresentationType;

	virtual const INT		Display() const;
protected:
	const INT				DisplayStandard() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDCoordinateSystem2D *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCoordinateSystem2D &	operator = (const CDCoordinateSystem2D & iCoordinateSystem);
#pragma endregion

#pragma region Memeber Variable
private:
	DOUBLE					m_CoordLineLength;
	DOUBLE					m_LineWidth;
	CGPoint2DDouble			m_Origin;
#pragma endregion
};

		}
	}
}