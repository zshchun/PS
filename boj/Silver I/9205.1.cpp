#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> a;
bool visited[101];
bool dfs(int i) {
	if (i == N-1) return true;
	for (int j=1;j<N;j++) {
		if (visited[j]) continue;
		int dx = abs(a[i].first-a[j].first);
		int dy = abs(a[i].second-a[j].second);
		if (dx+dy <= 1000) {
			visited[j] = true;
			if (dfs(j)) return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--) {
		cin >> N;
		N += 2;
		a.resize(N);
		memset(visited, 0, sizeof(visited));
		for (pair<int,int> &p: a) {
			cin >> p.first >> p.second;
			p.first += 32768;
			p.second += 32768;
		}
		visited[0] = true;
		cout << (dfs(0) ? "happy" : "sad") << '\n';
	}
	return 0;
}
