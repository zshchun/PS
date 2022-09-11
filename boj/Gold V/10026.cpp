#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int a[100][100];
int visited[100][100];
int cvisited[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int n, int m) {
	int x, y, i;
	queue<pair<int,int>> q;
	pair<int,int> p;
	q.push(make_pair(n, m));
	visited[n][m] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for(i=0;i<4;i++) {
			x = p.first+dir[i][0];
			y = p.second+dir[i][1];
			if (x>=0 && x<N && y>=0 && y<N && a[n][m] == a[x][y] && !visited[x][y]) {
				q.push(make_pair(x, y));
				visited[x][y] = 1;
			}
		}
	}
}

void cbfs(int n, int m) {
	int x, y, i, v1, v2;
	queue<pair<int,int>> q;
	pair<int,int> p;
	q.push(make_pair(n, m));
	cvisited[n][m] = 1;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		v1 = a[n][m] <= 2 ? 1 : 3;
		for(i=0;i<4;i++) {
			x = p.first+dir[i][0];
			y = p.second+dir[i][1];
			v2 = a[x][y] <= 2 ? 1 : 3;
			if (x>=0 && x<N && y>=0 && y<N && v1 == v2 && !cvisited[x][y]) {
				q.push(make_pair(x, y));
				cvisited[x][y] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	string s;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> s;
		for (j=0;j<N;j++) {
			if (s[j] == 'R')
				a[i][j] = 1;
			else if (s[j] == 'G')
				a[i][j] = 2;
			else if (s[j] == 'B')
				a[i][j] = 3;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				ans1++;
			}
			if (!cvisited[i][j]) {
				cbfs(i, j);
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2 << '\n';
	return 0;
}

