#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	string hj, fan = ":fan:";
	cin >> hj;
	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			if (i == 1 && j == 1)
				cout << ':' << hj << ':';
			else
				cout << fan;
		}
		cout << endl;
	}
	return 0;
}
