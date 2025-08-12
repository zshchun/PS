#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, ans = 0;
	string s;
	cin >> s;
	for (i=3;i<=s.size();i++) {
		if (s.substr(i-3, 4) == "DKSH")
			ans++;
	}
	cout << ans << endl;

	return 0;
}
