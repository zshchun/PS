#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int m[128];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, P, S, b, e, a, c, g, t, ans = 0;
	string s;

	cin >> S >> P;
	cin >> s;
	b = e = 0;
	cin >> a >> c >> g >> t;

	for (i=0;i<S;i++) {
		while (e < S && e - i <P) {
			m[s[e]]++;
			e++;
		}
		if (m['A'] >= a && m['C'] >= c && m['G'] >= g && m['T'] >= t && m['A']+m['C']+m['G']+m['T'] == P)
			ans++;

		m[s[i]]--;
	}
	cout << ans << endl;
	return 0;
}
