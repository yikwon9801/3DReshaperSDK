#pragma once

namespace Kernel
{
	namespace Primitive
	{
		RsDEFINE_CLASS(CRectDouble);
	}

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
		RsDEFINE_CLASS(CVector2D);
		RsDEFINE_CLASS(CMatrix2x2);
		RsDEFINE_CLASS(CMatrix3x3);
		RsDEFINE_CLASS(CMatrix2x3);
		RsDEFINE_CLASS(CMatrix3x4);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDataObject);
		RsDEFINE_CLASS(CDimension);

		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CGPolyhedron);
			}

			RsDEFINE_CLASS(CGPoint2DDouble);
			RsDEFINE_CLASS(CGPointDouble);
			RsDEFINE_CLASS(CGPolygons2D);
			RsDEFINE_CLASS(CGMultiLines);
			RsDEFINE_CLASS(CGCloud);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Primitive;
		using namespace Kernel::Collection;
		using namespace Kernel::Math;
		using namespace Kernel::Util;
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;
		using namespace Kernel::Object::Geometry::Mesh;

#define ROUND_COMPARE_SCALE	3

RsDEFINE_TEMPLATECLASS_TYPENAME(_DataType, CPolygonLayers) : RsINHERITANCE(CGeometryObject)
{
#pragma region Type Definition
public:
	typedef vector<_DataType>	_SlicedPolygons2D;
#pragma endregion

#pragma region Construction & Destruction
protected:
	CPolygonLayers() {}
	CPolygonLayers(const CPolygonLayers<_DataType> & iPolygonLayers) { operator = (iPolygonLayers); }
	virtual ~CPolygonLayers() {}
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const _SlicedPolygons2D & GetSlicedPolygons() const { return m_SlicedPolygons; }
	inline _SlicedPolygons2D & SlicedPolygons() { return m_SlicedPolygons; }
	inline const UINT GetLayerCount() const { return (UINT)m_SlicedPolygons.size(); }
public:
	const _DataType & GetPolygons(const UINT iIndex) const { return m_SlicedPolygons[iIndex]; }
	const INT FindPolygons(const DOUBLE iZ) const
	{
		const DOUBLE iFindZ = CMath::Round(iZ, ROUND_COMPARE_SCALE);

		for (INT ii = 0; ii < (INT)m_SlicedPolygons.size(); ii++)
		{
			const DOUBLE iZToCompare = CMath::Round(m_SlicedPolygons[ii].GetZ(), ROUND_COMPARE_SCALE);
			if (iFindZ < iZToCompare) break;

			if (iFindZ == iZToCompare)
				return ii;
		}

		return -1;
	}
	const INT FindLowerPolygons(const DOUBLE iZ) const
	{
		const DOUBLE iFindZ = CMath::Round(iZ, ROUND_COMPARE_SCALE);
		INT nFind = -1;
		for (INT ii = 0; ii < (INT)m_SlicedPolygons.size(); ii++)
		{
			const DOUBLE iZToCompare = CMath::Round(m_SlicedPolygons[ii].GetZ(), ROUND_COMPARE_SCALE);
			if (iFindZ < iZToCompare) break;

			nFind = ii;
		}

		return nFind;
	}
	const INT CutMaxLayer(const UINT iMaxLayer)
	{
		const UINT iLayerCount = (UINT)m_SlicedPolygons.size();
		if (iLayerCount <= iMaxLayer) return 1;
		
		m_SlicedPolygons.erase(m_SlicedPolygons.begin() + iMaxLayer, m_SlicedPolygons.begin() + iLayerCount - 1);

		return 0;
	}
	void CutLimitHeight(const DOUBLE iZ)
	{
		const DOUBLE iFindZ = CMath::Round(iZ, ROUND_COMPARE_SCALE);
		const INT nLayerCount = (INT)m_SlicedPolygons.size();
		for (INT ii = nLayerCount - 1; ii >= 0; ii--)
		{
			const CSlicedPolygon2D & iSlicedPolygon = m_SlicedPolygons[ii];

			const DOUBLE iZToCompare = CMath::Round(iSlicedPolygon.GetZ(), ROUND_COMPARE_SCALE);

			if (iFindZ < iZToCompare)
				m_SlicedPolygons.erase(m_SlicedPolygons.begin() + ii);
			else
				break;
		}
	}
#pragma endregion

#pragma region General Function
public:
	void Get(CGCloud * oClound) const
	{
		ASSERT(oClound);
		oClound->Clear();

		INT nVertexCount = 0;
		const INT nLayerCount = (INT)m_SlicedPolygons.size();
		for (INT ii = 0; ii < nLayerCount; ii++)
		{
			const CSlicedPolygon2D & iSlicedPolygon = m_SlicedPolygons[ii];

			nVertexCount += iSlicedPolygon.GetVertexCount();
		}

		CTableArray<CGVertex> iPoints(nVertexCount);
		nVertexCount = 0;
		for (INT ii = 0; ii < nLayerCount; ii++)
		{
			const CSlicedPolygon2D & iSlicedPolygon = m_SlicedPolygons[ii];
			const DOUBLE iZ = iSlicedPolygon.GetZ();

			const CGPolygon2D::_VertexVector & vertices = iSlicedPolygon.GetVertices();

			for (INT jj = 0; jj < (INT)vertices.size(); jj++)
			{
				const Coordinate2D & v1 = vertices[jj];
				CGVertex & v2 = iPoints[jj + nVertexCount];

				v2._xx = v1._xx;
				v2._yy = v1._yy;
				v2._zz = iZ;
			}

			nVertexCount += iSlicedPolygon.GetVertexCount();
		}

		oClound->SetPoints(iPoints);
	}
	void Get(CGMultiLines * oMultiLines) const
	{
		vector<CGMultiLine *> iMultiLines;

		const UINT nLayerCount = (INT)m_SlicedPolygons.size();
		for (UINT ii = 0; ii < nLayerCount; ii++)
		{
			const CSlicedPolygon2D & iSlicedPolygon = m_SlicedPolygons[ii];

			vector<CGMultiLine *> temp;
			iSlicedPolygon.Get(temp);
			iMultiLines.insert(iMultiLines.end(), temp.begin(), temp.end());

		}

		oMultiLines->AddMultiLines(iMultiLines, FALSE);
	}
	void Set(const CTableList<const CPolygonLayers<_DataType> *> & iTableSlicedPolygons)
	{
		Clear();

		list<const CPolygonLayers<_DataType> *> iListSlicedPolygons = iTableSlicedPolygons.GetList();
		if (!iListSlicedPolygons.size()) return;

		vector<DOUBLE> iLayerThickness;
		CPolygonLayers<_DataType>::GetLayerThickness(iListSlicedPolygons, iLayerThickness);

		m_SlicedPolygons.resize(iLayerThickness.size());

		map<DOUBLE, _DataType *> mapSlice;
		for (UINT ii = 0; ii < (UINT)iLayerThickness.size(); ii++)
		{
			_DataType * iSlicePolygon = &m_SlicedPolygons[ii];
			iSlicePolygon->SetZ(iLayerThickness[ii]);
			mapSlice.insert(pair<DOUBLE, _DataType *>(iLayerThickness[ii], iSlicePolygon));
		}

		for (list<const CPolygonLayers<_DataType> *>::const_iterator it = iListSlicedPolygons.begin(); it != iListSlicedPolygons.end(); it++)
		{
			const CPolygonLayers<_DataType> * iSlicedPolygons = *it;

			const INT nLayerCount = (INT)iSlicedPolygons->m_SlicedPolygons.size();
			for (INT ii = 0; ii < nLayerCount; ii++)
			{
				const _DataType & iSlicedPolygon = iSlicedPolygons->m_SlicedPolygons[ii];

				mapSlice[CMath::Round(iSlicedPolygon.GetZ(), ROUND_COMPARE_SCALE)]->AddPolygons(iSlicedPolygon);
			}
		}
	}
	void GetLayerThickness(vector<DOUBLE> & oLayerThickness) const
	{
		const UINT nCount = (UINT)m_SlicedPolygons.size();

		if (!nCount) return;
		oLayerThickness.resize(nCount);

		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			oLayerThickness[ii] = CMath::Round(m_SlicedPolygons[ii].GetZ(), ROUND_COMPARE_SCALE);
	}
	void GetLayerThickness(vector<vector<DOUBLE>> & oLayerThickness) const
	{
		const UINT nCount = (UINT)m_SlicedPolygons.size();

		if (!nCount) return;

		oLayerThickness.push_back(vector<DOUBLE>());

		DOUBLE dPreGap = 0.;
		vector<DOUBLE> * newList = &oLayerThickness.back();
		newList->push_back(CMath::Round(m_SlicedPolygons[0].GetZ(), ROUND_COMPARE_SCALE));
		BOOL bFirst = TRUE;
		for (UINT ii = 1; ii < nCount; ii++)
		{
			const DOUBLE dGap = CMath::Round(m_SlicedPolygons[ii].GetZ(), ROUND_COMPARE_SCALE) - CMath::Round(m_SlicedPolygons[ii - 1].GetZ(), ROUND_COMPARE_SCALE);
			if (bFirst) dPreGap = dGap;
			if (CMath::Round(dPreGap, ROUND_COMPARE_SCALE) != CMath::Round(dGap, ROUND_COMPARE_SCALE))
			{
				oLayerThickness.push_back(vector<DOUBLE>());
				dPreGap = dGap;
				newList = &oLayerThickness.back();
				bFirst = TRUE;
			}
			else
				bFirst = FALSE;
			newList->push_back(dGap);
		}
	}
 	
	void Clear() { m_SlicedPolygons.clear(); }
	void ClearPolygons()
	{
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].Clear();
	}
	void ClearPolygons(const UINT iType)
	{
		switch (iType)
		{
		case 1:			ClearPolygons();	break;
		default:		Clear();			break;
		}
	}
 	void Resize(const UINT iSize) { m_SlicedPolygons.resize(iSize); }

	void SetZ(const vector<DOUBLE> & iSlicingHeight)
	{
		ASSERT((UINT)iSlicingHeight.size() == GetLayerCount());
		if (GetLayerCount() != (UINT)iSlicingHeight.size()) return;

		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].SetZ(iSlicingHeight[ii]);
	}
	void Chain(const UINT8 iType = 0, const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet())
	{
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].Chain(iType, iAccuracy);
	}
	const INT ConnectOverlappedOnlyParallelVector2D(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet(), CProgress * iProgress = NULL)
	{
		INT nRet = 0;
		const UINT nCount = (UINT)m_SlicedPolygons.size();
		for (UINT ii = 0; ii < nCount; ii++)
		{
			if (nRet = m_SlicedPolygons[ii].ConnectOverlappedOnlyParallelVector2D(iAccuracy))
				return nRet;

			if (iProgress)	iProgress->Progress((DOUBLE)(ii + 1) / (DOUBLE)nCount);
		}
		return nRet;
	}
	const INT ChangeVector2DPositiveDirection(const CVector2D & iDirection)
	{
		INT nRet = 0;
		const UINT nCount = (UINT)m_SlicedPolygons.size();
		for (UINT ii = 0; ii < nCount; ii++)
		{
			if (nRet = m_SlicedPolygons[ii].ChangeVector2DPositiveDirection(iDirection))
				return nRet;
		}
		return nRet;
	}
	const INT ChangeVector2DOrdering(const CVector2D iDirection)
	{
		INT nRet = 0;
		const UINT nCount = (UINT)m_SlicedPolygons.size();
		for (UINT ii = 0; ii < nCount; ii++)
		{
			if (nRet = m_SlicedPolygons[ii].ChangeVector2DOrdering(iDirection))
				return nRet;
		}
		return nRet;
	}
	void SetZ(const vector<FLOAT> & iSlicingHeight)
	{
		ASSERT((UINT)iSlicingHeight.size() == GetLayerCount());
		if (GetLayerCount() != (UINT)iSlicingHeight.size()) return;

		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].SetZ((DOUBLE)iSlicingHeight[ii]);
	}

	void MakeAllThickness(const DOUBLE iThickness)
	{
		for (UINT ii = 0; ii < (UINT)m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].SetZ(iThickness * (DOUBLE)(ii + 1));
	}

	void AddPolygons(const CPolygonLayers<_DataType> & iSlicedPolygons)
	{
		const CPolygonLayers< _DataType>::_SlicedPolygons2D & iPolygonList = iSlicedPolygons.GetSlicedPolygons();
		if (!m_SlicedPolygons.size())
		{
			m_SlicedPolygons = iPolygonList;
			return;
		}

		for (CPolygonLayers< _DataType>::_SlicedPolygons2D::const_iterator it = iPolygonList.begin(); it != iPolygonList.end(); it++)
		{
			const _DataType & iPolygons = *it;

			const INT nFind = FindPolygons(iPolygons.GetZ());
			if (nFind < 0)
			{
				if (m_SlicedPolygons.size())
					InsertAt(FindLowerPolygons(iPolygons.GetZ()) + 1, iPolygons, FALSE);
				else
					m_SlicedPolygons.push_back(iPolygons);
			}
			else
			{
				m_SlicedPolygons[nFind].AddPolygons(iPolygons);
			}
		}
	}
	const BOOL InsertAt(const UINT nIndex, const DOUBLE iZ, const CGMultiLine & iLine, const BOOL iZShift = TRUE)
	{
		if (nIndex > (UINT)m_SlicedPolygons.size()) return FALSE;

		m_SlicedPolygons.insert(m_SlicedPolygons.begin() + nIndex, _DataType(iZ, iLine));

		if (iZShift)
		{
			for (UINT ii = nIndex + 1; ii < (UINT)m_SlicedPolygons.size(); ii++)
			{
				_DataType & SlicePolygon2D = m_SlicedPolygons[ii];
				SlicePolygon2D.SetZ(SlicePolygon2D.GetZ() + iZ);
			}
		}

		return TRUE;
	}
	const BOOL InsertAt(const UINT nIndex, const CPolygonLayers<_DataType> & iSlicePolygons2D, const BOOL iZShift = TRUE)
	{
		const _SlicedPolygons2D & SlicePolygons = iSlicePolygons2D.GetSlicedPolygons();
		const UINT nCount = (UINT)SlicePolygons.size();

		if (!nCount) return FALSE;
		if (nIndex > (UINT)m_SlicedPolygons.size()) return FALSE;

		m_SlicedPolygons.insert(m_SlicedPolygons.begin() + nIndex, SlicePolygons.begin(), SlicePolygons.end());

		if (iZShift)
		{
			DOUBLE iStartShiftZ = 0.;
			DOUBLE iEndShiftZ = m_SlicedPolygons[nIndex + nCount - 1].GetZ();
			if (nIndex)
			{
				const DOUBLE ShiftZ = m_SlicedPolygons[nIndex - 1].GetZ();
				for (UINT ii = nIndex; ii < nCount + nIndex; ii++)
				{
					_DataType & SlicePolygon2D = m_SlicedPolygons[ii];
					SlicePolygon2D.SetZ(SlicePolygon2D.GetZ() + ShiftZ);
				}
			}
			for (UINT ii = nIndex + nCount; ii < (UINT)m_SlicedPolygons.size(); ii++)
			{
				_DataType & SlicePolygon2D = m_SlicedPolygons[ii];
				SlicePolygon2D.SetZ(SlicePolygon2D.GetZ() + iEndShiftZ);
			}
		}

		return TRUE;
	}
	const BOOL InsertAt(const UINT nIndex, const _DataType & iSlicePolygon2D, const BOOL iZShift = TRUE)
	{
		if (nIndex > (UINT)m_SlicedPolygons.size()) return FALSE;

		m_SlicedPolygons.insert(m_SlicedPolygons.begin() + nIndex, iSlicePolygon2D);
		if (iZShift)
		{
			const DOUBLE iZ = iSlicePolygon2D.GetZ();
			for (UINT ii = nIndex + 1; ii < (UINT)m_SlicedPolygons.size(); ii++)
			{
				_DataType & SlicePolygon2D = m_SlicedPolygons[ii];
				SlicePolygon2D.SetZ(SlicePolygon2D.GetZ() + iZ);
			}
		}

		return TRUE;
	}

	const BOOL RemoveAt(const UINT nIndex, const UINT nCountToRemove, const BOOL iZShift = TRUE)
	{
		if (m_SlicedPolygons.size() <= nIndex + nCountToRemove) return FALSE;

		DOUBLE iEndShiftZ = m_SlicedPolygons[nIndex + nCountToRemove - 1].GetZ();

		m_SlicedPolygons.erase(m_SlicedPolygons.begin() + nIndex, m_SlicedPolygons.begin() + nIndex + nCountToRemove);

		if (iZShift)
		{
			for (UINT ii = nIndex; ii < (UINT)m_SlicedPolygons.size(); ii++)
			{
				CSlicedPolygon2D & SlicePolygon2D = m_SlicedPolygons[ii];
				SlicePolygon2D.SetZ(SlicePolygon2D.GetZ() - iEndShiftZ);
			}
		}

		return TRUE;
	}

	void RemoveEmptyPolygon(const BOOL iUpper, const DOUBLE iOffsetDisnce = 0.)
	{
		const INT nLayerCount = (INT)m_SlicedPolygons.size();

		if (iUpper)
		{
			for (INT ii = nLayerCount - 1; ii >= 0; ii--)
			{
				if (iOffsetDisnce)
				{
					_DataType iSlicePolygon2D = m_SlicedPolygons[ii];
					iSlicePolygon2D.Offset(iOffsetDisnce, 2);
					if (iSlicePolygon2D.GetLineCount())
						break;

					m_SlicedPolygons.erase(m_SlicedPolygons.begin() + ii);
				}
				else
				{
					if (m_SlicedPolygons[ii].GetLineCount())
						break;

					m_SlicedPolygons.erase(m_SlicedPolygons.begin() + ii);
				}
			}
		}
		else
		{
			list<INT> remove;
			for (INT ii = 0; ii < nLayerCount; ii++)
			{
				if (iOffsetDisnce)
				{
					_DataType iSlicePolygon2D = m_SlicedPolygons[ii];
					iSlicePolygon2D.Offset(iOffsetDisnce, 2);
					if (iSlicePolygon2D.GetLineCount())
						break;
					else
						remove.push_back(ii);
				}
				else
				{
					if (m_SlicedPolygons[ii].GetLineCount())
						break;
					else
						remove.push_back(ii);
				}
			}

			for (list<INT>::const_reverse_iterator it = remove.rbegin(); it != remove.rend(); it++)
				m_SlicedPolygons.erase(m_SlicedPolygons.begin() + *it);
		}
	}

	void RemoveDuplicateCoordinate(const DOUBLE iAccuracy = CGPoint2DDouble::AbsoluteAccuracyGet())
	{
		for (UINT ii = 0; ii < (UINT)m_SlicedPolygons.size(); ii++)
		{
			_DataType & SlicePolygon2D = m_SlicedPolygons[ii];
			SlicePolygon2D.RemoveDuplicateCoordinate(iAccuracy);
		}
	}

	const INT GetUsableSlice(const UINT iStartIndex = 0) const
	{
		INT nRet = -1;
		const UINT nCount = (UINT)m_SlicedPolygons.size();
		ASSERT(iStartIndex < nCount);
		if (iStartIndex >= nCount) return nRet;

		_SlicedPolygons2D & ThisSlicePolygons = const_cast<_SlicedPolygons2D &>(m_SlicedPolygons);

		for (UINT ii = iStartIndex; ii < nCount; ii++)
		{
			const CSlicedPolygon2D & iSlicedPolygon = ThisSlicePolygons[ii];
			if (iSlicedPolygon.GetVertices().size() >= 2)
			{
				nRet = (INT)ii;
				break;
			}
		}

		return nRet;
	}
	const DOUBLE GetUppermostZ() const
	{
		return m_SlicedPolygons.size() ? m_SlicedPolygons[m_SlicedPolygons.size() - 1].GetZ() : 0.;
	}
	const DOUBLE GetLowestZ(const BOOL iEstimateZ = FALSE) const
	{
		return iEstimateZ && m_SlicedPolygons.size() > 1 ? m_SlicedPolygons[0].GetZ() - (m_SlicedPolygons[1].GetZ() - m_SlicedPolygons[0].GetZ()) : m_SlicedPolygons[0].GetZ();
	}

