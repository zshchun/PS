#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;

typedef tuple<int,int,int,int> tup;
int p[3001];


int find(int x) {
	if (p[x] < 0) {
		return x;
	}
	return p[x] = find(p[x]);
}

void _union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
	}
}


// CCW CounterClockWise
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int ret = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	else
		return 0;
}

bool is_intersect(tup &t1, tup &t2) {
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	tie(x1, y1, x2, y2) = t1;
	tie(x3, y3, x4, y4) = t2;
	int ret1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int ret2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

	if (ret1 == 0 && ret2 == 0) {
		if (y1 == y2 && y1 == y3 && y1 == y4) {
			y1 = x1; y2 = x2; y3 = x3; y4 = x4;
		}
		if (y1 > y2) swap(y1, y2);
		if (y3 > y4) swap(y3, y4);
		return y1 <= y4 && y2 >= y3;
	} else if (ret1 <= 0 && ret2 <= 0) {
		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	vector<tup> t;
	cin.tie(0);
	int i, j, x1, y1, x2, y2;
	cin >> N;
	fill_n(p, 3001, -1);

	for (i=0;i<N;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		t.push_back(tup(x1, y1, x2, y2));
	}

	for (i=0;i<N;i++) {
		for (j=0;j<i;j++) {
			if (is_intersect(t[i], t[j])) {
				_union(i, j);
			}
		}
	}
	int ans1 = 0;
	int ans2 = 0;
	for (i=0;i<N;i++) {
		ans1 = min(ans1, p[i]);
		if (p[i] < 0)
			ans2++;
	}
	cout << ans2 << endl;
	cout << -ans1 << endl;

	return 0;
}
