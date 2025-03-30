#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int b, p;
	cin >> b;
	p = 5 * b - 400 ;

	cout << p << endl;
	if (p < 100)
		cout << "1\n";
	else if (p > 100)
		cout << "-1\n";
	else
		cout << "0\n";
	return 0;
}
