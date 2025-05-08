#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MOD 1'000'003;
int N, S, E, T;
ll a[51][51];
ll ans[51][51];

void mult(ll (&a)[51][51], ll (&b)[51][51]) {
	int i, j, k;
	ll c[51][51] = {0, };
	for (k=0;k<N*5;k++) {
		for (i=0;i<N*5;i++) {
			for (j=0;j<N*5;j++) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= MOD;
			}
		}
	}
	memcpy(a, c, sizeof(a));
}

void pow(int t) {
	while (t) {
		if (t & 1)
			mult(ans, a);
		t /= 2;
		mult(a, a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x;
	char c;
	cin >> N >> S >> E >> T;
	S--; E--;

	for (i=0;i<N;i++) {
		for (j=1;j<5;j++)
			a[5 * i + j][5 * i + j - 1] = 1;

		for (j=0;j<N;j++) {
			cin >> c; x = c - '0';
			if (x)
				a[5 * i][5 * j + x - 1] = 1;
		}
	}
	for (i=0;i<5*N;i++)
		ans[i][i] = 1;

	pow(T);
	cout << ans[5 * S][5 * E] << endl;

	return 0;
}
