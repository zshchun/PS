#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	cin >> n;
	string s;
	for (i=0;i<n;i++) {
		cin >> s;
		string t = s;
		if (next_permutation(s.begin(), s.end()))
			cout << s << endl;
		else
			cout << t << endl;
	}
	return 0;
}