protected:
	const BOOL IsEqual(const CPolygonLayers<_DataType> & iSlicedPolygons) const
	{
		if (m_SlicedPolygons.size() != iSlicedPolygons.m_SlicedPolygons.size()) return FALSE;
		for (UINT ii = 0; ii < (UINT)m_SlicedPolygons.size(); ii++)
		{
			if (m_SlicedPolygons[ii] != iSlicedPolygons.m_SlicedPolygons[ii])
				return FALSE;
		}

		return TRUE;
	}
#pragma endregion
 
#pragma region CAD Functions
public:
	void Union(CProgress * iProgress = NULL)
	{
		const UINT nCount = (UINT)m_SlicedPolygons.size();
		for (UINT ii = 0; ii < nCount; ii++)
		{
			m_SlicedPolygons[ii].Union();

			if (iProgress) iProgress->Progress((DOUBLE)(ii + 1) / (DOUBLE)nCount);
		}
	}
	void Offset(const DOUBLE iOffsetDistance, const UINT16 iOption = 0)
	{
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].Offset(iOffsetDistance, iOption);
	}
	void Intersect(const CGPolygons2D & iPolygons)
	{
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].Intersect(iPolygons);
	}
 
	void Reduce(const UINT16 iType, const DOUBLE iTolerance = 0.)
	{
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].Reduce(iType, iTolerance);
	}
	void ReduceJuttedAndLength(const DOUBLE iJuttedTolerance, const DOUBLE iLengthTolerance)
	{
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].ReduceJuttedAndLength(iJuttedTolerance, iLengthTolerance);
	}

	void MoveZ(const DOUBLE iZ)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
		{
			CSlicedPolygon2D & iSlicedPolygon = *it;

			iSlicedPolygon.SetZ(iSlicedPolygon.GetZ() + iZ);
		}
	}

	void Solid(const DOUBLE iThickness, const UINT iSolidType = 0, const BOOL iChain = FALSE)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
		{
			_DataType & iSlicedPolygon = *it;

			iSlicedPolygon.Solid(iThickness, iSolidType, iChain);
		}
	}
 
	CGPolyhedron * Reconstruct(const UINT iCreteriaSliceNumber, CProgress * iProgress = NULL) const
	{
		UINT nStepCount = 5;
		if (m_SlicedPolygons.size() > iCreteriaSliceNumber)
			nStepCount = (UINT)(m_SlicedPolygons.size() / iCreteriaSliceNumber);

		const DOUBLE iThickness = 0.1 * (DOUBLE)nStepCount;
		CGPolyhedron * oResult = new CGPolyhedron;
		CTableList<const CGPolyhedron *> tablePolyhedrons;
		for (UINT ii = 0; ii < (UINT)m_SlicedPolygons.size(); ii++)
		{
			if ((ii % nStepCount)) continue;

			_DataType iSlicedPolygon = m_SlicedPolygons[ii];
			iSlicedPolygon.Union();

			const DOUBLE iZ = iSlicedPolygon.GetZ();
			CGPolyhedron * LowerPoly = iSlicedPolygon.Reconstruct2D();
			CGPolyhedron * UpperPoly = LowerPoly->Clone();

			CTableList<const CGPolyhedron *> iPolyTable;

			CVector iTranslate(0, 0, 1);

			*LowerPoly += iTranslate * iZ;
			*UpperPoly += iTranslate * (iZ - iThickness);
			UpperPoly->InvertNormal();

			iPolyTable.Add((const CGPolyhedron *&)LowerPoly);
			iPolyTable.Add((const CGPolyhedron *&)UpperPoly);

			CGMultiLines multilines;
			iSlicedPolygon.Get(multilines);

			const CGMultiLines::_MultiLineVector & MultiLines = multilines.GetMutiLines();
			for (CGMultiLines::_MultiLineVector::const_iterator it = MultiLines.begin(); it != MultiLines.end(); it++)
			{
				CGMultiLine * iLine1 = *it;
				CGMultiLine * iLine2 = iLine1->Clone();
				*iLine2 += iTranslate * -iThickness;

				CTableArray<CGMultiLine *> iLines(2);
				iLines[0] = iLine2;
				iLines[1] = iLine1;

				CGPolyhedron * iPolyhedron = CGMultiLine::CreateMeshWithLines(iLines);
				iPolyTable.Add((const CGPolyhedron *&)iPolyhedron);

				delete iLine2;
			}

			CGPolyhedron * result = new CGPolyhedron;
			result->Compound(iPolyTable);

			const UINT nPolyCount = (UINT)iPolyTable.Size();
			for (UINT ii = 0; ii < nPolyCount; ii++)
				delete iPolyTable[ii];

			tablePolyhedrons.Add((const CGPolyhedron *&)result);

			if (iProgress)
				iProgress->Progress((DOUBLE)ii / (DOUBLE)m_SlicedPolygons.size());
		}

		oResult->Compound(tablePolyhedrons);

		const UINT nPolyCount = (UINT)tablePolyhedrons.Size();
		for (UINT ii = 0; ii < nPolyCount; ii++)
			delete tablePolyhedrons[ii];

		if (iProgress)
			iProgress->Progress(1.);

		return oResult;
	}
