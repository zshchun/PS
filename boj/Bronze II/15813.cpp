#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for (char c : s) {
		ans += c - 'A' + 1;
	}
	cout << ans << endl;
	return 0;
}
