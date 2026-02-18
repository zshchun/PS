#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int N, ans;
int a[21][21];
#define DIRT 1
#define JEWEL 2
#define VERT 0
#define HORI 1

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

typedef struct point {
	int y, x;
} point_t;

int dfs(point_t s, point_t e, int dir) {
	int i, j, dirt = 0, jewel = 0;
	vector<point_t> d;
	for (i=s.y;i<=e.y;i++) {
		for (j=s.x;j<=e.x;j++) {
			if (a[i][j] == DIRT) {
				dirt++;
				d.push_back(point_t{i, j});
			} else if (a[i][j] == JEWEL) {
				jewel++;
			}
		}
	}
	if (dirt == 0 && jewel == 1) {
		return 1;
	}
	if (dirt + 1 != jewel) {
		return 0;
	}

	int ret = 0, cnt1, cnt2;
	point_t top_s = s, top_e = e, bot_s = s, bot_e = e;
	point_t left_s = s, left_e = e, right_s = s, right_e = e;
	for (point_t p : d) {
		bool possible = true;

		if (dir == VERT) {
			left_e.x = p.x - 1; right_s.x = p.x + 1;
			for (i=s.y;i<=e.y;i++) {
				if (a[i][p.x] == JEWEL) {
					possible = false;
					break;
				}
			}
			if (!possible) continue;
			cnt1 = dfs(left_s, left_e, !dir);
			if (cnt1 == 0) continue;
			cnt2 = dfs(right_s, right_e, !dir);
			if (cnt2 == 0) continue;
		} else if (dir == HORI) {
			top_e.y = p.y - 1; bot_s.y = p.y + 1;
			for (i=s.x;i<=e.x;i++) {
				if (a[p.y][i] == JEWEL) {
					possible = false;
					break;
				}
			}
			if (!possible) continue;

			cnt1 = dfs(top_s, top_e, !dir);
			if (cnt1 == 0) continue;
			cnt2 = dfs(bot_s, bot_e, !dir);
			if (cnt2 == 0) continue;
		}
		ret += cnt1 * cnt2;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> a[i][j];

	point_t start = {0, 0};
	point_t end = {N-1, N-1};

	ans = dfs(start, end, VERT) + dfs(start, end, HORI);

	if (ans == 0)
		cout << "-1\n";
	else
		cout << ans << endl;
	return 0;
}
