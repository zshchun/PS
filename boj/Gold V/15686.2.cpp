#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define INF 123456789
int N, M, ans = INF;
vector<P> chicken, home;
int used[14];
int chicken_distance() {
	int i, j, sum=0;
	for (i=0;i<home.size();i++) {
		int x = INF;
		for (j=0;j<chicken.size();j++) {
			if (!used[j]) continue;
			int d = abs(chicken[j].first-home[i].first)+abs(chicken[j].second-home[i].second);
			if (x > d) x = d;
		}
		sum += x;
	}
	return sum;
}

void dfs(int c, int n) {
	if (c == M) {
		int d = chicken_distance();
		if (d < ans)
			ans = d;
		return;
	}
	int i;
	for (i=n;i<chicken.size();i++) {
		if (used[i]) continue;
		used[i] = 1;
		dfs(c+1, i+1);
		used[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int v;
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cin >> v;
			if (v == 2) {
				chicken.push_back(P(i, j));
			} else if (v == 1) {
				home.push_back(P(i, j));
			}
		}
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}

