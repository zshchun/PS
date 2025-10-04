#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, ans = 0;
	string s, t;
	cin >> n;
	cin >> s >> t;
	for (i=0;i<n;i++)
		if (s[i] != t[i])
			ans++;
	cout << ans << endl;
	return 0;
}
