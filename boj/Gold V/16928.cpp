#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int visited[101];
int ladder[101];
void bfs(int a) {
	queue<int> q;
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == 100) return;
		for (int j=1;j<=6;j++) {
			if (v+j <= 100 && !visited[v+j]) {
				int jmp = v+j;
				while (ladder[jmp] && !visited[ladder[jmp]]) {
					visited[jmp] = visited[v] + 1;
					jmp = ladder[jmp];
				}
				if (!ladder[jmp] && !visited[jmp])
					q.push(jmp);
				visited[jmp] = visited[v] + 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, from, to;
	cin >> N >> M;
	for (i=0;i<N+M;i++) {
		cin >> from >> to;
		ladder[from] = to;
	}
	bfs(1);
	cout << visited[100]-1 << '\n';
	return 0;
}

