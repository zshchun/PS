#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll T, N, M;
ll a[1001];
ll b[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, ans = 0;
	cin >> T >> N;
	for (i=1;i<=N;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	cin >> M;
	for (i=1;i<=M;i++) {
		cin >> b[i];
		b[i] += b[i-1];
	}

	unordered_map<ll, ll> m;

	for (i=0;i<N;i++)
		for (j=i+1;j<=N;j++)
			m[a[j]-a[i]]++;

	for (i=0;i<M;i++)
		for (j=i+1;j<=M;j++)
			if (m.count(T-(b[j]-b[i])) > 0)
				ans += m[T-(b[j]-b[i])];

	cout << ans << endl;
	return 0;
}
