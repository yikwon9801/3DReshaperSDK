#pragma once

namespace Kernel
{
	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
	}

	namespace Slice
	{
		RsDEFINE_CLASS(CPolygonObject);

		using namespace Kernel::Object;
		using namespace ClipperLib;

RsDEFINE_DLL_CLASS(CPolygonSet) : RsINHERITANCE(CPolygonObject)
{
#pragma region Type Definition
#pragma endregion

#pragma region Construction & Destruction
public:
	CPolygonSet();
	CPolygonSet(const ClipperLib::Paths * iPolygons);
	CPolygonSet(const ClipperLib::Paths & iPolygons);
	CPolygonSet(const CPolygonSet & iPolygonSet);
	virtual ~CPolygonSet();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region General Function
public:
protected:
	const BOOL				IsEqual(const CPolygonSet & iPolygonSet) const;
private:
	const BOOL				IsEntireBoundary() const;
	void					AddEntireBoundary();
	void					RemoveEntireBoundary();
#pragma endregion

#pragma region Mathmatics
public:
	void					Intersection(const CPolygonSet & iPolygonSet);
	void					Union();
	void					Union(const CPolygonSet & iPolygonSet, const DOUBLE iDistanceForCorrection = 0.);
	void					Difference(const CPolygonSet & iPolygonSet);
	void					Complement();
	const BOOL				IsUniversal() const;
	const BOOL				IsEmpty() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CPolygonSet *	Clone() const;
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region Operator Declaration
public:
	const CPolygonSet &		operator = (const CPolygonSet & iPolygonSet);
	const CPolygonSet &		operator = (const ClipperLib::Paths & iPolygons);
	const CPolygonSet 		operator ^ (const CPolygonSet & iPolygonSet) const;
	void					operator ^= (const CPolygonSet & iPolygonSet);
	const CPolygonSet 		operator | (const CPolygonSet & iPolygonSet) const;
	void					operator |= (const CPolygonSet & iPolygonSet);
	const CPolygonSet 		operator - (const CPolygonSet & iPolygonSet) const;
	void					operator -= (const CPolygonSet & iPolygonSet);
	const BOOL				operator == (const CPolygonSet & iPolygonSet) const;
	const BOOL				operator != (const CPolygonSet & iPolygonSet) const;
#pragma endregion

#pragma region Static Functions
public:
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

	}
}