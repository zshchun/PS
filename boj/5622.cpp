#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	int i, j, sum=0, gap;
	cin >> s;
	char c;
	for (i=0;i<s.size();i++) {
		c = s[i]-'A';
		if (c > 22) {
			c -= 2;
		} else if (c > 15) {
			c -= 1;
		}
		j = c / 3;
		sum += j + 3;
	}
	cout << sum << "\n";
	return 0;
}
