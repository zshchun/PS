#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define distance(a, b) (abs(a.first-b.first)+abs(a.second-b.second))

int d[103][103];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, i, j, k;
	vector<pair<int,int>> v;
	cin >> T;
	while (T--) {
		cin >> N;
		N += 2;
		memset(d, 0x33, sizeof(d));
		v.resize(N);
		for (auto &p : v)
			cin >> p.first >> p.second;
		for (i=0;i<N;i++) {
			for (j=0;j<N;j++) {
				if (i == j) d[i][j] = 0;
				else if (distance(v[i], v[j]) <= 1000)
					d[i][j] = 1;
			}
		}
		for (k=0;k<N;k++) {
			for (i=0;i<N;i++) {
				for (j=0;j<N;j++) {
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				}
			}
		}
		if (d[0][N-1] < 0x33333333)
			cout << "happy\n";
		else
			cout << "sad\n";

	}
	return 0;
}

