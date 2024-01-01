#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, K;
int a[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, ans = 0;
	map<ll,ll> m;

	cin >> N >> K;
	for (i=1;i<=N;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (i=1;i<=N;i++) {
		if (a[i] == K) ans++;
		if (m.count(a[i] - K))
			ans += m[a[i] - K];
		m[a[i]]++;
	}

	cout << ans << endl;
	return 0;
}
