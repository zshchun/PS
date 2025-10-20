#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string n;
	int i, b, ans = 0;
	cin >> n >> b;
	for (char &c : n) {
		ans *= b;
		if (c >= '0' && c <= '9')
			ans += c - '0';
		else
			ans += c - 'A' + 10;
	}
	cout << ans << endl;
	return 0;
}
