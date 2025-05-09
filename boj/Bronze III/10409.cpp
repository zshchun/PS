#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, x, ans = 0;
	cin >> n >> T;
	for (i=0;i<n;i++) {
		cin >> x;
		if (x <= T) {
			ans++;
			T -= x;
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
