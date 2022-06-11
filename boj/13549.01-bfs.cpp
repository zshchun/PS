#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, K, ans;
bool visited[100001];

void bfs(int s) {
	deque<P> q;
	int n, d;
	q.push_back(P(s, 0));
	while(!q.empty()) {
		tie(n, d) = q.front();
		q.pop_front();

		if (n == K) {
			ans = d;
			break;
		}
		visited[n] = 1;
		if (n*2 <= 100000 && !visited[n*2]) q.push_front(P(n*2, d));
		if (n+1 <= 100000 && !visited[n+1]) q.push_back(P(n+1, d+1));
		if (n-1 >= 0 && !visited[n-1]) q.push_back(P(n-1, d+1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	bfs(N);
	cout << ans << '\n';
	return 0;
}

