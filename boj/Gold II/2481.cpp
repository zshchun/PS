#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1094567890
int N, K, S, E;
vector<int> a;
unordered_map<int, int> s;
vector<int> g[100001];
int visited[100001];
int backtrace[100001];

void dijkstra() {
	fill_n(visited, N+1, INF);
	priority_queue<int, vector<int>, greater<int>> pq;
	visited[S] = 0;
	pq.push(S);
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		for (int &next : g[cur]) {
			if (visited[next] > visited[cur] + 1) {
				visited[next] = visited[cur] + 1;
				backtrace[next] = cur;
				pq.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, J;
	char c;
	cin >> N >> K;
	for (i=0;i<N;i++) {
		k = 0;
		for (j=K-1;j>=0;j--) {
			cin >> c;
			k |= (c - '0') << j;
		}
		a.push_back(k);
		s.insert({k, i});
	}

	for (i=0;i<N;i++) {
		for (j=0;j<K;j++) {
			k = a[i] ^ (1 << j);
			if (s.find(k) != s.end()) {
				g[i].push_back(s[k]);
			}
		}
	}
	cin >> J;
	S = 0;
	dijkstra();
	while (J--) {
		cin >> E;
		E--;


		if (visited[E] == INF) {
			cout << "-1\n";
		} else {
			vector<int> ans;
			i = E;
			while (i != S) {
				ans.push_back(i+1);
				i = backtrace[i];
			}
			ans.push_back(S+1);
			for (i=ans.size()-1;i>=0;i--)
				cout << ans[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}
