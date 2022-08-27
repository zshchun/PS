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
	while(T--) {
		map<char, ll> a;
		char c;
		for (i=0;i<4;i++) {
			cin >> c;
			a[c-'a']++;
		}
		cout << a.size()-1 <<endl;
	}
	return 0;
}
