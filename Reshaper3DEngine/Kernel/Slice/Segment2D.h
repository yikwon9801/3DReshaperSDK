#pragma once

namespace Kernel
{
	namespace Util
	{
		RsDEFINE_CLASS(CProgress);
	}

	namespace Collection
	{
		template<typename _DataType> class CTableArray;
		template<typename _DataType> class CTableList;
	}

	namespace Math
	{
		RsDEFINE_CLASS(CVector);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

RsDEFINE_DLL_CLASS(CSegment2D) : RsINHERITANCE(CGSegment2D)
{
#pragma region Construction & Destruction
public:
	CSegment2D(const DOUBLE iX1, const DOUBLE iY1, const DOUBLE iX2, const DOUBLE iY2, const INT iFaceIdx);
	CSegment2D(const CSegment2D & iSegment);
	virtual ~CSegment2D();
protected:
	CSegment2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const INT		GetFaceIndex() const { return m_FaceIdx; }
#pragma endregion

public:
	const BOOL				IsEqual(const CSegment2D & iSegment) const;

#pragma region Abstract fuction of IDataObject
public:
	virtual CSegment2D *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT		ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT		SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT		GetBlockType() const;
#pragma endregion

#pragma region Operator Declaration
public:
	const CSegment2D &		operator = (const CSegment2D & iSegment);
	const BOOL				operator == (const CSegment2D & iSegment) const;
	const BOOL				operator != (const CSegment2D & iSegment) const;
#pragma endregion

#pragma region Static fuction
#pragma endregion

#pragma region Memeber Variable
private:
	INT						m_FaceIdx;
#pragma endregion
};

	}
}