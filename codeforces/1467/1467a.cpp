#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, N, M, ans=0;
	cin >> T;
	while(T--) {
		cin >> N;
		if (N == 1)
			cout << "9";
		else
			cout << "98";
		char c = '9';
		for (i=2;i<N;i++) {
			cout << c;
			if (c == '9')
				c = '0';
			else
				c++;
		}
		cout << '\n';
	}
	return 0;
}
