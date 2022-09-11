#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int d[6][6];
int a[6][6];
int t[6][6];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll B;
	int N, i, j, k, l;
	cin >> N >> B;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> d[i][j];
			a[i][j] = d[i][j];
		}
	}
	for (k=1;k<B;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				t[i][j] = 0;
				for (l=1;l<=N;l++) {
					t[i][j] += a[l][j] * d[i][l];
				}
				t[i][j] %= 1000;
			}
		}
		memcpy(a, t, sizeof(t));
	}
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			if (j > 1) cout << ' ';
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}