#pragma endregion

#pragma region BoundingBox & Centeroid
public:
	const CBoundingBox GetVolumeBoundingBox() const
	{
		CBoundingBox result = GetBoundingBox();
		result.SetMinZ(GetLowestZ(TRUE));

		return result;
	}
public:
	virtual const CBoundingBox GetBoundingBox() const
	{
		CBoundingBox boundingBox(DBL_MAX, DBL_MAX, DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX);

		const INT nLayerCount = (INT)m_SlicedPolygons.size();
		for (INT ii = 0; ii < nLayerCount; ii++)
		{
			const CSlicedPolygon2D & iSlicedPolygon = m_SlicedPolygons[ii];

			boundingBox += iSlicedPolygon.GetBoundingBox3D();
		}

		return boundingBox;
	}
#pragma endregion
 
// #pragma region Read & Write 3D File
// public:
// 	const BOOL				ReadSliceFile(const LPCTSTR lpStrFilePath, CProgress * iProgress = NULL);
// #pragma endregion

#pragma region Abstract fuction of CGeometryObject
public:
	virtual void Invert()
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			(*it).Invert();
	}
#pragma endregion
 
#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL CopyFrom(const CDataObject & iObjectToCopy)
	{
		if (!CGeometryObject::CopyFrom(iObjectToCopy)) return FALSE;

		const CPolygonLayers<_DataType> * pData = dynamic_cast<const CPolygonLayers<_DataType> *>(&iObjectToCopy);
		ASSERT(pData);
		if (!pData)	return FALSE;

		m_SlicedPolygons		= pData->m_SlicedPolygons;

		return TRUE;
	}
