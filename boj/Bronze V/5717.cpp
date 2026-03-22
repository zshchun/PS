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
		if (!a && !b)
			break;
		cout << a + b << endl;
	}
	return 0;
}
