#include "mat4.h"
#include <math.h>

namespace Dangine 
{
	namespace Maths 
	{

		mat4::mat4() {
			for (int i = 0; i < 16; i++) 
			{
				elements[i] = 0;
			}
		}

		mat4::mat4(float diagnal) {
			for (int i = 0; i < 16; i++) 
			{
				elements[i] = 0;
			}

			elements[0 + 0 * 4] = diagnal;
			elements[1 + 1 * 4] = diagnal;
			elements[2 + 2 * 4] = diagnal;
			elements[3 + 3 * 4] = diagnal;
		}

		mat4 mat4::multiply(const mat4& m) 
		{
			mat4 result(1.0f);
			for (int y = 0; y < 4; y++) 
			{
				for (int x = 0; x < 4; x++) 
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += elements[e + y] * m.elements[x + e];
					}
					result.elements[x + y * 4] = sum;
				}
			}

			return result;
		}

		mat4 mat4::rotate(float angle, float x, float y, float z) 
		{
			mat4 result(1.0f);

			float c = cos(angle * (180 / M_PI));
			float s = sin(angle * (180 / M_PI));
			float omc = 1.0f - c;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[0 + 1 * 4] = x * y * omc + z * s;
			result.elements[0 + 2 * 4] = x * z * omc - y * s;

			result.elements[1 + 0 * 4] = y * x * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[1 + 2 * 4] = y * z * omc + x * s;

			result.elements[2 + 0 * 4] = z * x * omc + y * s;
			result.elements[2 + 1 * 4] = z * y * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		mat4 mat4::rotate(float angle, const vec3& rot) 
		{
			mat4 result(1.0f);

			float c = cos(angle * (180 / M_PI));
			float s = sin(angle * (180 / M_PI));
			float omc = 1.0f - c;

			float x = rot.x;
			float y = rot.y;
			float z = rot.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = x * y * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = y * x * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = z * x * omc + y * s;
			result.elements[1 + 2 * 4] = z * y * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		mat4 mat4::translate(float x, float y, float z) 
		{
			mat4 result(1.0f);

			result.elements[3 + 0 * 4] = x;
			result.elements[3 + 1 * 4] = y;
			result.elements[3 + 2 * 4] = z;

			return result;
		}

		mat4 mat4::translate(const vec3& pos) 
		{
			mat4 result(1.0f);


			result.elements[3 + 0 * 4] = pos.x;
			result.elements[3 + 1 * 4] = pos.y;
			result.elements[3 + 2 * 4] = pos.z;

			return result;
		}

		mat4 mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[3 + 0 * 4] = (left + right) / (left - right);
			result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
			result.elements[3 + 2 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(float fov, float near, float far, float aspectRatio)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = (1.0f / tan(fov / 2)) / aspectRatio;
			result.elements[1 + 1 * 4] = 1.0f / tan(fov / 2);

			result.elements[2 + 2 * 4] = (far + near) / (near - far);
			result.elements[3 + 2 * 4] = (far * near * 2.0f) / (near - far);

			result.elements[2 + 3 * 4] = -1;

			return result;
		}

		mat4 mat4::scale(float x, float y, float z) 
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = x;
			result.elements[1 + 1 * 4] = y;
			result.elements[2 + 2 * 4] = z;

			return result;
		}

		mat4 mat4::scale(const vec3& scale) 
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}

		mat4 mat4::invert() 
		{
			for (int i = 0; i < 16; i++) {
				if (elements[i] != 0) {
					elements[i] = 1 / elements[i];
				}
			}

			return *this;
		}

	}
}