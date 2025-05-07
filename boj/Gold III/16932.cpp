#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans, idx;
int a[1001][1001];
int visited[1001][1001];
int cnt[1000*1000+1];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pa> q;

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = idx;
	q.push_back(pa(y, x));

	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N || !a[ny][nx])
			continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	cin >> N >> M;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			cin >> a[i][j];

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				q.clear();
				idx++;
				dfs(i, j);
				cnt[idx] = q.size();
			}
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (a[i][j] == 0) {
				int total = 1;
				unordered_set<int> s;
				for (k=0;k<4;k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N || !visited[ny][nx]) continue;
					if (s.count(visited[ny][nx]) == 0)
						total += cnt[visited[ny][nx]];
					s.insert(visited[ny][nx]);
				}
				ans = max(ans, total);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
