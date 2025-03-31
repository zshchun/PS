#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, a, total=0;
	float b, c = 0.0;
	char x, y;
	string s;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> s >> a >> x;
		if (x == 'A')
			b = 4.0;
		else if (x == 'B')
			b = 3.0;
		else if (x == 'C')
			b = 2.0;
		else if (x == 'D')
			b = 1.0;
		else if (x == 'F')
			b = 0.0;
		y = '0';
		if (x != 'F')
			cin >> y;
		if (y == '+')
			b += 0.3;
		else if (y == '-')
			b -= 0.3;
		c += a * b;
		total += a;
	}
	cout.precision(2);
	cout << fixed << c / total << endl;
	return 0;
}
