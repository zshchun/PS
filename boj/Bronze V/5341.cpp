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
	ll v, i, ans;
	while (1) {
		ans = 0;
		cin >> v;
		if (v == 0) break;
		for (i=1;i<=v;i++)
			ans += i;
		cout << ans << endl;
	}
	return 0;
}