#pragma endregion

#pragma region File Declaration
public:
protected:
	const INT ReadPolygons(CFileReadObject & file, CProgress * iProgress = NULL)
	{
		UINT nCount = 0;
		file >> nCount;
		if (!nCount)	return 0;

		INT ret = 0;
		m_SlicedPolygons.resize(nCount);
		for (UINT ii = 0; ii < nCount; ii++)
		{
			if (ret = FileReadManagedObj(file, m_SlicedPolygons[ii], iProgress))
				return ret;
		}

		return 0;
	}
	const INT SavePolygons(CFileWriteObject & file, CProgress * iProgress = NULL)
	{
		const UINT nCount = (const UINT)m_SlicedPolygons.size();
		file << nCount;

		INT ret = 0;
		for (UINT ii = 0; ii < nCount; ii++)
		{
			if (ret = FileWriteManagedObj(file, m_SlicedPolygons[ii], iProgress))
				return ret;
		}

		return 0;
	}
#pragma endregion

#pragma region Operator Declaration
public:
	void operator += (const CVector2D & iVector)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			*it += iVector;
	}
	void operator += (const CPolygonLayers<_DataType> & iSlicedPolygons)
	{
		ASSERT(iSlicedPolygons.GetLayerCount() == GetLayerCount());
		if (GetLayerCount() != iSlicedPolygons.GetLayerCount()) return;

#if PARALLEL_METHOD == PARALLEL_GENERAL
		for (UINT ii = 0; ii < m_SlicedPolygons.size(); ii++)
			m_SlicedPolygons[ii].AddPolygons(iSlicedPolygons.m_SlicedPolygons[ii]);
#elif PARALLEL_METHOD == PARALLEL_OPENMP
		INT ii = 0;
		INT nCount = (INT)m_SlicedPolygons.size();
#pragma omp parallel for private(ii)
		for (ii = 0; ii < nCount; ii++)
			m_SlicedPolygons[ii].AddPolygons(iSlicedPolygons.m_SlicedPolygons[ii]);
#endif
	}
	void operator -= (const CVector2D & iVector)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			*it -= iVector;
	}
	void operator *= (const DOUBLE iValue)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			*it *= iValue;
	}
	void operator *= (const CMatrix2x2 & iMatrix)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			*it *= iMatrix;
	}
	void operator *= (const CMatrix2x3 & iMatrix)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			*it *= iMatrix;
	}
	void operator /= (const DOUBLE iValue)
	{
		for (_SlicedPolygons2D::iterator it = m_SlicedPolygons.begin(); it != m_SlicedPolygons.end(); it++)
			*it /= iValue;
	}
 #pragma endregion

