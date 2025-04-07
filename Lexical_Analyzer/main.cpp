#include <bits/stdc++.h>
using namespace std;

enum class TokenType
{
	Identifier,
	Integer,
	AddOp,
	SubOp,
	MulOp,
	DivOp,
	AssignOp,
	LeftParen,
	RightParen,
	LeftBrace,
	RightBrace,
	LeftBracket,
	RightBracket,
	Semicolon,
	KeywordIf,
	KeywordFor,
	KeywordWhile,
	LessThanOp,
	GreaterThanOp,
	LessEqualOp,
	GreaterEqualOp,
	EndOfInput,
	Invalid
};

struct Token
{
	TokenType type;
	string value;
};

unordered_map<TokenType, string> tokenTypeToStrMap =
{
	{TokenType::Identifier, "Identifier"},
	{TokenType::Integer, "Integer"},
	{TokenType::AddOp, "AddOp"},
	{TokenType::SubOp, "SubOp"},
	{TokenType::MulOp, "MulOp"},
	{TokenType::DivOp, "DivOp"},
	{TokenType::AssignOp, "AssignOp"},
	{TokenType::LeftParen, "LeftParen"},
	{TokenType::RightParen, "RightParen"},
	{TokenType::LeftBrace, "LeftBrace"},
	{TokenType::RightBrace, "RightBrace"},
	{TokenType::LeftBracket, "LeftBracket"},
	{TokenType::RightBracket, "RightBracket"},
	{TokenType::Semicolon, "Semicolon"},
	{TokenType::KeywordIf, "KeywordIf"},
	{TokenType::KeywordFor, "KeywordFor"},
	{TokenType::KeywordWhile, "KeywordWhile"},
	{TokenType::LessThanOp, "LessThanOp"},
	{TokenType::GreaterThanOp, "GreaterThanOp"},
	{TokenType::LessEqualOp, "LessEqualOp"},
	{TokenType::GreaterEqualOp, "GreaterEqualOp"},
	{TokenType::EndOfInput, "EndOfInput"},
	{TokenType::Invalid, "Invalid"}
};

string getTokenTypeStr(TokenType type)
{
	return tokenTypeToStrMap[type];
}

Token getNextToken()
{
	char currentChar;

	while (cin.get(currentChar) && isspace(currentChar));

	if (cin.eof())
		return {TokenType::EndOfInput, "EOF"};

	switch (currentChar)
	{
		case '+': return {TokenType::AddOp, "+"};
		case '-': return {TokenType::SubOp, "-"};
		case '*': return {TokenType::MulOp, "*"};
		case '/': return {TokenType::DivOp, "/"};
		case '=': return {TokenType::AssignOp, "="};
		case '(': return {TokenType::LeftParen, "("};
		case ')': return {TokenType::RightParen, ")"};
		case '{': return {TokenType::LeftBrace, "{"};
		case '}': return {TokenType::RightBrace, "}"};
		case '[': return {TokenType::LeftBracket, "["};
		case ']': return {TokenType::RightBracket, "]"};
		case ';': return {TokenType::Semicolon, ";"};
		case '<':
		{
			if (cin.peek() == '=')
			{
				cin.get();
				return {TokenType::LessEqualOp, "<="};
			}
			return {TokenType::LessThanOp, "<"};
	    }
		case '>':
		{
			if (cin.peek() == '=')
			{
				cin.get();
				return {TokenType::GreaterEqualOp, ">="};
			}
			return {TokenType::GreaterThanOp, ">"};
	    }
		default:
			break;
	}

	if (isdigit(currentChar))
	{
		string number(1, currentChar);
		while (cin.get(currentChar) && isdigit(currentChar))
			number += currentChar;

		cin.unget();
		return {TokenType::Integer, number};
	}

	if (isalpha(currentChar))
	{
		string identifier(1, currentChar);
		while (cin.get(currentChar) && isalnum(currentChar))
			identifier += currentChar;
		cin.unget();

		if (identifier == "if") return {TokenType::KeywordIf, identifier};
		if (identifier == "for") return {TokenType::KeywordFor, identifier};
		if (identifier == "while") return {TokenType::KeywordWhile, identifier};

		return {TokenType::Identifier, identifier};
	}

	return {TokenType::Invalid, string(1, currentChar)};
}

int main()
{
	cout << "Enter input (Ctrl+D on Unix/Linux, Ctrl+Z then Enter on Windows to end):" << endl;

	while (true)
	{
		Token token = getNextToken();
		cout << "Next token: " << getTokenTypeStr(token.type) << " Value: " << token.value << endl;

		if (token.type == TokenType::EndOfInput) break;
		if (token.type == TokenType::Invalid)
		    cerr << "Error: Invalid token '" << token.value << "'" << endl;
	}

	return 0;
}
