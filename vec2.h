#pragma once

namespace Dangine 
{
	namespace Maths 
	{
	
		struct vec2 
		{
			union {
				float x, y;
				float xy[2];
				float rg[2];
			};

			vec2();
			vec2(float x, float y);

			vec2 add(const vec2& v);
			vec2 subtruct(const vec2& v);
			vec2 multiply(const vec2& v);
			vec2 devide(const vec2& v);

			friend inline vec2 operator+(vec2& left, const vec2& right)
			{
				return left.add(right);
			}

			friend inline vec2 operator-(vec2& left, const vec2& right)
			{
				return left.subtruct(right);
			}

			friend inline vec2 operator*(vec2& left, const vec2& right)
			{
				return left.multiply(right);
			}

			friend inline vec2 operator/(vec2& left, const vec2& right)
			{
				return left.devide(right);
			}

			vec2& operator+=(const vec2& v);

			vec2& operator-=(const vec2& v);

			vec2& operator*=(const vec2& v);

			vec2& operator/=(const vec2& v);

		};

	}
}
