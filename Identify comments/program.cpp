#include<bits/stdc++.h>

using namespace std;
void solve() {
	vector<string>input;
	string in;
	while (getline(cin, in))input.push_back(in);

	int state = 0;

	for (auto s : input) {
		int i = 0;
		while (s[i] == ' ')i++;
		if ( state == 0 && s[i] == '/' && s[i + 1] == '/') {
			state = 1; break;
		} else if (s[i] == '/' && s[i + 1] == '*') {state = 2;}
		if (state == 2) {
			int j = s.size() - 1;

			while (s[j] == ' ')j--;
			if (s[j] == '/' && s[j - 1] == '*') {
				state = 3;
				break;
			}
		}
	}

	if (state == 1)cout << "Single Line Comment" << endl;
	else if (state == 3)cout << "Multi Line Comment" << endl;
	else cout << "No comment" << endl;
}

int main() {
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}
