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
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		vector<string> s(n);
		set<string> t;
		for (i=0;i<n;i++) {
			cin >> s[i];
			t.insert(s[i]);
		}

		for (i=0;i<n;i++) {
			bool ok = false;
			for (j=1;j<s[i].size();j++) {
				string x = s[i].substr(0, j);
				string y = s[i].substr(j);

				if (t.count(x) && t.count(y)) {
					ok = true;
					break;
				}
			}
			if (ok)
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}
	return 0;
}
