#pragma once

namespace Dangine 
{
	namespace Maths 
	{

		struct vec3 
		{
			union {
				float x, y, z;
				float xyz[3];
				float rgb[3];
			};

			vec3();
			vec3(float x, float y, float z);

			vec3 add(const vec3& v);
			vec3 subtruct(const vec3& v);
			vec3 multiply(const vec3& v);
			vec3 devide(const vec3& v);

			friend inline vec3 operator+(vec3& left, const vec3& right)
			{
				return left.add(right);
			}

			friend inline vec3 operator-(vec3& left, const vec3& right)
			{
				return left.subtruct(right);
			}

			friend inline vec3 operator*(vec3& left, const vec3& right)
			{
				return left.multiply(right);
			}

			friend inline vec3 operator/(vec3& left, const vec3& right)
			{
				return left.devide(right);
			}

			vec3& operator+=(const vec3& v);

			vec3& operator-=(const vec3& v);

			vec3& operator*=(const vec3& v);

			vec3& operator/=(const vec3& v);

		};

	}
}
