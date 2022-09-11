#include <bits/stdc++.h>
using namespace std;
int N;
int m[101][101];
bool visited[101];

void bfs(int n) {
	int i, j;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		i = q.front();
		q.pop();
		for (j=1;j<=N;j++) {
			if (m[i][j] && !visited[j]) {
				q.push(j);
				visited[j] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> m[i][j];
		}
	}
	for (i=1;i<=N;i++) {
		bfs(i);
		for (j=1;j<=N;j++) {
			if (j > 1) cout << ' ';
			cout << visited[j];
		}
		cout << '\n';
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
