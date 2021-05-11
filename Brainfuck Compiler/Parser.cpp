#include "Parser.h"

std::string Parser::parse(std::vector<Token> tokens)
{
	// Loop through all the tokens
	for (Token tok : tokens)
	{
		// Reset typeCount if needed
		if (tok.type != previous.type)
			typeCount = 1;

		// Append the corresponding c code to the parsed data
		// Convert ++ptr;++ptr; into ptr+=2 where possible
		switch (tok.type)
		{
		case TokenType::PLUS:
			if (previous.type == TokenType::PLUS)
			{
				c_code.pop_back();
				typeCount++;
				c_code.push_back("*ptr+=" + std::to_string(typeCount) + ";");
			}
			else
				c_code.push_back("++*ptr;");
			break;

		case TokenType::MINUS:
			if (previous.type == TokenType::MINUS)
			{
				c_code.pop_back();
				typeCount++;
				c_code.push_back("*ptr-=" + std::to_string(typeCount) + ";");
			}
			else
				c_code.push_back("--*ptr;");
			break;

		case TokenType::LSQUARE:
			c_code.push_back("while(*ptr){");
			break;

		case TokenType::RSQUARE:
			c_code.push_back("}");
			break;

		case TokenType::LTRIANGLE:
			if (previous.type == TokenType::LTRIANGLE)
			{
				c_code.pop_back();
				typeCount++;
				c_code.push_back("ptr-=" + std::to_string(typeCount) + ";");
			}
			else
				c_code.push_back("--ptr;");
			break;

		case TokenType::RTRIANGLE:
			if (previous.type == TokenType::RTRIANGLE)
			{
				c_code.pop_back();
				typeCount++;
				c_code.push_back("ptr+=" + std::to_string(typeCount) + ";");
			}
			else
				c_code.push_back("++ptr;");
			break;

		case TokenType::PERIOD:
			c_code.push_back("putchar(*ptr);");
			break;

		case TokenType::COMMA:
			c_code.push_back("scanf(\" %c\", ptr);");
			break;

		default:
			break;
		}

		previous = tok;
	}

	c_code.push_back("}");
	
	std::string str;
	for (std::string s : c_code)
		str += s;

	return str;
}
