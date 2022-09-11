#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, i, j;
	int valid, cnt = 0;
	string s;
	int map;
	char c;
	cin >> n;
	for (i=0;i<n;i++) {
		map = 0;
		cin >> s;
		valid = 1;
		c = s[0];
		map |= 1 << (c-'a');
		for (j=1;j<s.size();j++) {
			if (c == s[j])
				continue;
			c = s[j];
			if (map & (1<<(c-'a'))) {
				valid = 0;
				break;
			}
			map |= 1 << (c-'a');
		}
		if (valid)
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}

