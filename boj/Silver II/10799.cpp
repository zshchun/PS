#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int i = 0, ans = 0, j = 0;
	vector<int> a;

	for (i=0;i<s.size();i++) {
		char c = s[i];
		if (c == '(') {
			a.push_back(0);
		} else if (c == ')') {
			a.pop_back();
			if (s[i-1] == '(')
				ans += a.size();
			else
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
