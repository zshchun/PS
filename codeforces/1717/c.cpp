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
		cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		for (i=0;i<n;i++)
			cin >> b[i];
		bool ok = true;
		for (i=0;i<n;i++) {
			if (b[i] < a[i]) ok = false;
			if (a[i] != b[i] && b[i] > b[(i+1)%n]+1) ok = false;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
