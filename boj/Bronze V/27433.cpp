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
	ll y, i, ans = 1;
	cin >> y;
	for (i=1;i<=y;i++)
		ans *= i;
	cout << ans << endl;

	return 0;

}
