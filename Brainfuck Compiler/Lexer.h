#pragma once

#include <vector>
#include <string>

#include "Token.h"

/// <summary>
/// Used to tokenize a brainfuck file
/// </summary>
class Lexer
{
private:
	/// <summary>
	/// Appends a token to the tokens array and resets the current token
	/// </summary>
	/// <param name="tokens">Token array to append to</param>
	/// <param name="tok">Token to append</param>
	void appendToken(std::vector<Token>& tokens, Token& tok);

	/// List of processed tokens
	std::vector<Token> Tokens;
	/// Current token
	Token current;

public:
	/// <summary>
	/// Parse a string into a vector of tokens
	/// </summary>
	/// <param name="data">String to parse</param>
	/// <returns>A vector of tokens</returns>
	std::vector<Token> parse(std::string data);
};
