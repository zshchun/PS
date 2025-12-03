#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, r, c;
	cin >> r >> c;
	string s;
	vector<string> v(c);
	for (i=0;i<r;i++) {
		cin >> s;
		for (j=0;j<c;j++)
			v[j] += s[j];
	}

	for (i=1;i<r;i++) {
		unordered_set<string> st;
		for (j=0;j<c;j++) {
			string t = v[j].substr(i);
			if (st.count(t) > 0) {
				cout << i-1 << endl;
				return 0;
			}
			st.insert(t);
		}
	}
	cout << r-1 << endl;

	return 0;
}
