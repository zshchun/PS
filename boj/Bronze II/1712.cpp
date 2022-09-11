#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, c, i = -1;
	cin>>a>>b>>c;
	if (c > b)
		for (i=a/(c-b);a+i*b >= i*c;i++)
			;
	cout << i << '\n';

	return 0;
}
