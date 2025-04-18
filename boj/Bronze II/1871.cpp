#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, a, b;
	char c;
	cin >> n;
	while (n--) {
		int a = 0;
		for (i=0;i<3;i++) {
			a *= 26;
			cin >> c;
			a += c - 'A';
		}
		cin >> c >> b;
		if (abs(a - b) > 100)
			cout << "not nice\n";
		else
			cout << "nice\n";
	}
	return 0;
}
