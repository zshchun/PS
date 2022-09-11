#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N;
int b[6][6];
int r[6][6];

void mult(int x[][6], int y[][6]) {
	int t[6][6];
	int i, j, l;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			t[i][j] = 0;
			for (l=1;l<=N;l++) {
				t[i][j] += x[l][j] * y[i][l];
			}
			t[i][j] %= 1000;
		}
	}
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			x[i][j] = t[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll B, e;
	int i, j;
	cin >> N >> B;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> b[i][j];
		}
		r[i][i] = 1;
	}
	e = B;
	while (e) {
		if (e & 1)
			mult(r, b);
		e >>= 1;
		mult(b, b);
	}
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			if (j > 1) cout << ' ';
			cout << r[i][j];
		}
		cout << '\n';
	}
	return 0;
}
