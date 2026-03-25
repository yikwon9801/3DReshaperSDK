#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDLine) : RsINHERITANCE(CDMultiLine)
{
#pragma region Construction & Destruction
public:
	CDLine();
	CDLine(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);
	CDLine(const CDLine & rhs);
	CDLine(const CGLine & iLine);
	virtual ~CDLine();
#pragma endregion

public:
	void					Init(const CGPointDouble & iDeparture, const CGPointDouble & iArrival);

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD			= CDMultiLine::REP_STANDARD,
		REP_STANDARDINCLUDETEXT = CDMultiLine::REP_STANDARDINCLUDETEXT,
	}RepresentationType;

	virtual const INT		Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDLine *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDLine &			operator = (const CDLine & iLine);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	void					operator *= (const CMatrix3x3 & iMatrix);
	void					operator *= (const CMatrix3x4 & iMatrix);
	const BOOL				operator == (const CDLine & iLine) const;
	const BOOL				operator != (const CDLine & iLine) const;
#pragma endregion
};

		}
	}
}