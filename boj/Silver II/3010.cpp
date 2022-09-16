#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll cx[4] = { 0, 0, 1, -1 };
ll cy[4] = { 1, -1, 0, 0 };
ll dx[4] = { 0, 0, 2, -2 };
ll dy[4] = { 2, -2, 0, 0 };

int main() {
	ll i, j, k, ans=0;
	string s[7];
	for (i=0;i<7;i++)
		getline(cin, s[i]);
	for (i=0;i<7;i++) {
		for (j=0;j<7;j++) {
			for (k=0;k<4;k++) {
				ll ny = i + cy[k];
				ll nx = j + cx[k];
				ll y = i + dy[k];
				ll x = j + dx[k];
				if (y < 0 || y >= 7 || x < 0 || x >= 7)
					continue;
				if (s[i][j] == 'o' && s[ny][nx] == 'o' && s[y][x] == '.')
					ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
