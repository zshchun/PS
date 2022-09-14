#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll ans, N, M;
ll dx[4] = { 0, 0, 1, -1 };
ll dy[4] = { 1, -1, 0, 0 };

void dfs(vector<vector<ll>> &campus, vector<vector<ll>> &visited, ll y, ll x) {
	if (visited[y][x]) return;
	if (campus[y][x] == -1) return;
	if (campus[y][x] == 1) ans++;

	visited[y][x] = 1;
	for (ll i=0;i<4;i++) {
		ll nx = x + dx[i];
		ll ny = y + dy[i];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
		dfs(campus, visited, ny, nx);
	}
}

int main() {
	ll i, j, y, x;
	cin >> N >> M;
	vector<vector<ll>> campus(N, vector<ll>(M));
	vector<vector<ll>> visited(N, vector<ll>(M));
	string s;
	for (i=0;i<N;i++) {
		cin >> s;
		for (j=0;j<M;j++) {
			if (s[j] == 'P')
				campus[i][j] = 1;
			else if (s[j] == 'I') {
				y = i;
				x = j;
			} else if (s[j] == 'X') {
				campus[i][j] = -1;
			}
		}
	}

	dfs(campus, visited, y, x);

	if (ans == 0)
		cout << "TT\n";
	else
		cout << ans << endl;

	return 0;
}
