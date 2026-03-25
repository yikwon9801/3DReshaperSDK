#pragma once

namespace Kernel
{

	namespace Object
	{
		namespace Geometry
		{
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Position
	{

		namespace Window
		{

			using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CWinPointDouble) : RsINHERITANCE(CGPointDouble)
{

#pragma region Construction & Destruction
public:
	CWinPointDouble();
	CWinPointDouble(const CWinPointDouble & iPoint);
	CWinPointDouble(const CPoint & iPoint);
	virtual ~CWinPointDouble();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CPoint		GetWinPoint() const { return CPoint(_xpos, _ypos); }
	inline const BOOL		IsWinPoint(const CPoint & iPoint) const { return _xpos == iPoint.x && _ypos == iPoint.y; }
public:
	void					Null();
#pragma endregion

#pragma region General Function
public:
	const BOOL				IsNull() const;
protected:
	const BOOL				IsEqual(const CWinPointDouble & iPoint) const;
#pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void			Invert();
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CWinPointDouble *	Clone() const;
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CWinPointDouble &	operator = (const CWinPointDouble & iPoint);
	const BOOL				operator == (const CWinPointDouble & iPoint) const;
	const BOOL				operator != (const CWinPointDouble & iPoint) const;
#pragma endregion

#pragma region Memeber Variable
protected:
	union {
		struct { INT _xpos, _ypos; };
		INT _position[2];
	};
#pragma endregion
};

		}
	}
}