#include <iostream>

using namespace std;

long long int gcd(int A, int B) {
	if (B == 0) return A;
	return gcd(B, A % B);
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long int sum = 0;
		int arr[101]; 
		int K; cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < K; i++) {
			for (int j = i + 1; j < K; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << (long long int)sum << '\n';
	}
	return 0;
}