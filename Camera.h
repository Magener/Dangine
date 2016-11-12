#pragma once

#include "vec2.h"
#include "vec2.h"
#include "mat4.h"

namespace Dangine 
{
	namespace Graphics 
	{
		
		class Camera 
		{
		public:
			Camera(const Maths::vec3& pos, const Maths::vec3& rot);

			inline Maths::vec3 getPos() const
			{
				return m_Pos;
			}

			inline Maths::vec3 getRot() const
			{
				return m_Rot;
			}

			inline void setPos(const Maths::vec3& pos)
			{
				m_Pos = pos;
			}

			inline void setRot(const Maths::vec3& rot)
			{
				m_Rot = rot;
			}

			inline void setPos(float x, float y, float z)
			{
				m_Pos.x = x;
				m_Pos.y = y;
				m_Pos.z = z;
			}

			inline void setRot(float rx, float ry, float rz)
			{
				m_Rot.x = rx;
				m_Rot.y = ry;
				m_Rot.z = rz;
			}

			inline Maths::mat4 getMatrix() {
				return Maths::mat4::translate(-m_Pos.x, -m_Pos.y, -m_Pos.z);
			}

			void increasePos(const Maths::vec3& pos);
			void increaseRot(const Maths::vec3& rot);
			void increasePos(float x, float y, float z);
			void increaseRot(float rx, float ry, float rz);

		private:
			Maths::vec3 m_Pos;
			Maths::vec3 m_Rot;
		
		};

		class Camera2D 
		{
		public:
			Camera2D(const Maths::vec2& pos);

			inline Maths::vec2 getPos() const
			{
				return m_Pos;
			}

			inline Maths::mat4 getMatrix() const
			{
				return Maths::mat4::translate(-m_Pos.x, -m_Pos.y, 0);
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

			void increasePos(const Maths::vec2& v);
			void increasePos(float x, float y);

		private:
			Maths::vec2 m_Pos;

		};

	}
}