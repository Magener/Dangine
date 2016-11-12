#include "Camera.h"

namespace Dangine 
{
	namespace Graphics 
	{
		
		Camera::Camera(const Maths::vec3& pos, const Maths::vec3& rot) : m_Pos(pos), m_Rot(rot) 
		{}

		void Camera::increasePos(const Maths::vec3& pos) 
		{
			m_Pos += pos;
		}

		void Camera::increaseRot(const Maths::vec3& rot) 
		{
			m_Rot += rot;
		}

		void Camera::increasePos(float x, float y, float z)
		{
			m_Pos.x += x;
			m_Pos.y += y;
			m_Pos.z += z;
		}

		void Camera::increaseRot(float rx, float ry, float rz)
		{
			m_Rot.x += rx;
			m_Rot.y += ry;
			m_Rot.z += rz;
		}

		Camera2D::Camera2D(const Maths::vec2& pos) : m_Pos(pos) 
		{}

		void Camera2D::increasePos(const Maths::vec2& pos)
		{
			m_Pos += pos;
		}

		void Camera2D::increasePos(float x, float y)
		{
			m_Pos.x += x;
			m_Pos.y += y;
		}

	}
}
