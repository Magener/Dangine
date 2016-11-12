#pragma once

namespace Dangine 
{
	namespace Maths 
	{

		struct vec4 
		{
			union {
				float x, y, z, w;
				float xyzw[4];
				float rgba[4];
			};

			vec4();
			vec4(float x, float y, float z, float w);

			vec4 add(const vec4& v);
			vec4 subtruct(const vec4& v);
			vec4 multiply(const vec4& v);
			vec4 devide(const vec4& v);

			friend inline vec4 operator+(vec4& left, const vec4& right)
			{
				return left.add(right);
			}

			friend inline vec4 operator-(vec4& left, const vec4& right)
			{
				return left.subtruct(right);
			}

			friend inline vec4 operator*(vec4& left, const vec4& right)
			{
				return left.multiply(right);
			}

			friend inline vec4 operator/(vec4& left, const vec4& right)
			{
				return left.devide(right);
			}

			vec4& operator+=(const vec4& v);

			vec4& operator-=(const vec4& v);

			vec4& operator*=(const vec4& v);

			vec4& operator/=(const vec4& v);

		};

	}
}
