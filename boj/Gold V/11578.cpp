#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans = INF;
int perfect;
int a[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, v;
	cin >> N >> M;
	perfect = (1 << N) - 1;
	for (i=0;i<M;i++) {
		cin >> k;
		for (j=0;j<k;j++) {
			cin >> v;
			a[i] |= 1 << (v - 1);
		}
	}
	for (i=0;i<(1<<M);i++) {
		int solved = 0;
		for (j=0;j<M;j++)
			if (i & (1 << j))
				solved |= a[j];
		if (perfect == solved)
			ans = min(ans, __builtin_popcount(i));
	}
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
