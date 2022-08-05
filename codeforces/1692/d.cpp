#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n;

bool isPalindrome(ll min) {
	ll h = min / 60;
	ll m = min % 60;
	ll d1 = h / 10;
	ll d2 = h % 10;
	ll d3 = m / 10;
	ll d4 = m % 10;
	if (d1 == d4 && d2 == d3) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		ans = 0;
		ll h=0, m=0, now;
		string s;
		cin >>s >> j;
		h += (s[0]-'0') * 10;
		h += s[1]-'0';
		m += (s[3]-'0') * 10;
		m += s[4]-'0';

		unordered_set<ll> ss;
		now = h * 60 + m;
		while(1) {
			if (ss.find(now) != ss.end())
				break;
			ss.insert(now);
			ans += isPalindrome(now);
			now = (now + j) % 1440;
		}
		cout << ans << endl;
	}
	return 0;
}
