#include "Buffer.h"

namespace Dangine
{
	namespace Graphics 
	{
		
		Buffer::Buffer(GLenum type) : m_ComponentSize(0), m_Type(type) 
		{
			glGenBuffers(1, &m_Id);
		}

		Buffer::~Buffer() {
			glDeleteBuffers(1, &m_Id);
		}

		void Buffer::put(GLsizeiptr size, GLvoid* data, GLuint componentSize) 
		{
			m_ComponentSize = componentSize;
			
			bind();

			glBufferData(m_Type, size, data, GL_STATIC_DRAW);

			unbind();
		}

		void *Buffer::map(GLenum access) const
		{
			bind();
			return glMapBuffer(m_Type, access);
		}

		void Buffer::unmap() const
		{
			glUnmapBuffer(m_Type);
		}

		IndexBuffer::IndexBuffer() : m_Count(0) 
		{
			glGenBuffers(1, &m_Id);
		}

		IndexBuffer::~IndexBuffer() {
			glDeleteBuffers(1, &m_Id);
		}

		void IndexBuffer::put(GLsizeiptr size, GLvoid* data, GLuint count) 
		{
			m_Count = count;

			bind();

			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

			unbind();
		}

	}
}
