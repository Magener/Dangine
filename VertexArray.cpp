#include "VertexArray.h"

namespace Dangine 
{
	namespace Graphics 
	{
	
		VertexArray::VertexArray() 
		{
			glGenVertexArrays(1, &m_Id);
		}

		VertexArray::~VertexArray()
		{
			glDeleteVertexArrays(1, &m_Id);
			for (const Buffer *buffer : m_Buffers) 
			{
				buffer->~Buffer();
			}
		}

		void VertexArray::addBuffer(Buffer& buffer, const GLuint attribNum, const GLsizei stride, const GLvoid* offset) 
		{
			m_Buffers.push_back(&buffer);
			
			bind();
			buffer.bind();
			
			enableIndex(attribNum);

			glVertexAttribPointer(attribNum, buffer.getComponentSize(), GL_FLOAT, GL_FALSE, stride, offset);

			buffer.unbind();
			unbind();
		}

	}
}
