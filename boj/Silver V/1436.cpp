#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	ll n, i, j, ans;
	cin>>n;
	i = 0;
	while(n) {
		for (j=i;j;j/=10) {
			if (j % 1000 == 666) {
				n--;
				ans = i;
				break;
			}
		}
		i++;
	}
	cout << ans << "\n";
	return 0;
}
