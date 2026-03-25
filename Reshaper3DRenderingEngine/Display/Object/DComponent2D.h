#pragma once

namespace Display
{
	namespace View
	{
		RsDEFINE_CLASS(CDOpenGLScene);
	}

	namespace Object
	{
		RsDEFINE_CLASS(CDComponentSelect);

		namespace Geometry
		{
			RsDEFINE_CLASS(CDGroup);

			namespace Mesh
			{
				RsDEFINE_CLASS(CDOpenGLTable);
			}
		}

		using namespace Display::Object::Geometry;
		using namespace Display::Object::Geometry::Mesh;
		using namespace Display::View;

RsDEFINE_DLL_CLASS(CDComponent2D) : RsINHERITANCE(CDComponent)
{
#pragma region Construction & Destruction
protected:
	CDComponent2D();
	CDComponent2D(LPARAM lParam);
	virtual ~CDComponent2D();
#pragma endregion

#pragma region Setter & Getter function
public:
#pragma endregion

#pragma region Abstract fuction of IDataObject
protected:
	virtual const BOOL	CopyFrom(const CDataObject & iObjectToCopy);
#pragma endregion

#pragma region File Declaration
public:
	virtual const INT	ReadBin(CFileReadObject & file, CProgress * iProgress = NULL);
	virtual const INT	SaveBin(CFileWriteObject & file, CProgress * iProgress = NULL);
	virtual const UINT	GetBlockType() const;
#pragma endregion
};

	}
}