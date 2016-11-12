#include "vec3.h"

namespace Dangine {
	namespace Maths {

		vec3::vec3() : x(0), y(0), z(0) 
		{}

		vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) 
		{}

		vec3 vec3::add(const vec3& v)
		{
			return *this += v;
		}

		vec3 vec3::subtruct(const vec3& v)
		{
			return *this -= v;
		}

		vec3 vec3::multiply(const vec3& v)
		{
			return *this *= v;
		}

		vec3 vec3::devide(const vec3& v)
		{
			return *this /= v;
		}

		vec3& vec3::operator+=(const vec3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		vec3& vec3::operator-=(const vec3& v) 
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		vec3& vec3::operator*=(const vec3& v) 
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;

			return *this;
		}

		vec3& vec3::operator/=(const vec3& v) 
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;

			return *this;
		}

	}
}
