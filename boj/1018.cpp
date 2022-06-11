#include <bits/stdc++.h>
using namespace std;
int dp[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y, v, c, ans = 1<<30, t, i;
	char ch;
	cin>>n>>m;
	for (y=0;y<n;y++) {
		c = 0;
		for (x=0;x<m;x++) {
			cin>>ch;
			if (ch == 'B')
				v = 0;
			else if (ch == 'W')
				v = 1;
			if (((y+x) & 1) == v)
				c++;
			dp[y+1][x+1] = c;
			if (y>=7 && x>= 7) {
				t = 0;
				for(i=0;i<8;i++) {
					t += dp[y+1-i][x+1] - dp[y-i+1][x+1-8];
				}
				t = min(64-t, t);
				ans = min(ans, t);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
