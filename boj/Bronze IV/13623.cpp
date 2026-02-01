#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a != b && b == c)
		cout << "A\n";
	else if (b != a && a == c)
		cout << "B\n";
	else if (c != a && a == b)
		cout << "C\n";
	else
		cout << "*\n";

	return 0;
}
