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
		char last = 'z';
		for (i=0;i<s.size();i++) {
			if (last != s[i]) {
				if (i%2) ans++;
				last = s[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
