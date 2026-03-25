#pragma once

namespace Display
{

	namespace Object
	{

		namespace Geometry
		{
			namespace Mesh
			{
				RsDEFINE_CLASS(CDOpenGLDisplay);
			}

			using namespace Display::Object::Geometry::Mesh;

RsDEFINE_DLL_CLASS(CDSlicedPolygons2D) : RsINHERITANCE(CDPolygons2D)
{
#pragma region Construction & Destruction
public:
	CDSlicedPolygons2D();
	virtual ~CDSlicedPolygons2D();
#pragma endregion

#pragma region Setter & Getter function
public:
	inline const CSlicedPolygon2D *	GetPolygons() const { return dynamic_cast<const CSlicedPolygon2D *>(CDPolygons2D::GetPolygons()); }
	inline const DOUBLE			GetZ() const { return GetPolygons() ? GetPolygons()->GetZ() : 0.; }
#pragma endregion

#pragma region Display
public:
	typedef enum {
		REP_STANDARD ,
	}RepresentationType;
protected:
	virtual const INT			Display() const;
protected:
	const INT					DisplayLines() const;
#pragma endregion

#pragma region Abstract fuction of IDataObject
public:
	virtual CDSlicedPolygons2D *	Clone() const;
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
	const CDSlicedPolygons2D &	operator = (const CDSlicedPolygons2D & iSlicedPolygons);
#pragma endregion

#pragma region Memeber Variable
private:
#pragma endregion
};


		}
	}
}