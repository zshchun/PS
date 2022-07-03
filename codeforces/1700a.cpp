#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		ans = 0;
		for (i=1;i<m;i++)
			ans += i;
		for (i=1;i<=n;i++)
			ans += i*m;
		cout << ans << endl;
	}
	return 0;
}
