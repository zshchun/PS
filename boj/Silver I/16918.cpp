#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int R, C, N;
int a[202][202];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, t = 3;
	char c;
	cin >> R >> C >> N;
	for (i=1;i<=R;i++) {
		for (j=1;j<=C;j++) {
			cin >> c;
			if (c == 'O')
				a[i][j] = 1;
		}
	}

	while (t <= N+1) {
		vector<pa> s;
		for (i=1;i<=R;i++) {
			for (j=1;j<=C;j++) {
				if (t & 1) {
					if (a[i][j] == 0)
						a[i][j] = t;
				} else {
					if (a[i][j] && a[i][j]+3 <= t) {
						s.push_back(pa(i-1, j));
						s.push_back(pa(i, j-1));
						s.push_back(pa(i, j));
						s.push_back(pa(i, j+1));
						s.push_back(pa(i+1, j));
					}
				}
			}
		}
		s.erase(unique(s.begin(), s.end()), s.end());
		for (pa &p: s)
			a[p.first][p.second] = 0;
		t++;
	}
	for (i=1;i<=R;i++) {
		for (j=1;j<=C;j++) {
			cout << (a[i][j] ? 'O' : '.');
		}
		cout << endl;
	}


	return 0;
}
