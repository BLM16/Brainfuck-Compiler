#include "Parser.h"

std::string Parser::parse(std::vector<Token> tokens)
{
	// Loop through all the tokens
	for (Token tok : tokens)
	{
		// Append the corresponding c code to the parsed data
		switch (tok.type)
		{
		case TokenType::PLUS:
			c_code += "++*ptr;";
			break;

		case TokenType::MINUS:
			c_code += "--*ptr;";
			break;

		case TokenType::LSQUARE:
			c_code += "while(*ptr){";
			break;

		case TokenType::RSQUARE:
			c_code += "}";
			break;

		case TokenType::LTRIANGLE:
			c_code += "--ptr;";
			break;

		case TokenType::RTRIANGLE:
			c_code += "++ptr;";
			break;

		case TokenType::PERIOD:
			c_code += "putchar(*ptr);";
			break;

		case TokenType::COMMA:
			c_code += "scanf(\" %c\", ptr);";
			break;

		default:
			break;
		}
	}

	c_code += "}";
	return c_code;
}
