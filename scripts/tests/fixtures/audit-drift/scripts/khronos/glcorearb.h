/* Fixture stand-in for scripts/khronos/glcorearb.h: one block, two prototypes. */
#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glClear (GLbitfield mask);
GLAPI GLenum APIENTRY glGetError (void);
#endif
#endif /* GL_VERSION_1_0 */
