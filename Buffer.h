#pragma once

#include <GL/glew.h>

namespace Dangine 
{
	namespace Graphics 
	{
	
		class Buffer 
		{
		public:
			Buffer(GLenum type = GL_ARRAY_BUFFER);
			~Buffer();

			void put(GLsizeiptr size, GLvoid* data, GLuint componentSize);

			void bind() const 
			{
				glBindBuffer(m_Type, m_Id);
			}

			inline void unbind() const 
			{
				glBindBuffer(m_Type, 0);
			}

			inline GLuint getComponentSize() const
			{
				return m_ComponentSize;
			}

			void *map(GLenum access) const;
			void unmap() const;

		private:
			GLuint m_Id;
			GLuint m_ComponentSize;
			GLenum m_Type;

		};

		class IndexBuffer 
		{
		public:
			IndexBuffer();
			~IndexBuffer();

			void put(GLsizeiptr size, GLvoid* data, GLuint count);

			void bind() const 
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
			}

			inline void unbind() const 
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}

			inline GLuint getCount() const
			{
				return m_Count;
			}

		private:
			GLuint m_Id;
			GLuint m_Count;

		};

	}
}
