#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 0)
		cout << c * c - b << endl;
	else if (b == 0)
		cout << c * c - a << endl;
	else if (c == 0)
		cout << sqrt(a + b) << endl;
	return 0;
}
