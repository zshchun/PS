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
	string s;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> s;
		if (s.size() >= 6 && s.size() <= 9)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