#pragma region Static Functions
public:
	static void	GetLayerThickness(const list<const CPolygonLayers<_DataType> *> & iSlicedPolygonsList, vector<DOUBLE> & oLayerThickness)
	{
		vector<DOUBLE> tmp;
		set<DOUBLE> resultSet;
		for (list<const CPolygonLayers<_DataType> *>::const_iterator it = iSlicedPolygonsList.begin(); it != iSlicedPolygonsList.end(); it++)
		{
			const CPolygonLayers<_DataType> * iSlicedPolygons = *it;

			iSlicedPolygons->GetLayerThickness(tmp);

			for (UINT ii = 0; ii < (UINT)tmp.size(); ii++)
				resultSet.insert(CMath::Round(tmp[ii], ROUND_COMPARE_SCALE));
			//resultSet.insert(tmp.begin(), tmp.end());
		}

		oLayerThickness.insert(oLayerThickness.end(), resultSet.begin(), resultSet.end());
	}
 	static const INT SearchUnderZIndexInVectorArray(const vector<DOUBLE> & iArray, const DOUBLE iZ)
	{
		const DOUBLE iFindZ = CMath::Round(iZ, ROUND_COMPARE_SCALE);
		INT nFindIndex = -1;
		for (INT ii = 0; ii < (INT)iArray.size(); ii++)
		{
			const DOUBLE iZToCompare = CMath::Round(iArray[ii], ROUND_COMPARE_SCALE);
			if (iFindZ <= iZToCompare) break;

			nFindIndex = ii;
		}

		return nFindIndex;
	}
	static void	ConvertTo(const vector<DOUBLE> & input, vector<vector<DOUBLE>> & output)
	{
		const UINT nCount = (UINT)input.size();

		if (!nCount) return;

		DOUBLE dPreGap = 0.;
		vector<DOUBLE> * newList = NULL;
		for (UINT ii = 0; ii < nCount; ii++)
		{
			const DOUBLE dGap = ii ? CMath::Round(input[ii], ROUND_COMPARE_SCALE) - CMath::Round(input[ii - 1], ROUND_COMPARE_SCALE) : CMath::Round(input[ii], ROUND_COMPARE_SCALE);
			if (CMath::Round(dPreGap, ROUND_COMPARE_SCALE) != CMath::Round(dGap, ROUND_COMPARE_SCALE))
			{
				output.push_back(vector<DOUBLE>());
				dPreGap = dGap;
				newList = &output.back();
			}
			newList->push_back(dGap);
		}
	}
 #pragma endregion

#pragma region Memeber Variable
protected:
	_SlicedPolygons2D		m_SlicedPolygons;
#pragma endregion
};

#undef ROUND_COMPARE_SCALE

	}
}