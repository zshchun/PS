#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl "\n"
#define INF 123456789
inline ull mask(ull x) {
	int c = __builtin_ffsll(x) - 1;
	if (c % 8 == 0) {
		return (x << 1) | (x << 8) | (x >> 8) | (x << 9) | (x >> 7);
	} else if (c % 8 == 7) {
		return (x >> 1) | (x << 8) | (x >> 8) | (x >> 9) | (x << 7);
	}
	return UINT64_MAX;
}

int ans;
int d[4] = { 1, 7, 8, 9 };

void dfs(ull m, ull c) {
	if (ans) return;
	if (m & c) return;
	if (m == 0 || c == 1) {
		ans = 1;
		return;
	}
	ull bm = mask(c);
	for (int i=0;i<4;i++) {
		if (((c << d[i]) & bm) && !(m & (c<<d[i]))) {
			dfs(m << 8, c << d[i]);
		}
		if (((c >> d[i]) & bm) && !(m & (c>>d[i]))) {
			dfs(m << 8, c >> d[i]);
		}
	}
	dfs(m << 8, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ull m = 0;
	int i, j;
	char c;
	for (i=0;i<64;i+=8) {
		for (j=7;j>=0;j--) {
			cin >> c;
			if (c == '#')
				m |= 1ULL << (i + j);
		}
	}

	dfs(m, 1ULL<<63);
	cout << ans << endl;
	return 0;
}
