#pragma once

namespace Display
{

	namespace Object
	{
		RsDEFINE_CLASS(CDComponentSelect);

		namespace Geometry
		{

RsDEFINE_DLL_CLASS(CDSphere) : RsINHERITANCE(CDPoint)
{
#pragma region Construction & Destruction
public:
	CDSphere();
	CDSphere(const CGPointDouble & iPoint);
	CDSphere(const CDSphere & iSphere);
	virtual ~CDSphere();
#pragma endregion

#pragma region Setter & Getter function
#pragma endregion

#pragma region Fuction of CDComponent
public:
	virtual const BOOL		IsSelected(CDComponentSelect & ioComponentSelect) const;
#pragma endregion

#pragma region Abstract fuction of IDisplay
public:
	typedef enum	{
		REP_STANDARD = REP_SPHERE,
	}RepresentationType;

	virtual const INT		Display() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CDSphere *		Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDSphere &		operator = (const CDSphere & iSphere);
	void					operator += (const CVector & iVector);
	void					operator -= (const CVector & iVector);
	const BOOL				operator == (const CDSphere & iSphere) const;
	const BOOL				operator != (const CDSphere & iSphere) const;
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}