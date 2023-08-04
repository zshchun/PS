#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N;
ll a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll x, i;
	cin >> N;
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (i=4;i<=1000000;i++) {
		a[i] = (a[i-1] + a[i-2] + a[i-3]) % 1000000009;
	}
	while (N--) {
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}
