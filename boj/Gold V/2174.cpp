#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789

int A, B, N, M;
int a[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n, x, y, d;
	cin >> A >> B;
	cin >> N >> M;
	char c;
	vector<tup> robot;
	robot.push_back(tup(0, 0, 0));

	for (i=1;i<=N;i++) {
		cin >> x >> y >> c;
		if (c == 'N') d = 0;
		else if (c == 'E') d = 1;
		else if (c == 'S') d = 2;
		else if (c == 'W') d = 3;
		x--;
		y = B - y;
		robot.push_back(tup(y, x, d));
		a[y][x] = i;
	}

	for (i=0;i<M;i++) {
		cin >> k >> c >> n;
		tie(y, x, d) = robot[k];
		if (c == 'L') {
			robot[k] = tup(y, x, (d + 3 * n) % 4);
		} else if (c == 'R') {
			robot[k] = tup(y, x, (d + n) % 4);
		} else if (c == 'F') {
			int px = x;
			int py = y;
			for (j=0;j<n;j++) {
				x += dx[d];
				y += dy[d];
				if (y < 0 || x < 0 || x >= A || y >= B) {
					cout << "Robot " << k << " crashes into the wall\n";
					return 0;
				}
				if (a[y][x]) {
					cout << "Robot " << k << " crashes into robot " << a[y][x] << "\n";
					return 0;
				}
			}
			a[y][x] = k;
			a[py][px] = 0;
			robot[k] = tup(y, x, d);
		}
	}

	cout << "OK\n";

	return 0;
}
