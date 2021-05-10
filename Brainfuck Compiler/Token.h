#pragma once

/// <summary>
/// Types of possible tokens
/// </summary>
enum class TokenType : char
{
	PLUS,
	MINUS,
	LSQUARE,
	RSQUARE,
	LTRIANGLE,
	RTRIANGLE,
	PERIOD,
	COMMA,
	UNSET
};

/// <summary>
/// Represents a reserved brainfuck symbol
/// </summary>
struct Token
{
public:
	/// Type of token
	TokenType type { TokenType::UNSET };
};
