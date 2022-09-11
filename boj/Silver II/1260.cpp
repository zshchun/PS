#include <bits/stdc++.h>
using namespace std;
char *visited;
int v, e;
char *a;

void dfs(int n) {
	cout << n << ' ';
	visited[n] = 1;
	for (int i=1;i<=v;i++) {
		if (a[n*v+i] == 1 && !visited[i]) {
			dfs(i);
		}
	}
}
void bfs(int n) {
	queue<int> q;
	q.push(n);
	int i, j;
	visited[n] = 1;
	while(!q.empty()) {
		i = q.front();
		q.pop();
		cout << i << ' ';
		for (j=1;j<=v;j++) {
			if (a[i*v+j] == 1 && !visited[j]) {
				q.push(j);
				visited[j] = 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	int b, i, x, y;
	cin >> v >> e >> b;

	visited = new char[v+1];
	a = new char[(v+1)*v+1];
	for (i=0;i<(v+1)*v+1;i++)
		a[i] = 0;
	for (i=0;i<e;i++) {
		cin >> x >> y;
		a[x*v+y] = 1;
		a[y*v+x] = 1;
	}
	memset(visited, 0, v+1);
	dfs(b);
	cout << '\n';

	memset(visited, 0, v+1);
	bfs(b);
	cout << '\n';
	
	return 0;
}



