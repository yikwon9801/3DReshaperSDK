#include "stdafx.h"

namespace Display
{

namespace Object
{

namespace Rendering
{
RsDEFINE_DLL_CLASS(CRendering)
{
public:
	static void			GenBuffers(GLsizei n, GLuint *buffers);
	static void			BindBuffer(GLenum target, GLuint buffer);
	static void			BufferData(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
	static void			BufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
	static void			DeleteBuffers(GLsizei n, const GLuint *buffers);
	static void			GetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
	static GLvoid *		MapBuffer(GLenum target, GLenum access);
	static GLboolean	UnmapBuffer(GLenum target);

	static const BOOL	IsAvailableVBO();
};
}
}
}