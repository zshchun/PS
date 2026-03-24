#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans;
	string s;
	while (getline(cin, s)) {
		if (s == "#") break;
		ans = 0;
		for (int i=1;i<=s.size();i++) {
			if (s[i-1] == ' ') continue;
			ans += i * (s[i-1] - 'A' + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
