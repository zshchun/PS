#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char s[101];
	int i, n;
	int a[26] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	cin.getline(s, 101);
	for (i=0;s[i];i++) {
		n = s[i] - 'a';
		if (a[n] == -1) {
			a[n] = i;
		}
	}
	for (i=0;i<26;i++) {
		if (i > 0)
			cout << " ";
		cout << a[i];
	}
	cout << "\n";

	return 0;
}
