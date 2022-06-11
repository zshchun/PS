#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string line;
	int a, b, r;
	int s[101], p;

	while (getline(cin, line)) {
		if (line.size() == 1 && line[0] == '.')
			break;
		a = 0; b = 0; r = 1; p = 0;
		for (char c: line) {
			if (c == '(') {
				s[p++] = 1;
				a++;
			} else if (c == ')') {
				if (s[--p] != 1) r = 0;
				a--;
			} else if (c == '[') {
				s[p++] = 2;
				b++;
			} else if (c == ']') {
				if (s[--p] != 2) r = 0;
				b--;
			}
			if (a < 0 || b < 0 || !r) {
				r = 0;
				break;
			}
		}
		if (r && !a && !b)
			cout << "yes\n";
		else
			cout << "no\n";

	}
	return 0;
}
