#include <bits/stdc++.h>
using namespace std;

bool isSeparator(char c)
{
	if (c == '{' || c == '}' || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '>' || c == '<' || c == '=' || c == ' ' || c == ',' || c == ';')
		return 1;
	return 0;
}

void op(string s)
{
	if (s.compare("+") == 0)
		cout << "Plus Operator" << endl;
	else if (s.compare("-") == 0)
		cout << "Minus Operator" << endl;
	else if (s.compare("*") == 0)
		cout << "Multiply Operator" << endl;
	else if (s.compare("/") == 0)
		cout << "Divide Operator" << endl;
	else if (s.compare("%") == 0)
		cout << "Modulas Operator" << endl;

	// Logical Operator
	else if (s.compare("||") == 0)
		cout << "Logical OR Operator." << endl;
	else if (s.compare("&&") == 0)
		cout << "Logical AND Operator." << endl;
	else if (s.compare("!") == 0)
		cout << "Logical NOT Operator." << endl;

	// Assignment Operator
	else if (s.compare("==") == 0)
		cout << "Equal Operator." << endl;
	else if (s.compare("<") == 0)
		cout << "Less Than Operator." << endl;
	else if (s.compare(">") == 0)
		cout << "Greater Than Operator." << endl;
	else if (s.compare("<=") == 0)
		cout << "Less than or equal Operator." << endl;
	else if (s.compare(">=") == 0)
		cout << "Greater than or equal Operator." << endl;
	else if (s.compare("!=") == 0)
		cout << "Not equal Operator." << endl;

	// Relational Operator
	else if (s.compare("=") == 0)
		cout << "Assign assignment Operator." << endl;
	else if (s.compare("+=") == 0)
		cout << "Add AND assignment Operator." << endl;
	else if (s.compare("-=") == 0)
		cout << "Subtract AND assignment Operator." << endl;
	else if (s.compare("*=") == 0)
		cout << "Multiply AND assignment Operator." << endl;
	else if (s.compare("/=") == 0)
		cout << "Divide AND assignment Operator." << endl;
	else if (s.compare("%=") == 0)
		cout << "Modulas AND assignment Operator." << endl;

	else if (s.compare("++") == 0)
		cout << "Increment Operator." << endl;
	else if (s.compare("--") == 0)
		cout << "Decrement Operator." << endl;

	// Bitwise Operator
	else if (s.compare("|") == 0)
		cout << "Bitwise OR Operator." << endl;
	else if (s.compare("&") == 0)
		cout << "Bitwise AND Operator." << endl;
	else if (s.compare("<<") == 0)
		cout << "Binary Left Shift Operator." << endl;
	else if (s.compare(">>") == 0)
		cout << "Binary Right Shift Operator." << endl;
	else if (s.compare("^") == 0)
		cout << "Binary XOR Operator." << endl;
	else if (s.compare("~") == 0)
		cout << "Binary One's Complement Operator." << endl;

	// else
	//     cout << "It's not an Operator." << endl;
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

		if (isSeparator(s[0]) && s != ";")
		{
			cout << s << " is a ";
			op(s);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();

	return 0;
}