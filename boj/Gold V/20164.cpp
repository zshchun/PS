#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<vector<int>,int> pa;
#define endl "\n"
#define INF 123456789
int n, mn = INF, mx;

void dfs(int x, int cnt) {
	int i, j, k, a, b, c, sz;
	if (x <= 9) {
		if (x % 2 == 1) cnt++;
		mn = min(mn, cnt);
		mx = max(mx, cnt);
		return;
	} else if (x <= 99) {
		i = x / 10;
		j = x % 10;
		if (j % 2 == 1) cnt++;
		if (i % 2 == 1) cnt++;
		dfs(i+j, cnt);
	} else {
		vector<int> v;
		while (x) {
			if (x % 2 == 1) cnt++;
			v.push_back(x % 10);
			x /= 10;
		}
		reverse(v.begin(), v.end());
		sz = v.size();
		for (i=1;i<=sz-2;i++) {
			for (j=i+1;j<=sz-1;j++) {
				a = b = c = 0;
				for (k=0;k<i;k++)
					a = a * 10 + v[k];
				for (k=i;k<j;k++)
					b = b * 10 + v[k];
				for (k=j;k<sz;k++)
					c = c * 10 + v[k];
				dfs(a+b+c, cnt);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> i;
	dfs(i, 0);
	cout << mn << ' ' << mx << endl;
	return 0;
}
