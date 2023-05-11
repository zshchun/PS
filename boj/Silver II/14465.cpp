#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll N, K, B, i, j, total = 0, ans = 0, v;
	cin >> N >> K >> B;
	vector<ll> a(N+1, 0);
	for (i=0;i<B;i++) {
		cin >> v;
		a[v] = 1;
	}
	ans = K;

	for (j=1;j<K;j++) {
		total += a[j];
	}
	for (i=K;i<=N;i++) {
		total += a[i];
		if (ans > total)
			ans = total;
		total -= a[i-K+1];
	}
	cout << ans << endl;

	return 0;
}
