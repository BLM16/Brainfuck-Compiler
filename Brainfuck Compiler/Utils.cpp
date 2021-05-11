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

Parameters parse_parameters(int argc, char** argv)
{
	/// Parameters to set
	Parameters params = Parameters();
	/// Is the outflag (-o) set
	bool isOutFlagged = false;

	for (int i = 1; i < argc; i++)
	{
		// Outflag isn't set
		if (!isOutFlagged)
		{
			// Outfile flag
			if (argv[i] == "-o")
				isOutFlagged = true;

			// C only flag
			else if (argv[i] == "-c")
				params.c_only = true;

			// Brainfuck file to compile
			else
			{
				// Path doesn't exist
				if (!fs::exists(argv[i]) || !fs::is_regular_file(argv[i]))
				{
					std::cerr << "File \"" << argv[i] << "\" not found" << std::endl;
					params.has_error = true;
					return params;
				}

				// Path to the brainfuck file
				const fs::path path(argv[i]);

				// Invalid filetype
				if (!path.has_extension() || !(path.extension().string() == ".b" || path.extension().string() == ".bf"))
				{
					std::cerr << "Invalid filetype \"" << path.extension().string() << "\". Please specify a brainfuck file with the extension \".b\" or \".bf\"" << std::endl;
					params.has_error = true;
					return params;
				}

				params.InFile = path;
			}
		}
		// Outflag is set
		else
		{
			if (argv[i] == "-o")
			{
				std::cerr << "Cannot have multiple outfile (-o) definitions" << std::endl;
				params.has_error = true;
				return params;
			}

			else if (argv[i] == "-c")
			{
				std::cerr << "Outfile definition (-o) must be followed by a valid file path" << std::endl;
				params.has_error = true;
				return params;
			}

			else
				params.OutFile = argv[i];
		}
	}

	return params;
}
