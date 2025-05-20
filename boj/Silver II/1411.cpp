#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, N, ans = 0;
	vector<string> t;
	string s;
	cin >> N;
	for (i=0;i<N;i++) {
		j = 0;
		char tbl[26] = {0, };
		string q;
		cin >> s;
		for (char &c : s) {
			if (!tbl[c-'a']) {
				tbl[c-'a'] = j + 'a';
				j++;
			}
			q += tbl[c-'a'];
		}
		t.push_back(q);
	}
	for (i=0;i<N;i++) {
		for (j=i+1;j<N;j++) {
			if (t[i] == t[j])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
