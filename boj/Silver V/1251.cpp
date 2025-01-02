#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	int i, j, k;
	cin.tie(0);
	string ans = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	string s, t;
	cin >> s;
	for (i=0;i<(int)s.size()-2;i++) {
		for (j=i+1;j<(int)s.size()-1;j++) {
			string a = s.substr(0, i+1);
			string b = s.substr(i+1, j-i);
			string c = s.substr(j+1);
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			t = a + b + c;
			if (t < ans)
				ans = t;
		}
	}
	cout << ans;
	return 0;
}
