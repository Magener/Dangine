#pragma once

#include <GL/glew.h>

namespace Dangine 
{
	namespace Graphics
	{
	
		class Texture2D 
		{
		public:
			Texture2D(const char *path, GLuint mipmaplvl, GLenum slot, GLenum type, bool pixelated, bool usingAlpha);
			~Texture2D();

			void bind() const;
			void unbind() const;

			inline GLuint getId() const
			{
				return m_Id;
			}

			inline GLenum getSlot() const 
			{
				return m_Slot - GL_TEXTURE0;
			}

			inline bool isPixelated() const
			{
				return m_Pixelated;
			}

			inline bool isUsingAlpha() const
			{
				return m_UsingAlpha;
			}

		private:
			GLuint m_Id;
			GLenum m_Slot;
			GLenum m_Type;
			bool m_Pixelated;
			bool m_UsingAlpha;

		};

	}
}
