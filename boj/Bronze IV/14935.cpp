#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, prev = INF;
	cin >> x;
	for (i=0;i<100;i++) {
		string s = to_string(x);
		j = (s[0]-'0') * s.size();
		if (i && j == prev) {
			cout << "FA\n";
			return 0;
		}
		prev = j;
	}
	cout << "NFA\n";
	return 0;
}
