#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;
vector<ll> c;

bool rbs(string &s) {
	ll val = 0;
	for (char &x: s) {
		if (x == '(')
			val++;
		else if (x == ')')
			val--;
		if (val < 0)
			return false;
	}
	if (val != 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		ans = 0;
		string s;
		cin >> s;
		vector<ll> a;
		ll o = s.size()/2, c = o;
		for (i=0;i<s.size();i++) {
			if (s[i] == '(') {
				o--;
			} else if (s[i] == ')') {
				c--;
			} else {
				a.push_back(i);
			}
		}
		for (i=0;i<a.size();i++) {
			if (i < o)
				s[a[i]] = '(';
			else
				s[a[i]] = ')';
		}
		if (o > 0 && c > 0) {
			swap(s[a[o-1]], s[a[o]]);
			if (rbs(s)) {
				cout << "NO\n";
				continue;
			}
		}
		cout << "YES\n";
	}
	return 0;
}
