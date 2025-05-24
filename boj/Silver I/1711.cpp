#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n, ans = 0;
	ll x1, x2, x3, y1, y2, y3, a, b, c;
	cin >> n;
	vector<pa> xy(n);
	for (i=0;i<n;i++)
		cin >> xy[i].first >> xy[i].second;

	for (i=0;i<n;i++) {
		for (j=i+1;j<n;j++) {
			for (k=j+1;k<n;k++) {
				tie(x1, y1) = xy[i];
				tie(x2, y2) = xy[j];
				tie(x3, y3) = xy[k];

				a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
				b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
				c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

				if ((a + b == c) || (c + b == a) || (a + c == b))
					ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
