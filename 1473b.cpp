#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

string strx(string &s, ll n) {
	string r;
	while(n--) {
		r += s;
	}
	return r;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, x, v, ans;
	cin >> T;
	while(T--) {
		string a, b;
		cin >> a >> b;
		n = a.size();
		m = b.size();
		ll g = __gcd(n, m);
		string t1 = strx(a, m/g);
		string t2 = strx(b, n/g);
		cout << (t1 == t2 ? t1 : "-1") << endl;
	}
	return 0;
}
