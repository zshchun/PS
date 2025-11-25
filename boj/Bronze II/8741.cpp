#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
bitset<1000001> a;
vector<int> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j = 1, k, carry = 0, ans = 0;
	cin >> k;
	for (i=0;i<k;i++)
		cout << "1";
	for (i=0;i<k-1;i++)
		cout << "0";
	cout << endl;
	return 0;
}
