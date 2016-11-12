#include "Entity.h"
#include "Buffer.h"

namespace Dangine 
{
	namespace Renderable 
	{

		Entity2D::Entity2D(const Maths::vec2& pos, const Maths::vec2& size, const Graphics::Texture2D& texture, float rot) : m_Pos(pos), m_Size(size), m_Texture(texture), m_Rot(rot) 
		{
		
			float vertices[] = 
			{
				m_Size.x	, m_Size.y, 0,
				m_Size.x	, 0		, 0,
				0			, 0		, 0,
				0			, m_Size.y, 0
			};


			float tc[] = 
			{
				0, 0,
				0, 1,
				1, 1,
				1, 0
			};

			unsigned int indices[] = 
			{
				0, 1, 2,
				2, 3, 0
			};

			m_VAO = new Graphics::VertexArray;

			Graphics::Buffer vbo;
			Graphics::Buffer tbo;

			vbo.put(sizeof(vertices), vertices, 3);
			tbo.put(sizeof(tc), tc, 2);
			
			m_IBO.put(sizeof(indices), indices, 6);

			m_VAO->addBuffer(vbo, 0, 0, 0);
			m_VAO->addBuffer(tbo, 1, 0, 0);
		}

		Entity2D::~Entity2D() {
			m_VAO->~VertexArray();
			m_IBO.~IndexBuffer();
		}

		void Entity2D::increasePos(const Maths::vec2& pos) 
		{
			m_Pos += pos;
		}

		void Entity2D::increasePos(float x, float y)
		{
			m_Pos.x += x;
			m_Pos.y += y;
		}

		void Entity2D::increaseRot(float rot) 
		{
			m_Rot += rot;
		}

	}
}
