#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >>a>>b;
	if (a+b >= 15 && b >= 8)
		cout << "1\n";
	else if (a+b >= 10 && b >= 3)
		cout << "2\n";
	else if (a+b >= 3)
		cout << "3\n";
	else
		cout << "4\n";
	return 0;
}
