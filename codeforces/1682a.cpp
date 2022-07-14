#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		string s;
		cin >> s;
		ans = 0;
		if (n%2) ans++;
		char c = s[((n-1)/2)];
		for (i=(n/2)-1;i>=0;i--) {
			if (c == s[i]) ans += 2;
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}
