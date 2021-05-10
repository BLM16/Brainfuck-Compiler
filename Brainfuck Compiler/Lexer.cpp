#include "Lexer.h"

std::vector<Token> Lexer::parse(std::string data)
{
	// Loop through each char in the data
	for (char c : data)
	{
		// If the char is reserved add the corresponding token to the vector
		// If the char is not reserved we don't care about it so we ignore it
		switch (c)
		{
		case '+':
			current.type = TokenType::PLUS;
			appendToken(Tokens, current);
			break;

		case '-':
			current.type = TokenType::MINUS;
			appendToken(Tokens, current);
			break;

		case '[':
			current.type = TokenType::LSQUARE;
			appendToken(Tokens, current);
			break;

		case ']':
			current.type = TokenType::RSQUARE;
			appendToken(Tokens, current);
			break;

		case '<':
			current.type = TokenType::LTRIANGLE;
			appendToken(Tokens, current);
			break;

		case '>':
			current.type = TokenType::RTRIANGLE;
			appendToken(Tokens, current);
			break;

		case '.':
			current.type = TokenType::PERIOD;
			appendToken(Tokens, current);
			break;

		case ',':
			current.type = TokenType::COMMA;
			appendToken(Tokens, current);
			break;

		default:
			break;
		}
	}

	return Tokens;
}

void Lexer::appendToken(std::vector<Token>& tokens, Token& tok)
{
	tokens.push_back(tok);
	tok.type = TokenType::UNSET;
}
