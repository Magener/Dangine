#include "vec4.h"

namespace Dangine {
	namespace Maths {

		vec4::vec4() : x(0), y(0), z(0) 
		{}

		vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) 
		{}

		vec4 vec4::add(const vec4& v)
		{
			return *this += v;
		}

		vec4 vec4::subtruct(const vec4& v)
		{
			return *this -= v;
		}

		vec4 vec4::multiply(const vec4& v)
		{
			return *this *= v;
		}

		vec4 vec4::devide(const vec4& v)
		{
			return *this /= v;
		}

		vec4& vec4::operator+=(const vec4& v) 
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;

			return *this;
		}

		vec4& vec4::operator-=(const vec4& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;

			return *this;
		}

		vec4& vec4::operator*=(const vec4& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			w *= v.w;

			return *this;
		}

		vec4& vec4::operator/=(const vec4& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			w /= v.w;

			return *this;
		}

	}
}
