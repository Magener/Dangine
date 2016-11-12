#pragma once

#include <vector>

namespace Dangine 
{
	namespace Utils 
	{
		
		extern const char *loadFile(const char *path, bool binary);

		extern void writeToFile(const char *path, const char *data, bool binary);
		extern void appendToFile(const char *path, const char *data, bool binary);

	}
}
