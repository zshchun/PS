#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, K, ans = 1234567;
int nth[100001];
#define MAX 100000
int visited[100001];
queue<P> q;
void bfs() {
	int x, n;
	fill(visited, visited+MAX+1, 1234567);
	q.push(P(N, 0));
	while (!q.empty()) {
		tie(x, n) = q.front();
		q.pop();

		if (x < 0 || x > MAX || n > ans) continue;
		if (visited[x] < n) continue; // 4ms
		if (x == K) {
			ans = n;
			nth[ans]++;
			continue;
		}
		visited[x] = n;
		q.push(P(x+1, n+1));
		q.push(P(x-1, n+1));
		q.push(P(x*2, n+1));

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	bfs();
	cout << ans << "\n" << nth[ans] << '\n';
	return 0;
}
