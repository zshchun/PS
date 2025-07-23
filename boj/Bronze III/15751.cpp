#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if (a > b) swap(a, b);
	if (x > y) swap(x, y);
	cout << min(abs(a-b), abs(a-x)+abs(b-y)) << endl;
	return 0;
}
