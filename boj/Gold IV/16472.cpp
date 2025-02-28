#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	string s;
	cin >> n;
	cin >> s;
	unordered_map<char,int> m;
	for (i=0,j=0;i<(int)s.size();i++) {
		while ((int)m.size() <= n && j < (int)s.size()) {
			m[s[j]]++;
			j++;
			if ((int)m.size() <= n) ans = max(ans, j - i);
		}
		m[s[i]]--;
		if (m[s[i]] == 0)
			m.erase(s[i]);
	}

	cout << ans << endl;

	return 0;
}
