#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		string s;
		cin >> s;
		ans = n;
		for (i=1;i<n;i++) {
			if (s[i-1] != s[i]) ans += i;
		}
		cout << ans << endl;
	}
	return 0;
}
