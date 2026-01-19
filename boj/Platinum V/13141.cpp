#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int N, M;
double ans = INF;
int a[201][201];
vector<tup> t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, s, e, l;
	fill_n(a[0], 201*201, INF);
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> s >> e >> l;
		s--; e--;
		t.push_back(tup(s, e, l));
		a[s][e] = min(a[s][e], l);
		a[e][s] = min(a[e][s], l);
	}
	for (i=0;i<N;i++)
		a[i][i] = 0;

	// floyd warshall
	for (k=0;k<N;k++) {
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	for (i=0;i<N;i++) {
		double mx = 0;
		for (auto [s, e, l] : t) {
			mx = max(mx, (a[i][s]+a[i][e]+l) / 2.0);
		}
		ans = min(ans, mx);
	}

	cout << fixed << setprecision(1) << ans << endl;
	return 0;
}
