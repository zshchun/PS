#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
int a[51][51];
int r[51][4];
int c[51][4];

int bomboni() {
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	int x = 0;
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			for (int k=0;k<4;k++) {
				if (a[i][j] == k) {
					r[i][k] += a[i][j] == k;
					c[j][k] += a[i][j] == k;
					x = max({x, r[i][k], c[j][k]});
				} else {
					r[i][k] = 0;
					c[j][k] = 0;
				}
			}
		}
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = 0, cnt;
	char c;
	cin >> N;

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> c;
			if (c == 'C') {
				a[i][j] = 0;
			} else if (c == 'P') {
				a[i][j] = 1;
			} else if (c == 'Z') {
				a[i][j] = 2;
			} else if (c == 'Y') {
				a[i][j] = 3;
			}
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (i+1 < N) {
				swap(a[i][j], a[i+1][j]);
				cnt = bomboni();
				swap(a[i][j], a[i+1][j]);
				ans = max(cnt, ans);
			}
			if (j+1 < N) {
				swap(a[i][j], a[i][j+1]);
				cnt = bomboni();
				swap(a[i][j], a[i][j+1]);
				ans = max(cnt, ans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
