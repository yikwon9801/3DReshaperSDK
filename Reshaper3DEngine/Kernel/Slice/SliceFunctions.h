#pragma once

namespace Kernel
{
	namespace Object
	{

		namespace Geometry
		{
			RsDEFINE_CLASS(CGPoint2DInt);
		}
	}

	namespace Slice
	{
		using namespace Kernel::Object;
		using namespace Kernel::Object::Geometry;

		template<typename _DataType> class BoundingBox
		{
		public:
			inline const _DataType	GetCenterPoint() const { return (m_Lower + m_Upper) / 2; }
		public:
			_DataType	m_Lower, m_Upper;
		};
				
		inline const INT64	LengthSqaure(const IntPoint & iPoint) { return iPoint.X*iPoint.X + iPoint.Y*iPoint.Y; }
		inline const INT64	Length(const IntPoint & iPoint) { return (int64_t)sqrt(LengthSqaure(iPoint)); }


RsDEFINE_DLL_CLASS(CSliceFunctions)
{
private:
	CSliceFunctions() {}
public:
	static void			ApplyMatrix(Paths & ioPaths, const CMatrix2x3 & iMatrix);
	static void			ApplyMatrix(Paths & ioPaths, const CMatrix2x2 & iMatrix);
	static void			CalcBoundingBox(const Paths & iPaths, BoundingBox<CGPoint2DInt> & oBoundingBox);
};

	}
}