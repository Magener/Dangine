#include "FileUtils.h"

#include <stdlib.h>

namespace Dangine 
{
	namespace Utils 
	{

		const char *loadFile(const char *path, bool binary) 
		{
			FILE *file = fopen(path, binary ? "rb" : "rt");
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char *data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			return data;
		}

		void writeToFile(const char *path, const char *data, bool binary)
		{
			FILE *file = fopen(path, binary ? "wb" : "w");
			fprintf(file, data);
			fclose(file);
		}

		void appendToFile(const char *path, const char *data, bool binary)
		{
			FILE *file = fopen(path, binary ? "ab" : "a");
			fprintf(file, data);
			fclose(file);
		}

	}
}
