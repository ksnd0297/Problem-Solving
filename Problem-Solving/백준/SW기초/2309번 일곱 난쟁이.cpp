#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];

int main(void)
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i]; sum += arr[i];
	}

	bool flag = false;
	for (int i = 0; !flag && i < 9; i++) {
		for (int j = i + 1; !flag && j < 9; j++) {
			if ((sum - arr[i] - arr[j]) == 100) {
				arr[i] = 101; arr[j] = 101; flag = true;
			}
		}
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 7; i++) cout << arr[i] << '\n';
	return 0;
}