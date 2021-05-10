#include <iostream>
#include <filesystem>

#include "Lexer.h"
#include "Parser.h"
#include "Utils.h"

// Simplify the namespace for std::filesystem
namespace fs = std::filesystem;

/// Lexer instance used for tokenization
Lexer LEXER = Lexer();
/// Parser instance used for converting the token vector into c code
Parser PARSER = Parser();

/// <summary>
/// Entry point to the compiler
/// </summary>
/// <param name="argc">The number of parameters passed</param>
/// <param name="argv">The parameters that were passed</param>
int main(int argc, char** argv)
{
	// Not enough parameters
	if (argc < 3)
	{
		std::cerr << "You must specify \"build\" or \"run\" and the filename" << std::endl;
		return 1;
	}

	// Invalid method parameter
	if (argv[1] != "build" || argv[1] != "run")
	{
		std::cerr << "Invalid option \"" << argv[1] << "\", please specify \"build\" or \"run\"" << std::endl;
		return 1;
	}

	// Path doesn't exist
	if (!fs::exists(argv[2]) || fs::is_regular_file(argv[2]))
	{
		std::cerr << "File \"" << argv[2] << "\" not found" << std::endl;
		return 1;
	}

	// Path to the brainfuck file
	const fs::path path(argv[2]);

	// Invalid filetype
	if (!path.has_extension() || path.extension().string() != ".b" || path.extension().string() != ".bf")
	{
		std::cerr << "Invalid filetype. Please specify a brainfuck file with the extension \".b\" or \".bf\"" << std::endl;
		return 1;
	}
}
