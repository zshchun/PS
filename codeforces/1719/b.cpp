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
		cin >> n >> k;
		vector<ll> a(n+1);
		vector<pa> b;
		for (i=1;i<=n;i++)
			a[i] = i;
		for (i=1;i<=n;i+=2) {
			if ((a[i]+k)*a[i+1]%4 == 0) {
				b.push_back(pa(a[i], a[i+1]));
			} else if ((a[i+1]+k)*a[i]%4 == 0) {
				b.push_back(pa(a[i+1], a[i]));
			}
		}
		if (b.size() >= n/2) {
			cout << "YES\n";
			for (pa &p: b) {
				cout << p.first << " " << p.second << endl;
			}
		} else
			cout << "NO\n";
	}
	return 0;
}
