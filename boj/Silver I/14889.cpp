#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, ans = INF;
int a[21][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, l;

	cin >> N;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin >> a[i][j];

	for (k=0;k<(1<<N);k++) {
		if (__builtin_popcount(k) != (N>>1)) continue;
		vector<int> p;
		for (i=0;i<20;i++)
			if (k & (1<<i)) p.push_back(i+1);
		for (i=0;i<20;i++)
			if (!(k & (1<<i))) p.push_back(i+1);

		int diff[2] = { 0, 0 };
		for (i=0;i<N/2;i++)
			for (j=0;j<N/2;j++)
				diff[0] += a[p[i]][p[j]];

		for (i=N/2;i<N;i++)
			for (j=N/2;j<N;j++)
				diff[1] += a[p[i]][p[j]];

		ans = min(ans, abs(diff[0]-diff[1]));
	}

	cout << ans << endl;

	return 0;
}
