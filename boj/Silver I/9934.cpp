#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int t, N;
int a[1025];
vector<int> g[11];

void dfs(int n, int p, int m) {
	if (n >= N)
		return;
	g[n].push_back(a[p+m]);
	dfs(n+1, p, m/2);
	dfs(n+1, p+m+1, m/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N;
	t = (1 << N) - 1;

	for (i=0;i<=t;i++)
		cin >> a[i];

	dfs(0, 0, t/2);

	for (i=0;i<N;i++) {
		for (int x: g[i])
			cout << x << ' ';
		cout << endl;
	}

	return 0;
}
