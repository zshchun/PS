#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2, n12, ans;
	cin >> n1 >> n2 >> n12;
	n1++; n2++; n12++;
	ans = n1 * n2 / n12 - 1;
	cout << ans << endl;
	return 0;
}
