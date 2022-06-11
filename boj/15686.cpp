#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define INF 1234567891
ll N, M, ans = INF;
vector<P> ch, hs;
bool used[14];
ll h[101];
ll val[101][14];

void dfs(ll c, ll n) {
	ll i, j, dist, sum=0;
	if (n == M) {
		for (j=0;j<hs.size();j++)
			sum += h[j];
		if (sum < ans)
			ans = sum;

		return;
	}
	for (i=c;i<ch.size();i++) {
		if (used[i]) continue;

		vector<P> bck;
		for (j=0;j<hs.size();j++) {
			if (val[j][i] < h[j]) {
				bck.emplace_back(P(j, h[j]));
				h[j] = val[j][i];
			}
		}
		used[i] = 1;
		dfs(i, n+1);
		used[i] = 0;
		for (P &p : bck) {
			h[p.first] = p.second;
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, v;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> v;
			if (v == 1)
				hs.push_back(P(i, j));
			else if (v == 2)
				ch.push_back(P(i, j));
		}
	}
	fill_n(h, hs.size()+1, INF);
	for (i=0;i<hs.size();i++) {
		for (j=0;j<ch.size();j++) {
			val[i][j] = abs(hs[i].first-ch[j].first) + abs(hs[i].second-ch[j].second);
		}
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}

