
#include<bits/stdc++.h>

using namespace std;


void solve() {

	vector<string> lines;
	string line;
	vector<string> words;

	vector<int>getLoc, recursion, notHave;
	int i = 0;
	while (cin >> line) {
		if (line == "|")getLoc.push_back(i);
		words.push_back(line);
		i++;
	}

	string now = words[0];

	if (now == words[2])recursion.push_back(2);
	else {
		notHave.push_back(2);
	}

	for (int i = 0; i < (int)getLoc.size(); i++) {
		if (now == words[getLoc[i] + 1])recursion.push_back(getLoc[i] + 1);
		else {
			notHave.push_back(getLoc[i] + 1);
		}
	}
	if (recursion.size() > 0) {
		cout << now << " -> ";
		for (int loc : notHave) {
			for (int i = loc; i < (int)words.size(); i++) {
				if (words[i] == "|") {
					cout << now << "\'" << " | ";
					break;
				}
				cout << words[i] << " ";
			}
		}
		cout << now << "\'" << endl;
		cout << now << "\'" << " -> ";
		for (int loc : recursion) {
			for (int i = loc + 1; i < (int)words.size(); i++) {
				if (words[i] == "|") {
					cout << now << "\'" << " | ";
					break;
				}
				cout << words[i] << " ";
			}
		}
		cout << " $" << endl;
	} else {
		cout << "There is no left recursion." << endl;
	}
}


// DRIVER FUNCTION
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return (0);
}
