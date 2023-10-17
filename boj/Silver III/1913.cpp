#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, P;
int a[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0}; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, m, y, x, nx, ny, k = 1;
	int px, py;
	cin >> N >> P;
	m = N / 2;
	x = y = m;
	i = 0;
	j = 1;

	while (x >= 0 && x < N && y >= 0 && y < N) {
		if (P == k) {
			px = x + 1;
			py = y + 1;
		}
		a[y][x] = k++;
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < m-j || nx > m+j || ny < m-j || ny > m+j) {
			i = (i + 1) % 4;
			if (i == 0) j++;
			nx = x + dx[i];
			ny = y + dy[i];
		}
		x = nx;
		y = ny;
	}

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	cout << py << ' ' << px << endl;
	return 0;
}
