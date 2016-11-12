#include "vec2.h"

namespace Dangine 
{
	namespace Maths 
	{

		vec2::vec2() : x(0), y(0) 
		{}

		vec2::vec2(float x, float y) : x(x), y(y) 
		{}

		vec2 vec2::add(const vec2& v)
		{
			return *this += v;
		}

		vec2 vec2::subtruct(const vec2& v)
		{
			return *this -= v;
		}

		vec2 vec2::multiply(const vec2& v) 
		{
			return *this *= v;
		}

		vec2 vec2::devide(const vec2& v)
		{
			return *this /= v;
		}

		vec2& vec2::operator+=(const vec2& v) 
		{
			x += v.x;
			y += v.y;

			return *this;
		}

		vec2& vec2::operator-=(const vec2& v) 
		{
			x -= v.x;
			y -= v.y;

			return *this;
		}

		vec2& vec2::operator*=(const vec2& v) 
		{
			x *= v.x;
			y *= v.y;

			return *this;
		}

		vec2& vec2::operator/=(const vec2& v)
		{
			x /= v.x;
			y /= v.y;

			return *this;
		}

	}
}
