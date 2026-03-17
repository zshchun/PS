#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, D, v, f, c, i, ans;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N >> D;
		for (i=0;i<N;i++) {
			cin >> v >> f >> c;
			double h = (double)f / c;
			if (h * v >= D)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
