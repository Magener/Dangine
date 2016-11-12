#pragma once

#include "vec3.h"
#include "vec4.h"

#undef near
#undef far

namespace Dangine 
{
	namespace Maths 
	{
	
		struct mat4 
		{
		
			union
			{
				float elements[4 * 4];
				vec4 columns[4];
			};

			mat4();
			mat4(float diagnal);


			mat4 multiply(const mat4& m);

			static mat4 rotate(float angle, float x, float y, float z);
			static mat4 rotate(float angle, const vec3& rot);
			
			static mat4 translate(float x, float y, float z);
			static mat4 translate(const vec3& pos);
			
			static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
			static mat4 perspective(float fov, float near, float far, float aspectRatio);

			static mat4 scale(float x, float y, float z);
			static mat4 scale(const vec3& scale);

			mat4 invert();

			friend inline mat4 operator*(mat4& left, const mat4& right) 
			{
				return left.multiply(right);
			}

			static inline mat4 identity() 
			{
				return mat4(1.0f);
			}

		};
	
	}
}
