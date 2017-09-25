#include <iostream>
using namespace std;

int main() {
	int n=0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;
	if(n <= 0) {
		cout << "양수를 입력하세요!" << endl;
		return 0;
	}
	int k, sum=0;
	for(k=1; k<=n; k++) {
		sum += k;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum << "입니다." << endl;
	return 0;
}