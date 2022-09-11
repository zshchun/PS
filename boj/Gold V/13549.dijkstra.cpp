#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, K, ans;

#define INF 123456789
int d[100001];
bool visited[100001];

void dijkstra(int s) {
	int cur, cur_dist, next, dist;
	fill(d, d+100001, INF);
	priority_queue<P, vector<P>, greater<P> > q;
	d[s] = 0;
	q.push(P(0, s));
	while (!q.empty()) {
		tie(cur_dist, cur) = q.top();
		q.pop();
		if (cur > 100000 || cur < 0) continue;
		if (cur-1 >= 0 && cur_dist + d[cur] < d[cur-1]) {
			d[cur-1] = cur_dist + d[cur];
			q.push(P(d[cur-1], cur-1));
		}
		if (cur+1 <= 100000 && cur_dist + d[cur] < d[cur+1]) {
			d[cur+1] = cur_dist + d[cur];
			q.push(P(d[cur+1], cur+1));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	dijkstra(N);
	cout << d[K] << '\n';
	return 0;
}

