#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int N, K;
int visited[100001];
int p[100001];

void bfs() {
	int cur, i;
	queue<int> q;
	q.push(N);
	visited[N] = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur == K)
			break;
		int v[3] = { cur + 1, cur - 1, cur * 2 };
		for (i=0;i<3;i++) {
			if (v[i] >= 0 && v[i] <= 100000 && visited[v[i]] == -1) {
				q.push(v[i]);
				visited[v[i]] = visited[cur] + 1;
				p[v[i]] = cur;
			}
		}
	}
}
int main() {
	cin >> N >> K;
	fill(visited, visited+100001, -1);
	
	bfs();
	vector<int> ans;
	int i = K;
	 while (i != N) {
		ans.push_back(i);
		i = p[i];
	}
	ans.push_back(N);
	reverse(ans.begin(), ans.end());
	cout << ans.size() - 1 << endl;
	for (int x: ans) {
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}
