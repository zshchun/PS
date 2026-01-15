#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	if (t == s)
		cout << "true\n";
	else
		cout << "false\n";

	return 0;
}
