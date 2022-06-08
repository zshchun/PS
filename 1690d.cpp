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
	ll T, i, j, x, v, k, ans;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		vector<pl> a;
		string s;
		cin >> s;
		ans = 2e6;
		ll l = 0, r = 0, w=0;
		w = s[0] == 'W' ? 1 : 0;
		while (l < s.size()) {
			while (r-l+1 <k && r < s.size()-1) {
				r++;
				if (s[r] == 'W') w++;
			}
			if (r-l+1 >= k && w < ans) ans = w;
			if (s[l] == 'W') w--;
			l++;
		}
		cout << ans << endl;
	}
	return 0;
}
