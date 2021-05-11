#pragma once

#include <string>
#include <vector>

#include "Token.h"

/// <summary>
/// Used to convert a vector of tokens into c code
/// </summary>
class Parser
{
private:
	/// The c representation of the parsed tokens
	std::vector<std::string> c_code = { "#include<stdio.h>\nint main(){char array[30000] = {0}; char* ptr = &array[0];" };
	/// Previously parsed token
	Token previous;
	/// The number of the same token in a row
	int typeCount = 1;

public:
	/// <summary>
	/// Parses a vector of tokens into c code
	/// </summary>
	/// <param name="tokens">Vector of tokens to parse</param>
	/// <returns>C code representation of the tokens</returns>
	std::string parse(std::vector<Token> tokens);
};
