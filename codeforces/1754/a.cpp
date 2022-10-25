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
		string s;
		cin >> s;
		ans = 0;
		for (char &c: s) {
			if (c == 'Q') {
				if (ans < 0)
					ans = 1;
				else
					ans++;
			}
			else if (c == 'A')
				ans--;
		}
		if (ans <= 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
