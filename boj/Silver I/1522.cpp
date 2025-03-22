#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int get_count(string &s, int b, int e, char c) {
	int cnt = 0;
	for (int i=b;i<e;i++) {
		if (s[i] == c)
			cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, alen, ans = INF;
	string s;
	cin >> s;
	alen = get_count(s, 0, s.size(), 'a');
	s += s.substr(0, alen);
	for (i=0;i<s.size()-alen;i++) {
		ans = min(ans, get_count(s, i, i+alen, 'b'));
	}
	cout << ans << endl;
	return 0;
}
