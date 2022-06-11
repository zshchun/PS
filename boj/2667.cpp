#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
int **visited;
int **m;
int n;

int bfs(int a, int b) {
	pair<int, int> r;
	int i, j, y, x, k, cnt=0;
	q.push(pair<int,int>(a, b));
	visited[a][b] = 1;
	int ds[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!q.empty()) {
		cnt++;
		r = q.front();
		q.pop();
		i = r.first;
		j = r.second;
		for (k=0;k<4;k++) {
			y = i + ds[k][0];
			x = j + ds[k][1];
			if (y >= 0 && y < n && x >= 0 && x < n && !visited[y][x] && m[y][x]) {
				q.push(pair<int,int>(y, x));
				visited[y][x] = 1;
			}
		}
	}
	return cnt;
}

int main() {
	vector<int> h;
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int i, j;
	string l;
	cin >> n;
	visited = new int*[n];
	m = new int*[n];
	for (i=0;i<n;++i) {
		m[i] = new int[n];
		visited[i] = new int[n];
	}

	for (i=0;i<n;i++) {
		cin >> l;
		for (j=0;j<n;j++) {
			m[i][j] = l[j] - '0';
			visited[i][j] = 0;
		}
	}
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (m[i][j] && !visited[i][j]) {
				h.push_back(bfs(i, j));
			}
		}
	}
	sort(h.begin(), h.end());
	cout << h.size() << '\n';
	for (i=0;i<h.size();i++) {
		cout << h[i] << '\n';
	}

	return 0;
}
