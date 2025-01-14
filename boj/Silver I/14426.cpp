#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n, m, ans = 0;
	cin >> n >> m;
	unordered_set<string> a;
	string s;

	for (i=0;i<n;i++) {
		cin >> s;
		for (j=1;j<=(int)s.size();j++) {
			a.insert(s.substr(0, j));
		}
	}

	for (i=0;i<m;i++) {
		cin >> s;
		if (a.find(s) != a.end()) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
