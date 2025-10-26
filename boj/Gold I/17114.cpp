#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int,int,int,int,int,int,int,int,int,int> tup;
#define endl "\n"
#define INF 123456789
int ans, cnt;
int M, N, O, P, Q, R, S, T, U, V, W;
#define foreach() \
	 for (w=0;w<W;w++) \
	 for (v=0;v<V;v++) \
	 for (u=0;u<U;u++) \
	 for (t=0;t<T;t++) \
	 for (s=0;s<S;s++) \
	 for (r=0;r<R;r++) \
	 for (q=0;q<Q;q++) \
	 for (p=0;p<P;p++) \
	 for (o=0;o<O;o++) \
	 for (n=0;n<N;n++) \
	 for (m=0;m<M;m++) \

int dx[22][11] = {
		{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, m, n, o, p, q, r, s, t, u, v, w, d;
	cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;
	int a[M][N][O][P][Q][R][S][T][U][V][W];
	queue<tup> qu;
	foreach() {
		cin >> x;
		a[m][n][o][p][q][r][s][t][u][v][w] = x;
		if (x == 1)
			qu.push(tup(0, m, n, o, p, q, r, s, t, u, v, w));
		else if (x == 0)
			cnt++;
	}

	// BFS
	while (!qu.empty()) {
		tie(d, m, n, o, p, q, r, s, t, u, v, w) = qu.front();
		qu.pop();
		ans = max(ans, d);
		for (auto [dm, dn, no, dp, dq, dr, ds, dt, du, dv, dw] : dx) {
			dm += m; dn += n; no += o; dp += p; dq += q; dr += r; ds += s; dt += t; du += u; dv += v; dw += w;
			if (dm < 0 || dm >= M) continue;
			if (dn < 0 || dn >= N) continue;
			if (no < 0 || no >= O) continue;
			if (dp < 0 || dp >= P) continue;
			if (dq < 0 || dq >= Q) continue;
			if (dr < 0 || dr >= R) continue;
			if (ds < 0 || ds >= S) continue;
			if (dt < 0 || dt >= T) continue;
			if (du < 0 || du >= U) continue;
			if (dv < 0 || dv >= V) continue;
			if (dw < 0 || dw >= W) continue;
			if (!a[dm][dn][no][dp][dq][dr][ds][dt][du][dv][dw]) {
				a[dm][dn][no][dp][dq][dr][ds][dt][du][dv][dw] = 1;
				qu.push(tup(d+1, dm, dn, no, dp, dq, dr, ds, dt, du, dv, dw));
				cnt--;
			}
		}
	}

	if (cnt)
		cout << "-1\n";
	else
		cout << ans << endl;

	return 0;
}
