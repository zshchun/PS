#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
bool ab[26];
int tbl[26];
vector<char> ch;
vector<int> p;
vector<string> s;
ll n, ans;

ll Stol(string &s) {
	ll x = 0;
	for (int i=0;i<s.size();i++) {
		ll v = tbl[s[i]-'A'];
		x = x * 10 + v;
	}
	return x;
}

void solve() {
	ll sum = 0;
	for (int i=0;i<n;i++) {
		sum += Stol(s[i]);
	}
	ans = max(ans, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> n;
	s.resize(n);
	for (i=0;i<n;i++) {
		cin >> s[i];
		for (char c : s[i])
			ab[c-'A'] = 1;
	}
	for (i=0;i<26;i++)
		if (ab[i])
			ch.push_back('A'+i);
	
	for (i=0;i<10;i++)
		p.push_back(i);
	
	do {
		for (i=0;i<ch.size();i++)
			tbl[ch[i]-'A'] = p[i];
		solve();
	} while (next_permutation(p.begin(), p.end()));

	cout << ans << endl;

	return 0;
}
