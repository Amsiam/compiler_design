#include<bits/stdc++.h>

using namespace std;
// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
	        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
	        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
	        ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
	        ch == '/' || ch == '>' || ch == '<' ||
	        ch == '=')
		return (true);
	return (false);
}


regex integer("^[0-9]+$");

// Returns 'true' if the string is an INTEGER.
bool isInteger(string str)
{
	return regex_match(str, integer) ? 1 : 0;
}

// Returns 'true' if the string is a Float NUMBER.
regex floatnum("^[0-9]+[.][0-9]+$");
bool isFloatnum(string str)
{
	return regex_match(str, floatnum) ? 1 : 0;
}

regex exponent("^[0-9]+[E][+-]?[0-9]+$");
regex floatexponent("^[0-9]+[.][0-9]+[E][+-]?[0-9]+$");
bool isExponent(string str)
{
	return (regex_match(str, exponent) || regex_match(str, floatexponent)) ? 1 : 0;
}



void parse() {

	vector<string> lines;
	string line;
	while (getline(cin, line))
		lines.push_back(line);

	vector<string> words;

	bool isFoundQ = 0;

	for (string line : lines)
	{
		string l = "";
		for (int i = 0; i < (int) line.size(); i++)
		{
			char c = line[i];
			if (isDelimiter(c) && !isFoundQ)
			{
				if ((c == '+' || c == '-') && i - 1 > 0 && line[i - 1] == 'E' && (line[i - 2] - '0' >= 0 && line[i - 2] - '0' <= 9)) {
					l += line[i];
					continue;
				}
				if (l != "")
					words.push_back(l);

				if (c != ' ')
				{
					l = c;

					if (isOperator(c)) {
						i++;
						if (i < (int)line.size() && line[i] != ' ' && isOperator(line[i]))
						{
							l += line[i];
						} else {

							i--;
						}

					}
					words.push_back(l);
				}
				l = "";
			}
			else
			{
				if (c == '"' && !isFoundQ) {
					isFoundQ = 1;

					l += c;
				}
				else if (c == '"' && isFoundQ) {
					isFoundQ = 0;

					l += c;
					words.push_back(l);
					l = "";

				} else {

					l += c;
				}
			}
		}

		if (l != "")
			words.push_back(l);
	}

	for (auto word : words) {
		if (isInteger(word)) {
			cout << word << " is an integer." << endl;
		} else if (isFloatnum(word)) {
			cout << word << " is a float number." << endl;
		} else if (isExponent(word)) {
			cout << word << " is an exponent number." << endl;
		}
	}

}


// DRIVER FUNCTION
int main()
{
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	parse();

	return (0);
}
