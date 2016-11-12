#pragma once

#include <GL/glew.h>
#include "vec2.h"
#include "vec3.h"
#include "mat4.h"
#include "Texture.h"
#include "VertexArray.h"

namespace Dangine 
{
	namespace Renderable 
	{

		class Entity2D 
		{
		public:
			Entity2D(const Maths::vec2& pos, const Maths::vec2& size, const Graphics::Texture2D& texture, float rot);
			~Entity2D();

			inline Maths::vec2 getPos() const 
			{
				return m_Pos;
			}

			inline float getRotation() const 
			{
				return m_Rot;
			}

			inline Graphics::VertexArray *getModel() const 
			{
				return m_VAO;
			}

			inline Maths::mat4 getMatrix() const 
			{
				return Maths::mat4::translate(m_Pos.x, m_Pos.y, 0) * 
					Maths::mat4::rotate(m_Rot, 0, 0, 1);
			}

			inline Graphics::Texture2D getTexture() const 
			{
				return m_Texture;
			}

			inline Graphics::IndexBuffer getIBO() const 
			{
				return m_IBO;
			}

			inline void setPos(const Maths::vec2& pos) 
			{
				m_Pos = pos;
			}

			inline void setPos(float x, float y) 
			{
				m_Pos.x = x;
				m_Pos.y = y;
			}

			inline void setRotation(float rot) 
			{
				m_Rot = rot;
			}

			inline void bind() const 
			{
				m_IBO.bind();
				m_VAO->bind();
				m_Texture.bind();
			}

			inline void unbind() const 
			{
				m_Texture.unbind();
				m_VAO->unbind();
				m_IBO.unbind();
			}

			void increasePos(const Maths::vec2& pos);
			void increasePos(float x, float y);
			void increaseRot(float rot);

		private:
			Graphics::VertexArray *m_VAO;
			Graphics::IndexBuffer m_IBO;
			Graphics::Texture2D m_Texture;
			Maths::vec2 m_Pos, m_Size;
			float m_Rot;

		};

	}
}
