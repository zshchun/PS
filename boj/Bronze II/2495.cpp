#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans, cnt;
	string s;
	while (cin >> s) {
		ans = 1;
		for (i=0;i<s.size();i++) {
			cnt = 1;
			for (j=i+1;j<s.size();j++) {
				if (s[i] != s[j])
					break;
				cnt++;
				ans = max(ans, cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
