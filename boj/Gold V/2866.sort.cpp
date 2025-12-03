#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, r, c, ans;
	cin >> r >> c;
	string s;
	vector<string> v(c);
	for (i=0;i<r;i++) {
		cin >> s;
		for (j=0;j<c;j++)
			v[j] += s[j];
	}

	for (i=0;i<c;i++)
		reverse(v[i].begin(), v[i].end());
	sort(v.begin(), v.end());
	ans = r - 1;

	for (i=1;i<c;i++) {
		for (j=0;j<r;j++) {
			if (v[i-1][j] != v[i][j]) {
				ans = min(ans, r-1-j);
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
