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

RsDEFINE_DLL_CLASS(CDRuler) : RsINHERITANCE(CDComponent3D)
{
#pragma region Construction & Destruction
public:
	CDRuler(LPARAM lParam);
	CDRuler(const CDRuler & rhs);
	virtual ~CDRuler();
#pragma endregion

#pragma region Setter & Getter function
public:
	const CGPointDouble &	GetDeparture() const;
	const CGPointDouble &	GetArrival() const;
	const CVector &			GetUpDirection() const;
protected:
	const DOUBLE			GetUpLength() const;
	const CGPointDouble &	GetTextPosition() const;
public:
	void					SetLocation(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	void					SetUpDirection(const CVector & iVector);
	void					SetUpLength(const DOUBLE iLength);

	void					SetTextPosition(const CGPointDouble & iPosition);
public:
	const CVector			GetDirection() const;
#pragma endregion

#pragma region Display
public:
	virtual const INT		Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDRuler *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDRuler &			operator = (const CDRuler & iRuler);
#pragma endregion

#pragma region Memeber Variable
private:
	CGPointDouble			m_Departure;
	CGPointDouble			m_Arrival;
	CGPointDouble			m_TextPosition;

	CVector					m_Up;
	DOUBLE					m_UpLength;
#pragma endregion
};

		}
	}
}