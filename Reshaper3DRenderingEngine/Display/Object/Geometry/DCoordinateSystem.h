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

RsDEFINE_DLL_CLASS(CDCoordinateSystem) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDCoordinateSystem(const DOUBLE iLineLength, LPARAM lParam);
	CDCoordinateSystem(const CDCoordinateSystem & rhs);
	virtual ~CDCoordinateSystem();
#pragma endregion

#pragma region Setter & Getter function
private:
	const CGPointDouble &	GetOrigin() const;
	const DOUBLE			GetCoordLineLength() const;
public:
	void					SetOrigin(const CGPointDouble & iOrigin);
	void					SetCoordLineLength(const DOUBLE iLineLength);
#pragma endregion

private:
	void					_Init();
	void					_CreateCoordinate();

#pragma region Display
public:
	virtual const INT		Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDCoordinateSystem *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDCoordinateSystem &	operator = (const CDCoordinateSystem & iCoordinateSystem);
#pragma endregion

#pragma region Memeber Variable
private:
#define DIMESION			3
	CDLine					m_Coordinate[DIMESION];
	DOUBLE					m_CoordLineLength;
	CGPointDouble			m_Origin;
#pragma endregion
};

		}
	}
}