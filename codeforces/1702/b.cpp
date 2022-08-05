#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		ans = 0;
		set<char> a;
		for (i=0;i<s.size();i++) {
			a.insert(s[i]);
			if (a.size() > 3) {
				a.clear();
				a.insert(s[i]);
				ans++;
			}
		}
		if (a.size() > 0) ans++;
		cout << ans << endl;
	}
	return 0;
}
