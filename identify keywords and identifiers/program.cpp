#include<bits/stdc++.h>

using namespace std;

regex identifier("^[a-zA-Z_][a-z0-9A-Z_]*");

string keywords[33] = {
	"auto", "double", "int", "float", "char", "break", "case", "continue",
	"do", "default", "const", "else", "enum", "extern", "for", "if", "goto",
	"long", "register", "return", "signed", "static", "sizeof", "short", "struct",
	"switch", "typedef", "union", "void", "while", "volatile", "unsigned"
};

bool isSpearator(char c) {
	if (c == ' ' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == ';')return true;
	return false;
}


bool isKeyword(string s) {
	for (int i = 0; i < 32; i++) {
		if (s.compare(keywords[i]) == 0) return 1;
	}
	return 0;
}


bool isIdentifier(string s) {

	if (regex_match(s, identifier)) return 1;

	return 0;
}

void solve() {
	vector<string>input;
	string in;
	while (getline(cin, in))input.push_back(in);
	vector<string>sto;
	for (string line : input) {
		string ss = "";
		for (char s : line) {
			if (isSpearator(s)) {
				if (ss != "") {
					sto.push_back(ss);
				}
				ss = "";
				if (s != ' ') {
					ss += s;
					sto.push_back(ss);
				}
				ss = "";
			} else {
				ss += s ;
			}
		}
	}

	for (string s : sto) {
		if (isIdentifier(s)) {
			if (isKeyword(s))cout << s << " is a keyword" << endl;
			else cout << s << " is a identifier" << endl;
		} else {
			cout << s << " is not a valid identifier" << endl;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}