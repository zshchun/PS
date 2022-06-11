#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
bool visited[100001];
vector<pair<int,int>> m[100001];
int node, dist;
void dfs(int x, int w) {
	int i, a, b;
	if (visited[x]) return;
	visited[x] = 1;
	if (dist < w) {
		node = x;
		dist = w;
	}
	for (i=0;i<(int)m[x].size();i++) {
		tie(a, b) = m[x][i];
		dfs(a, w+b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, x, y, n;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> n;
		while (1) {
			cin >> x;
			if (x == -1) break;
			cin >> y;
			m[n].push_back(make_pair(x, y));
		}
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(node, 0);
	cout << dist << '\n';
	return 0;
}

