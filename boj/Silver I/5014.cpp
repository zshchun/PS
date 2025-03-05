#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int f, s, g, u, d;
int visited[1000001];

void dfs(int x, int cur) {
	if (visited[x] <= cur) return;
	visited[x] = cur;

	int nu = x + u;
	int nd = x - d;
	if (nu > 0 && nu <= f)
		dfs(nu, cur + 1);
	if (nd > 0 && nd <= f)
		dfs(nd, cur + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> f >> s >> g >> u >> d;
	fill_n(visited, 1000001, INF);

	dfs(s, 0);

	if (visited[g] == INF)
		cout << "use the stairs\n";
	else
		cout << visited[g] << endl;
	return 0;
}
