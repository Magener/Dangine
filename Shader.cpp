#include "Shader.h"
#include "FileUtils.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Dangine 
{
	namespace Graphics 
	{
	
		Shader::Shader(const char *vertPath, const char *fragPath) : m_UsingGeometry(false) 
		{
			
			m_vShaderID = loadShader(vertPath, GL_VERTEX_SHADER);
			m_fShaderID = loadShader(fragPath, GL_FRAGMENT_SHADER);
			m_ProgramID = glCreateProgram();


			glAttachShader(m_ProgramID, m_vShaderID);
			glAttachShader(m_ProgramID, m_fShaderID);
		}

		Shader::~Shader() 
		{
			disable();

			glDetachShader(m_ProgramID, m_vShaderID);
			glDetachShader(m_ProgramID, m_fShaderID);
			if (m_UsingGeometry) 
			{
				glDetachShader(m_ProgramID, m_gShaderID);
				glDeleteShader(m_gShaderID);
			}
			glDeleteShader(m_vShaderID);
			glDeleteShader(m_fShaderID);
			glDeleteProgram(m_ProgramID);

		}
		
		void Shader::addGeometry(const char *geomPath) 
		{
			m_UsingGeometry = true;

			m_gShaderID = loadShader(geomPath, GL_GEOMETRY_SHADER);

			glAttachShader(m_ProgramID, m_gShaderID);
		}

		GLuint Shader::getAttribLocation(const char *name) const 
		{
			return glGetAttribLocation(m_ProgramID, name);
		}

		GLuint Shader::getUniformLocation(const char *name) const 
		{
			return glGetUniformLocation(m_ProgramID, name);
		}

		void Shader::bindAttribute(GLuint index, const char *name) const 
		{
			return glBindAttribLocation(m_ProgramID, index, name);
		}

		void Shader::loadInt(const char *name, GLint value) const 
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::loadBool(const char *name, GLboolean value) const 
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::loadFloat(const char *name, GLfloat value) const 
		{
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::loadDouble(const char *name, GLdouble value) const
		{
			glUniform1d(getUniformLocation(name), value);
		}

		void Shader::loadTexture(const char *name, const Texture2D& texture) const 
		{
			glUniform1i(getUniformLocation(name), texture.getSlot());
		}

		void Shader::loadVector(const char *name, const Maths::vec2& value) const 
		{
			glUniform2f(getUniformLocation(name), value.x, value.y);
		}

		void Shader::loadVector(const char *name, const Maths::vec3& value) const 
		{
			glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
		}

		void Shader::loadVector(const char *name, const Maths::vec4& value) const 
		{
			glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
		}

		void Shader::Shader::loadMatrix(const char *name, const Maths::mat4& value) const 
		{
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, value.elements);
		}

		GLuint Shader::Shader::loadShader(const char *path, GLenum type) 
		{
			GLuint result = glCreateShader(type);

			const char *data = Utils::loadFile(path, false);

			glShaderSource(result, 1, &data, NULL);

			glCompileShader(result);

#ifdef DEBUG

			GLint error;

			glGetShaderiv(result, GL_COMPILE_STATUS, &error);

			if (error != GL_TRUE) 
			{
				GLint length;
				glGetShaderiv(result, GL_INFO_LOG_LENGTH, &length);
				char *err_data = new char[length + 1];
				glGetShaderInfoLog(result, length, &length, err_data);
				
				std::cout << err_data;

				glDeleteShader(result);

				return NULL;
			}

#endif

			return result;
		}

	}
}
