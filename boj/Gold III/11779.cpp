#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, M;
vector<P> b[1001];
bool visited[1001];
int update[1001];
stack<int> route;
#define INF 123456789
int d[1001] = {INF, };
void dijkstra(int s) {
	int cur, cur_dist;
	fill(d, d+1001, INF);
	priority_queue<P, vector<P>, greater<P> > pq;
	pq.push(P(0, s));
	d[s] = 0;
	while(!pq.empty()) {
		tie(cur_dist, cur) = pq.top();
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (P &n : b[cur]) {
			int next = n.first, dist = n.second;
			if (d[next] > cur_dist + dist) {
				update[next] = cur;
				d[next] = cur_dist + dist;
				pq.push(P(d[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int u, v, t, i;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v >> t;
		b[u].push_back(P(v, t));
	}
	cin >> u >> v;
	dijkstra(u);
	i = v;
	cout << d[v] << '\n';
	while(i != u) {
		route.push(i);
		i = update[i];
	}
	route.push(u);
	cout << route.size() << '\n';
	while (!route.empty()) {
		if (route.top() != u)
			cout << ' ';
		cout << route.top();
		route.pop();
	}
	cout << '\n';
	return 0;
}

