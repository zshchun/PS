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
		vector<ll> a(n+1);
		for (i=1;i<=n;i++)
			a[i] = i;
		for (i=n;i>=2;i-=2)
			swap(a[i], a[i-1]);
		for (i=1;i<=n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}
