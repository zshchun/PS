#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k, i;
	cin>>t;
	while (t--) {
		cin>>n>>k;
		if (n>k && n%k==0)
			cout << "1\n";
		else if (n>k)
			cout << "2\n";
		else if (k%n==0)
			cout << k/n<<"\n";
		else
			cout << (k/n)+1<<'\n';
	}
	return 0;
}
