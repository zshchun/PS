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
	int a, b;
	while (cin >> a >> b) {
		if (!a && !b) break;
		if (a < b && b % a == 0)
			cout << "factor\n";
		else if (a > b && a % b == 0)
			cout << "multiple\n";
		else
			cout << "neither\n";
	}
	return 0;
}
