#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tup;
#define endl "\n"

ll n;
int a[21*21][5];
int b[21][21];
int f[21][21];
int friends[21*21][4];
pa pos[21*21];
int room[21][21];
//class compare {
//public:
//	bool operator()(const pa &lhs, const pa &rhs) const {
//		if (lhs.first == rhs.first)
//			return lhs.second < rhs.second;
//		return lhs.first < rhs.first;
//	}
//};
//set<pa, compare> room[5];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, v, y, x, k, l, o, ny, nx, ans = 0;
	cin >> n;

	for (i=0;i<n*n;i++) {
		for (j=0;j<5;j++) {
			cin >> a[i][j];
		}
	}

	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			v = 4;
			if (i == 1 || i == n)
				v--;
			if (j == 1 || j == n)
				v--;
			room[i][j] = v;
		}
	}

	for (i=0;i<n*n;i++) {
		bool found = false;
		vector<tup> vec;
		memset(f, 0, sizeof(f));
		for (j=1;j<=4;j++) {
			friends[a[i][0]][j-1] = a[i][j];
			pa p = pos[a[i][j]];
			y = p.first;
			x = p.second;
			if (y != 0 && x != 0) {
				for (k=0;k<4;k++) {
					ny = y + dy[k];
					nx = x + dx[k];
					if (ny <= 0 || nx <= 0 || ny > n || nx > n)
						continue;
					f[ny][nx]++;
				}
			}
		}
		for (j=1;j<=n;j++) {
			for (k=1;k<=n;k++) {
				if (!b[j][k])
					vec.push_back(make_tuple(j, k, f[j][k], room[j][k]));
			}
		}
		sort(vec.begin(), vec.end(), [&](const tup &lhs, const tup &rhs) {
			int ly, lx, lf, lr, ry, rx, rf, rr;
			tie(ly, lx, lf, lr) = lhs;
			tie(ry, rx, rf, rr) = rhs;
			if (lf != rf)
				return lf > rf;
			if (lr != rr)
				return lr > rr;
			if (ly != ry)
				return ly < ry;
			return lx < rx;
		});
		y = get<0>(*vec.begin());
		x = get<1>(*vec.begin());
		b[y][x] = a[i][0];
		pos[a[i][0]] = pa(y, x);

		for (k=0;k<4;k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			if (ny <= 0 || nx <= 0 || ny > n || nx > n)
				continue;
			if (room[ny][nx] > 0)
				room[ny][nx]--;
		}
	}

	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			v = 0;
			o = b[i][j];
			for (k=0;k<4;k++) {
				for (l=0;l<4;l++) {
					ny = i + dy[l];
					nx = j + dx[l];
					if (ny <= 0 || nx <= 0 || ny > n || nx > n)
						continue;
					if (b[ny][nx] == friends[o][k])
						v++;
				}
			}
			if (v == 1)
				ans++;
			else if (v == 2)
				ans += 10;
			else if (v == 3)
				ans += 100;
			else if (v == 4)
				ans += 1000;
		}
	}

	cout << ans << endl;

	return 0;
}
