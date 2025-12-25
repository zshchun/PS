#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[1000001];
int b[1000001];
ll tree[500001];
ll N, ans;

// Fenwick Tree, Inversion counting
void update(int i, ll v) {
	while (i <= N) {
		tree[i] += v;
		i += i & -i;
	}
}

ll sum(int i) {
	ll ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= i & -i;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, v;
	cin >> N;
	for (i=1;i<=N;i++)
		cin >> a[i];
	for (i=1;i<=N;i++) {
		cin >> v;
		b[v] = i;
	}
	for (i=1;i<=N;i++) {
		j = b[a[i]];
		ans += (i-1) - sum(j-1);
		update(j, 1);
	}
	cout << ans << endl;
	return 0;
}
