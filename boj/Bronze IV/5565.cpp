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
	int total, a, i;
	cin >> total;
	for (i=0;i<9;i++) {
		cin >> a;
		total -= a;
	}
	cout << total << endl;
	
	return 0;
}
