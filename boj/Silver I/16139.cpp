#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string s;
int n;
int a[200001][26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, l, r, x;
	char c;

	cin >> s >> n;

	if (s.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	a[0][s[0]-'a']++;

	for (i=1;i<s.size();i++) {
		x = s[i] - 'a';
		for (j=0;j<26;j++) {
			if (x == j)
				a[i][j] = a[i-1][j] + 1;
			else
				a[i][j] = a[i-1][j];
		}
	}
	for (i=0;i<n;i++) {
		cin >> c >> l >> r;
		x = c - 'a';
		int t = l == 0 ? 0 : a[l-1][x];
		cout << a[r][x] - t << endl;
	}
	return 0;
}
