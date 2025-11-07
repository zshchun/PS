#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, m, ans = INF;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int a[11][11];
struct ball {
	int x, y;
} blue, red, hole;

enum {
	EMPTY = 0,
	WALL,
};

#define IS_SAME(a, b) (memcmp(&a, &b, sizeof(struct ball)) == 0)
#define IS_DIFF(a, b) (memcmp(&a, &b, sizeof(struct ball)) != 0)

void dfs(int c, struct ball b, struct ball r) {
	if (c > 10) return;
	struct ball cr, cb, pr, pb;
	
	for (int i=0;i<4;i++) {
		int blue_drop = 0, red_drop = 0;
		cb.x = b.x; cb.y = b.y;
		cr.x = r.x; cr.y = r.y;
		while (1) {
			pb.x = cb.x; pb.y = cb.y;
			pr.x = cr.x; pr.y = cr.y;

			cb.x += dx[i]; cb.y += dy[i];
			if (IS_SAME(cb, hole)) blue_drop = 1;
			if (a[cb.y][cb.x] == WALL || IS_SAME(cb, cr)) {
				cb.x = pb.x;
				cb.y = pb.y;
			}

			if (IS_SAME(cr, hole)) red_drop = 1;
			cr.x += dx[i]; cr.y += dy[i];
			if (a[cr.y][cr.x] == WALL || IS_SAME(cb, cr)) {
				cr.x = pr.x;
				cr.y = pr.y;
			}
			if (IS_SAME(pr, cr) && IS_SAME(pb, cb))
				break;
		}

		if (IS_SAME(b, cb) && IS_SAME(r, cr)) continue;
		if (red_drop && !blue_drop) {
			ans = min(ans, c);
			continue;
		}
		if (!(red_drop|blue_drop))
			dfs(c+1, cb, cr);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	char c;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> c;
			if (c == '#') {
				a[i][j] = WALL;
			} else if (c == 'O') {
				hole.y = i;
				hole.x = j;
			} else if (c == 'B') {
				blue.y = i;
				blue.x = j;
			} else if (c == 'R') {
				red.y = i;
				red.x = j;
			}
		}
	}

	dfs(1, blue, red);

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;

	return 0;
}
