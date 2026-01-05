#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
#define X first
#define Y second

ll dp[501][501];
ll dist[501][501];
ll N, K, ans = INF;
pa a[501];

inline ll distance(pa &a, pa &b) {
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k;
	cin >> N >> K;
	for (i=0;i<N;i++)
		cin >> a[i].X >> a[i].Y;

	fill_n(dp[0]+1, 501*501-1, INF);

	for (i=0;i<N;i++) {
		for (j=i+1;j<N;j++)
			dist[i][j] = distance(a[i], a[j]);
		if (i)
			dp[i][0] = dp[i-1][0] + dist[i-1][i];
	}

	for (i=0;i<N;i++) {
		for (j=0;j<=K;j++) {
			for (k=0;k<=K;k++) {
				int prev = i - k - 1;
				int prev_k = j - k;
				if (prev_k >= 0 && prev >= 0 && j+k > 0)
					dp[i][j] = min(dp[i][j], dp[prev][prev_k] + dist[prev][i]);
			}
		}
	}

	cout << *min_element(dp[N-1], dp[N-1]+K+1) << endl;

	return 0;
}
