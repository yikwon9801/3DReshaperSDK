#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{

			namespace Print
			{

RsDEFINE_DLL_CLASS(CDLaserPaths) : RsINHERITANCE(CDSlicedPolygons2D)
{
#pragma region Construction & Destruction
public:
	CDLaserPaths();
	virtual ~CDLaserPaths();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const INT			GetCurrent() const { return m_Current; }
	inline const COLORREF		GetHighLightColor() const { return m_HighLightColor; }
protected:
	inline const vector<DOUBLE> &	GetLengthBetweenVertices() const { return m_LengthBetweenVertices; }
	inline const BOOL			IsDataForLengthBetweenVertices() const { return (BOOL)m_LengthBetweenVertices.size(); }
public:
	inline void					Init() { InitCurrent(); InitHightLight(); }
	inline void					InitHightLight() { if(m_Polygons) m_HightLightArray.assign(m_Polygons->GetLineCount(), FALSE); }
	inline void					InitCurrent() { m_Current = -1; }
	inline void					SetCurrent(const INT iCurrent) { m_Current = iCurrent; }
	inline void					SetOnlyHighLight(const INT iIndex) { InitHightLight(); m_HightLightArray[iIndex] = TRUE; }
	inline void					SetHighLightColor(const COLORREF iColor) { m_HighLightColor = iColor; }
	inline void					SetSpeedForProgress(const DOUBLE iSpeed) { m_SpeedForProgress = iSpeed; }
	inline void					SetPolygons(CGPolygons2D * iPolygons, const BOOL iNoDeleteBuffer = FALSE) { CDSlicedPolygons2D::SetPolygons(iPolygons, iNoDeleteBuffer); Init(); }
public:
	void						Next();
	void						Prev();
	void						Jump(const INT iJump);

	void						InitProgress();
	void						ExitProgress();
	const INT					Progress(const UINT iMilliseconds);
#pragma endregion

#pragma region Display
public:
	typedef enum {
		REP_LINES ,
		REP_POINTS,
		REP_LINESWITHPOINTS,
		REP_CONTINOUSLINES,
		REP_CONTINOUSLINESWITHPOINTS,
	}RepresentationType;
protected:
	virtual const INT			Display() const;
protected:
	const INT					DisplayLines() const;
	const INT					DisplayPoints() const;
	const INT					DisplayLinesWithPoints() const;
	const INT					DisplayContinousLinesWithPoints() const;
private:
	const INT					_DisplayContinousLines(const BOOL iWithPoint) const;
	const INT					_DisplayContinousLinesWithPointsForProgress() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDLaserPaths *		Clone() const;
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
	const CDLaserPaths &		operator = (const CDLaserPaths & iLaserPaths);
#pragma endregion

#pragma region Static Function
public:
	static LPCTSTR				ToStringForDisplayType(const RepresentationType iType);
#pragma endregion

#pragma region Memeber Variable
protected:
	INT							m_Current;
	vector<BOOL>				m_HightLightArray;
	COLORREF					m_HighLightColor;

	DOUBLE						m_TimeForProgress;
	vector<const Coordinate2D *>	m_StartVertexBetweenVertices;
	vector<DOUBLE>				m_LengthBetweenVertices;
	DOUBLE						m_SpeedForProgress;
#pragma endregion
};

			}
		}
	}
}