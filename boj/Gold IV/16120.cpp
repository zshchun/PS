#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<char> s;
	int e;
	char c;
	while (cin >> c) {
		s.push_back(c);
		e = s.size();
		if (e >= 3 && s[e-4] == 'P' && s[e-3] == 'P' && s[e-2] == 'A' && s[e-1] == 'P') {
			s.pop_back(); s.pop_back(); s.pop_back();
		}
	}
	if (s.size() == 1 && s.back() == 'P')
		cout << "PPAP\n";
	else
		cout << "NP\n";
	return 0;
}
