#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int top = 31 - __builtin_clz(n);
	if ((1<<top) != n) top++;
	int bot = __builtin_ffs(n) - 1;
	cout << (1 << top) << ' ' << top - bot << endl;

	return 0;
}
