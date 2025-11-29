#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[26];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n;
	string s;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		k = 1;
		for (char &c : s) {
			a[c-'A'] += k;
			k *= 10;
		}
	}

	j = 9;
	sort(a, a+26, greater());
	for (i=0;i<26;i++) {
		ans += a[i] * j;
		j--;
	}

	cout << ans << endl;

	return 0;
}
