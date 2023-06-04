#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll R, C, N;
vector<string> s;

void dfs(int n, int sr, int sc, int er, int ec) {
	int step, start, end, i, j, dr, dc;
	if (n == 0)
		return;

	if (n % 2) {
		step = -1;
		start = er;
		end = sr;
	} else {
		step = 1;
		start = sr;
		end = er;
	}

	for (i=start;i!=end+step;i+=step) {
		if (i == start) {
			for (j=sc;j<=ec;j++)
				s[i][j] = '*';
		} else {
			s[i][sc+(i-start)*step] = '*';
			s[i][ec-(i-start)*step] = '*';
		}
	}

	dr = (1 << (n-1)) - 1;
	dc = (dr << 1) - 1;

	if (n % 2)
		dfs(n-1, (sr+er)/2, (sc+ec)/2-dc/2, er-1, (sc+ec)/2+dc/2);
	else
		dfs(n-1, sr+1, (sc+ec)/2-dc/2, (sr+er)/2, (sc+ec)/2+dc/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int i;
	R = (1 << N) - 1;
	C = (R << 1) - 1;

	for (i=0;i<R;i++) {
		s.push_back(string(C, ' '));
	}

	dfs(N, 0, 0, R-1, C-1);

	for (i=0;i<R;i++) {
		size_t sz = s[i].find_last_of("*");
		cout << s[i].substr(0, sz+1) << endl;
	}

	return 0;
}
