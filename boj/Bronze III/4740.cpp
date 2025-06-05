#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, line;
	while (1) {
		getline(cin, s);
		if (!s.empty() && s.back() == '\r')
			s.erase(s.size()-1);
		if (s == "***") break;
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}
