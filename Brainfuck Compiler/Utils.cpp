#include "Utils.h"

std::string read_file(fs::path path)
{
	std::string data;
	std::string line;

	std::ifstream file { path };

	// Make sure the file opened without error
	if (file.is_open())
	{
		// Read through every line in the file and append it to data
		while (std::getline(file, line))
			data += line;

		file.close();
	}

	return data;
}
