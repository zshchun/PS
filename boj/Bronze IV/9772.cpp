#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double x, y;
	while (1) {
		cin >> x >> y;
		if (x > 0 && y > 0)
			cout << "Q1\n";
		else if (x < 0 && y > 0)
			cout << "Q2\n";
		else if (x > 0 && y < 0)
			cout << "Q4\n";
		else if (x < 0 && y < 0)
			cout << "Q3\n";
		else
			cout << "AXIS\n";
		if (x == 0 && y == 0)
			break;
	}
	return 0;
}
