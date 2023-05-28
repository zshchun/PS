#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int ans, N;
int a[13];
bool e[200001*13];

void dfs(int p, int c) {
	if (p == N) {
		if (c > 0 && !e[c]) {
			e[c] = 1;
			ans--;
		}
		return;
	}

	dfs(p+1, c + a[p]);
	dfs(p+1, c - a[p]);
	dfs(p+1, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;

	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
		ans += a[i];
	}

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}
