#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N;
	cin >> N;
	if (N % 7 == 0 || N % 7 == 2)
		cout << "CY\n";
	else
		cout << "SK\n";

	return 0;
}
