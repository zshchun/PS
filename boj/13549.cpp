#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, K;
#define INF 123456789
int visited[100001];
void bfs(int s) {
	int x, y;
	queue<P> q;
	fill(visited, visited+100001, INF);
	q.push(P(s, 0));
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		if (x == K) {
			if (visited[K] > y) visited[K] = y;
			continue;
		}
		if (visited[x] > y) visited[x] = y;
		if (x*2 <= 100000 && visited[x*2] > y)
			q.push(P(x*2, y));
		if (x+1 <= 100000 && visited[x+1] > y+1)
			q.push(P(x+1, y+1));
		if (x-1 >= 0 && visited[x-1] > y+1)
			q.push(P(x-1, y+1));

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	bfs(N);
	cout << visited[K] << '\n';
	return 0;
}
