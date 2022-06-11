#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int m, n, i, x, y;
	char c;
	queue<int> q;
	cin >> n >> m;
	int *a = new int[m*n];
	int *visited = new int[m*n];
	for (i=0;i<n*m;i++) {
		do {
			cin.get(c);
		} while (c != '0' && c != '1');
		if (c == '1')
			a[i] = 1;
		else if (c == '0')
			a[i] = 0;
		visited[i] = 0;
	}

	q.push(0);
	visited[0] = 1;
	i = 0;
	while(!q.empty() && i != (m*n-1)) {
		i = q.front();
		q.pop();
		x = i % m;
		y = i / m;
		if ((y-1) >= 0 && a[i-m] && !visited[i-m]) {
			q.push(i-m); // up
			visited[i-m] = visited[i]+1;
		}
		if ((x-1) >= 0 && a[i-1] && !visited[i-1]) {
			q.push(i-1); // left
			visited[i-1] = visited[i]+1;
		}
		if ((y+1) < n && a[i+m] && !visited[i+m]) {
			q.push(i+m); // down
			visited[i+m] = visited[i]+1;
		}
		if ((x+1) < m && a[i+1] && !visited[i+1]) {
			q.push(i+1); // right
			visited[i+1] = visited[i]+1;
		}
	}
	cout << visited[m*n-1] << "\n";
	return 0;
}
