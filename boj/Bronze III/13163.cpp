#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	string s;
	cin.ignore();
	for (i=0;i<n;i++) {
		string t, ans;
		getline(cin, s);
//		cout << s << endl;
		for (j=s.size()-1;j>=0;j--) {
			if (s[j] == ' ') {
				ans += t;
				t = "";
			} else {
				t += s[j];
			}
		}
		reverse(ans.begin(), ans.end());
		cout << "god" << ans << endl;
	}
	return 0;
}
