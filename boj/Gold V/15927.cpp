#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	string s, t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());

	if (t == s) {
		for (i=1;i<s.size();i++)
			if (s[i] != s[0])
				break;
		if (i == s.size())
			cout << "-1\n";
		else
			cout << s.size() - 1 << endl;
	} else {
		cout << s.size() << endl;
	}

	return 0;
}
