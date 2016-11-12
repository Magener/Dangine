#pragma once

#include <GL/glew.h>
#include "vec2.h"
#include "vec2.h"
#include "vec2.h"
#include "mat4.h"
#include "Texture.h"

namespace Dangine 
{
	namespace Graphics 
	{
		
		class Shader 
		{
		public:
			Shader(const char *vertPath, const char *fragPath);
			~Shader();

			void addGeometry(const char *geomPath);

			inline void validate() const 
			{
				glLinkProgram(m_ProgramID);
				glValidateProgram(m_ProgramID);
			}

			inline void enable() const 
			{
				glUseProgram(m_ProgramID);
			}

			inline void disable() const 
			{
				glUseProgram(0);
			}

			GLuint getAttribLocation(const char *name) const;

			GLuint getUniformLocation(const char *name) const;

			void bindAttribute(GLuint index, const char *name) const;

			void loadInt(const char *name, GLint value) const;
			void loadBool(const char *name, GLboolean value) const;
			void loadFloat(const char *name, GLfloat value) const;
			void loadDouble(const char *name, GLdouble value) const;

			void loadTexture(const char *name, const Texture2D& texture) const;

			void loadVector(const char *name, const Maths::vec2& value) const;
			void loadVector(const char *name, const Maths::vec3& value) const;
			void loadVector(const char *name, const Maths::vec4& value) const;
			void loadMatrix(const char *name, const Maths::mat4& value) const;

			inline bool isUsingGeometry() 
			{
				return m_UsingGeometry;
			}

		private:
			GLuint m_ProgramID;
			GLuint m_vShaderID;
			GLuint m_fShaderID;
			GLuint m_gShaderID;
			bool m_UsingGeometry;

		private:
			GLuint loadShader(const char *path, GLenum type);

		};

	}
}
