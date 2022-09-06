#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	string s;
	while(T--) {
		cin >> s;
		set<char> alpha;
		for (i=0;i<s.size();i++)
			alpha.insert(s[i]);
		string cut = s.substr(0, alpha.size());
		bool ok = true;
		for (i=alpha.size();i<s.size();i+=alpha.size()) {
			string t = s.substr(i, alpha.size());
			if (t != cut.substr(0, t.size())) {
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
