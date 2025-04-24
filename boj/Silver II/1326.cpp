#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, S, E;
int jump[10001];
int visited[10001];

void bfs() {
	queue<int> q;
	q.push(S);
	visited[S] = 0;
	while (!q.empty()) {
		int cur = q.front();
		int step = jump[cur];
		q.pop();
		for (int left = cur-step;left>0;left-=step) {
			if (left > 0 && visited[left] == -1) {
				q.push(left);
				visited[left] = visited[cur] + 1;
			}
		}
		for (int right = cur+jump[cur];right<=N;right+=jump[cur]) {
			if (right <= N && visited[right] == -1) {
				q.push(right);
				visited[right] = visited[cur] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=1;i<=N;i++)
		cin >> jump[i];
	cin >> S >> E;

	fill_n(visited, 10001, -1);

	bfs();

	cout << visited[E] << endl;

	return 0;
}
