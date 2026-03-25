#pragma once

namespace Display
{

	namespace Object
	{

		namespace Rendering
		{

RsDEFINE_DLL_CLASS(CPolygonOpenGLTable) : RsINHERITANCE(CVBOOpenGLTable)
{
#pragma region Type Definition
public:
#pragma endregion

#pragma region Construction & Destruction
public:
	CPolygonOpenGLTable();
	virtual ~CPolygonOpenGLTable();
#pragma endregion

#pragma region Setter & Getter function
public:
	void				SetVectors(const vector<Coordinate2D> & iVertices, const vector<UINT> & iSeparators);
	void				SetVectorsForRealThickness(const vector<DOUBLE> & iLaserSpotSize, const vector<Coordinate2D> & iVertices, const vector<UINT> & iSeparators);
	void				SetTriangles(const vector<DOUBLE> & iLaserSpotSize, const vector<Coordinate2D> & iVertices, const vector<UINT> & iSeparators);
#pragma endregion

#pragma region Display
public:
	virtual const INT	Display(const UCHAR iOption) const;
#pragma endregion

#pragma region Static function
public:
	
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};

		}
	}
}