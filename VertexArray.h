#pragma once

#include <GL/glew.h>
#include <vector>
#include "Buffer.h"

namespace Dangine 
{
	namespace Graphics 
	{
	
		class VertexArray 
		{
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer& buffer, const GLuint attribNum, const GLsizei stride, const GLvoid* offset);

			inline void bind() const {
				glBindVertexArray(m_Id);
			}

			static inline void enableIndex(GLuint attribNum) 
			{
				glEnableVertexAttribArray(attribNum);
			}

			static inline void unbind() 
			{
				glBindVertexArray(0);
			}

		private:
			GLuint m_Id;
			std::vector<Buffer*> m_Buffers;

		};

	}
}
