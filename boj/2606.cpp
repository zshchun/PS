#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, u, v, c;
	cin>>n>>t;
	vector<bool> visited(n+1, false);
	vector<int> a[n+1];
	queue<int> q;
	while(t--) {
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	c = 0;
	q.push(1);
	visited[1] = true;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for (vector<int>::iterator it=a[u].begin();it!=a[u].end();++it) {
			if (visited[*it])
				continue;
			q.push(*it);
			visited[*it] = true;
			c++;
		}
	}
	cout << c << '\n';
	return 0;
}

