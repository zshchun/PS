#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N;
class D {
public:
	int d[6][6];
};

D operator*(D &x, D &y) {
	int i, j, l;
	D t;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			t.d[i][j] = 0;
			for (l=1;l<=N;l++) {
				t.d[i][j] += x.d[l][j] * y.d[i][l];
			}
			t.d[i][j] %= 1000;
		}
	}
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			x.d[i][j] = t.d[i][j];
		}
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll B, e;
	int i, j;
	D r, b;
	cin >> N >> B;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> b.d[i][j];
			if (i != j) r.d[i][j] = 0;
		}
		r.d[i][i] = 1;
	}
	e = B;
	while (e) {
		if (e & 1)
			r = r * b;
		e >>= 1;
		b = b * b;
	}
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			if (j > 1) cout << ' ';
			cout << r.d[i][j];
		}
		cout << '\n';
	}
	return 0;
}
