#include "Texture.h"
#include <SDL_image.h>

namespace Dangine 
{
	namespace Graphics 
	{
		
		Texture2D::Texture2D(const char *path, GLuint mipmaplvl, GLenum slot, GLenum type, bool pixelated, bool usingAlpha) : m_Type(type), m_Pixelated(pixelated), m_UsingAlpha(usingAlpha), m_Slot(slot + GL_TEXTURE0) 
		{
		
			glGenTextures(1, &m_Id);

			glActiveTexture(m_Slot);

			bind();

			SDL_Surface *img = IMG_Load(path);

			glTexImage2D(m_Type, mipmaplvl, (m_UsingAlpha) ? GL_RGBA : GL_RGB, img->w, img->h, 0, (m_UsingAlpha) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, img->pixels);

			glTexParameteri(m_Type, GL_TEXTURE_MIN_FILTER, (m_Pixelated) ? GL_NEAREST : GL_LINEAR);
			glTexParameteri(m_Type, GL_TEXTURE_MAG_FILTER, (m_Pixelated) ? GL_NEAREST : GL_LINEAR);

			if (mipmaplvl != 0) 
			{
				glGenerateMipmap(m_Type);
				glTexParameteri(m_Type, GL_TEXTURE_MIN_FILTER, (m_Pixelated) ? GL_LINEAR_MIPMAP_NEAREST : GL_LINEAR_MIPMAP_LINEAR);
			}

			SDL_FreeSurface(img);

			unbind();
		}

		Texture2D::~Texture2D() 
		{
			glDeleteTextures(1, &m_Id);
		}

		void Texture2D::bind() const 
		{
			glBindTexture(m_Type, m_Id);
		}

		void Texture2D::unbind() const 
		{
			glBindTexture(m_Type, 0);
		}

	}
}
