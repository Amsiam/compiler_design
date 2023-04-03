#include <bits/stdc++.h>
using namespace std;

regex identifier("^[a-zA-Z_][a-z0-9A-Z_]*");

string keywords[33] = {
	"auto", "double", "int", "float", "char", "break", "case", "continue",
	"do", "default", "const", "else", "enum", "extern", "for", "if", "goto",
	"long", "register", "return", "signed", "static", "sizeof", "short", "struct",
	"switch", "typedef", "union", "void", "while", "volatile", "unsigned"
};

bool isSeparator(char c)
{
	if (c == '{' || c == '}' || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '>' || c == '<' || c == '=' || c == ' ' || c == ',' || c == ';')
		return 1;
	return 0;
}

bool isKeyword(string s)
{
	for (int i = 0; i < 32; i++)
	{
		if (s.compare(keywords[i]) == 0)
			return 1;
	}
	return 0;
}

bool isIdentifier(string s)
{
	return regex_match(s, identifier) ? 1 : 0;
}

void solve()
{
	vector<string> lines;
	string line;
	while (getline(cin, line))
		lines.push_back(line);

	vector<string> words;

	for (string line : lines)
	{
		string l = "";
		for (int i = 0; i < line.size(); i++)
		{
			char c = line[i];
			if (isSeparator(c))
			{
				if (l != "")
					words.push_back(l);

				if (c != ' ')
				{
					l = c;
					i++;
					while (i < line.size() && line[i] != ' ' && isSeparator(line[i]))
					{
						l += line[i];
						i++;
					}
					i--;
					words.push_back(l);
				}
				l = "";
			}
			else
			{
				l += c;
			}
		}

		if (l != "")
			words.push_back(l);
	}
	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];
		if (isIdentifier(s))
		{
			if (isKeyword(s))
				cout << "'" << s << "'"
					 << " is a keyword." << endl;

			else
				cout << "'" << s << "'"
					 << " is an identifier." << endl;
		}
		else
		{
			// cout << s << " is not a valid identifier." << endl;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}