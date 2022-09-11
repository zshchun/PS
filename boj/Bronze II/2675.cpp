#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r;
	size_t i;
	char l[30];
	string s;
	while (cin >> r) {
		cin.getline(l, 30);
		if (strlen(l) == 0) continue;
		for(i=1;i<strlen(l);i++) {
			s += string(r, l[i]);
		}
		s += '\n';
	}

	cout << s;
	return 0;
}

