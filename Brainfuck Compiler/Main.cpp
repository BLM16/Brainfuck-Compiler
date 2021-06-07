#include <iostream>
#include <filesystem>

#include "Lexer.h"
#include "Parser.h"
#include "Utils.h"

/// Simplify the namespace for std::filesystem
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
	// Parse the parameters
	Parameters params = parse_parameters(argc, argv);
	if (params.has_error)
		return 1;

	/// Brainfuck code read from the specified file
	auto data = read_file(params.InFile);

	/// Tokenized brainfuck code
	auto Tokens = LEXER.parse(data);
	/// C equivalent of the brainfuck code
	auto C_Code = PARSER.parse(Tokens);

	// If the -c option is specified, write the c code and don't compile
	if (params.c_only)
		write_file(params.OutFile, C_Code);
	else
	{
		// Check if there is a terminal
		if (!system(NULL))
		{
			std::cerr << "No terminal exists to execute commands" << std::endl;
			return 1;
		}
		else
		{
			// Write a temp file with the c code
			write_file(params.InFile.string() + ".c", C_Code);

			// Compile the c code into an executable
			std::string cmd = "g++ -o " + params.OutFile.string() + " " + params.InFile.string() + ".c";
			system(cmd.c_str());

			// Delete the temp file
			remove((params.InFile.string() + ".c").c_str());
		}
	}
}
