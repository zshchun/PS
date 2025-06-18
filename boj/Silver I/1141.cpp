#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, len, ans = 1;
	cin >> n;
	vector<string> s(n);
	for (i=0;i<n;i++)
		cin >> s[i];
	sort(s.begin(), s.end());
	for (i=0;i<n-1;i++) {
		len = min(s[i].size(), s[i+1].size());
		string a = s[i].substr(0, len);
		string b = s[i+1].substr(0, len);
		if (a != b)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
