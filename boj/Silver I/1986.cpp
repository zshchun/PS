#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, m, ans;
int a[1001][1001];
int b[1001][1001];

int q_dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int q_dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int k_dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int k_dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void move_queen(pa &p) {
	int y = p.first;
	int x = p.second;
	for (int i=0;i<8;i++) {
		int ny = y + q_dy[i];
		int nx = x + q_dx[i];
		while (ny >= 0 && ny < n && nx >= 0 && nx < m) {
			if (b[ny][nx]) break;
			a[ny][nx] = 1;
			ny += q_dy[i];
			nx += q_dx[i];
		}
	}
}

void move_knight(pa &p) {
	int y = p.first;
	int x = p.second;
	for (int i=0;i<8;i++) {
		int ny = y + k_dy[i];
		int nx = x + k_dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m)
			a[ny][nx] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, y, nr_q, nr_k, nr_p;
	cin >> n >> m;

	cin >> nr_q;
	vector<pa> q(nr_q);
	for (i=0;i<nr_q;i++) {
		cin >> y >> x;
		y--; x--;
		q[i] = pa(y, x);
		a[y][x] = b[y][x] = 1;
	}

	cin >> nr_k;
	vector<pa> k(nr_k);
	for (i=0;i<nr_k;i++) {
		cin >> y >> x;
		y--; x--;
		k[i] = pa(y, x);
		a[y][x] = b[y][x] = 1;
	}

	cin >> nr_p;
	vector<pa> p(nr_p);
	for (i=0;i<nr_p;i++) {
		cin >> y >> x;
		y--; x--;
		p[i] = pa(y, x);
		a[y][x] = b[y][x] = 1;
	}

	for (pa &w: q)
		move_queen(w);

	for (pa &w: k)
		move_knight(w);

	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (!a[i][j])
				ans++;

	cout << ans << endl;

	return 0;
}
