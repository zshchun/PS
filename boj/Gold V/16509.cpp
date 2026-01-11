#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
#define X second
#define Y first
int ans = -1;
pa el, king;
int visited[10][9];
pa dx[8] = {{-2, -3}, {-3, -2}, {-3, 2}, {-2, 3}, {2, 3}, {3, 2}, {3, -2}, {2, -3}};
pa obs[8][2] = {
	{{0, -1}, {-1, -2}},
	{{-1, 0}, {-2, -1}},
	{{-1, 0}, {-2, 1}},
	{{0, 1}, {-1, 2}},
	{{0, 1}, {1, 2}},
	{{1, 0}, {2, 1}},
	{{1, 0}, {2, -1}},
	{{0, -1}, {1, -2}}};

pa operator+(pa lhs, pa &rhs) {
	lhs.X += rhs.X;
	lhs.Y += rhs.Y;
	return lhs;
}

bool check(pa &p) {
	if (p.X < 0 || p.Y < 0 || p.X >= 9 || p.Y >= 10)
		return false;
	return true;
}

void bfs() {
	int i, j;
	queue<pa> q;
	q.push(el);
	visited[el.Y][el.X] = 0;
	while (!q.empty()) {
		pa cur = q.front();
		q.pop();
		for (i=0;i<8;i++) {
			bool possible = true;
			for (j=0;j<2;j++) {
				pa ob = obs[i][j] + cur;
				if (check(ob) == false || ob == king) {
					possible = false;
					break;
				}
			}
			pa next = dx[i] + cur;
			if (possible == false || check(next) == false || visited[next.Y][next.X] != -1)
				continue;
			visited[next.Y][next.X] = visited[cur.Y][cur.X] + 1;
			if (next == king)
				return;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill_n(visited[0], 10*9, -1);
	cin >> el.Y >> el.X >> king.Y >> king.X;
	bfs();
	cout << visited[king.Y][king.X] << endl;
	return 0;
}
