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
		j = (n+1) / 2;
		cout << j << endl;
		i = 0;
		for (i=0;i<j;i++)
			cout << i*3+1 << " " << (n-i)*3 << endl;
	}
	return 0;
}
