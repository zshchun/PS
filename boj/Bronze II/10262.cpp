#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[2], b[2];
	int g, e;
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	g = a[0] + a[1] + b[0] + b[1];
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	e = a[0] + a[1] + b[0] + b[1];
	if (e > g)
		cout << "Emma\n";
	else if (g > e)
		cout << "Gunnar\n";
	else
		cout << "Tie\n";
	return 0;
}
