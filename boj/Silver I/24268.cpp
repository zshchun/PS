#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
ll d, ans = -1;

string one_number(ll n) {
	string ret;
	while (n) {
		ret = (char)('0' + (n % d)) + ret;
		n /= d;
	}
	return ret;
}

ll get_year(string &a) {
	ll ret = 0;
	ll e = 1;
	for (int i=a.size()-1;i>=0;i--) {
		ret += e * (a[i] - (int)'0');
		e *= d;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	string t = "1023456789";
	cin >> n >> d;

	t.resize(d);
	string s = one_number(n);

	do {
		ll year = get_year(t);
		if (year > n) {
			ans = year;
			break;
		}
	} while (next_permutation(t.begin(), t.end()));
	cout << ans << endl;
	return 0;
}
