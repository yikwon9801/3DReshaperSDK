#pragma once

#include <vector>
#include <map>

using namespace std;

namespace Kernel
{

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
		RsDEFINE_CLASS(CBoundingBox);
	}

	namespace Position
	{

		namespace Nesting
		{

			using namespace Kernel::Object;

struct NestingSize
{
	DOUBLE cx, cy;
	NestingSize() : cx(0.), cy(0.) {}
};

struct NestingRect
{
	void * Data;
	DOUBLE xLower, yLower, xUpper, yUpper;
	NestingRect() : xLower(0.), yLower(0.), xUpper(0.), yUpper(0.), Data(NULL) {}
	const DOUBLE Width() const { return xUpper - xLower; }
	const DOUBLE Height() const { return yUpper - yLower; }
};

RsDEFINE_DLL_CLASS(CBox2DPlacement) : RsINHERITANCE(CDataObject)
{
#pragma region Type Definition
public:
	typedef vector<NestingRect>		RectArray;
	typedef vector<RectArray>		RectArrayArray;
	typedef vector<NestingSize>		SizeArray;
#pragma endregion

#pragma region Construction & Destruction
public:
	CBox2DPlacement(RectArray & iRects, const NestingRect & iDimension);
	CBox2DPlacement(const CBox2DPlacement & iPlacement);
	virtual ~CBox2DPlacement();
#pragma endregion

#pragma region Setter & Getter function
public:
	const RectArrayArray &	GetResult() const { return m_Result; }
#pragma endregion

public:

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL		CopyFrom(const CDataObject & iObjectToCopy);
	virtual CBox2DPlacement *	Clone() const;
#pragma endregion

private:
	void					_CalculatePosition();
	void					_ArrangePosition();

#pragma region Operator Declaration
public:
	const CBox2DPlacement &	operator = (const CBox2DPlacement & iPlacement);
#pragma endregion

#pragma region Static fuction
public:
	static const BOOL		LessthanYSize(const NestingRect & iRect1, const NestingRect & iRect2);
#pragma endregion

#pragma region Memeber Variable
private:
	RectArray &				m_Rects;
	RectArrayArray			m_Result;
	SizeArray				m_Area;
	NestingSize				m_Size;
	NestingRect				m_Dimension;
#pragma endregion
};

		}
	}
}