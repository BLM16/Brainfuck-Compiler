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

	std::cout << C_Code << std::endl;
}
