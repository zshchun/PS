#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n;
ll a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> n;
	for (i=1;i<=n;i++)
		for (j=i;j<=n;j+=i)
			a[j] += i;

	cout << accumulate(a, a+n+1, 0ULL) << endl;
	return 0;
}
