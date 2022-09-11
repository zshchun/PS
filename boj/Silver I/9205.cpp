#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[101];
int N;
vector<pair<int,int>> v;
void dfs(int i) {
	if (i == N-1) return;
	for (int j=1;j<N;j++) {
		if (visited[j]) continue;
		int d = abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second);
		if (d <= 50*20) {
			visited[j] = 1;
			dfs(j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		N += 2;
		v.resize(N);
		memset(visited, 0, sizeof(visited));
		for (pair<int,int> &p : v)
			cin >> p.first >> p.second;
		dfs(0);
		if (visited[N-1])
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}

