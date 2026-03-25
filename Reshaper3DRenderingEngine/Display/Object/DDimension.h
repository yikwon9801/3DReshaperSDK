#pragma once

namespace Display
{
	namespace Object
	{
		using namespace Display::Object::Geometry;

RsDEFINE_DLL_CLASS(CDDimension) : RsINHERITANCE(CDBoundingBox)
{
#pragma region Construction & Destruction
public:
	CDDimension(const CDimension & iDimension);
	CDDimension(const CDDimension & iDimension);
	virtual ~CDDimension();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const BYTE			GetBitVisible() const	{ return m_BitVisible; }
	inline void					SetBitVisible(const BYTE iBitVisible)	{ m_BitVisible = iBitVisible; }
#pragma endregion
protected:
	virtual const CBoundingBox	GetBoundingBox() const;

#pragma region Display
public:
	typedef enum	{
		REP_STANDARD,
		REP_FACE,
		REP_SHOWDETECTEDFACE,
	}RepresentationType;
protected:
	virtual const INT			Display() const;

	const INT					DisplayShowDetectedFace() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDDimension *		Clone() const;
protected:
	virtual const BOOL			CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT			ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT			SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT			GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CDDimension &			operator = (const CDDimension & iDimension);
	void						operator += (const CVector & iVector);
	void						operator -= (const CVector & iVector);
	void						operator *= (const CMatrix3x3 & iMatrix);
	void						operator *= (const CMatrix3x4 & iMatrix);
#pragma endregion

#pragma region Memeber Variable
private:
#define NUMBEROFFACE	6
	BYTE						m_BitVisible;
#pragma endregion
};


	}
}