#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[26];
	int i, m;
	char c = ' ';
	for (i=0;i<26;i++)
		a[i] = 0;
	for (i=0;i<s.size();i++) {
		a[(s[i] & ~0x20)-'A']++;
	}

	for (i=0,m=0;i<26;i++) {
		if (a[i] > m) {
			c = i+'A';
			m = a[i];
		} else if (m && a[i] == m) {
			c = '?';
		}
	}
	cout << c <<"\n";

	return 0;
}
