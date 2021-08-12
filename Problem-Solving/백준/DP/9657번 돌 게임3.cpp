#include <iostream>
#include <string.h>

using namespace std;

int arr[1010];

int main(void)
{
	memset(arr, -1, sizeof(arr));
	arr[1] = 1;
	for (int i = 1; i <= 1000; i++) {
		if (arr[i] == 1) {
			arr[i] = 1;
			if(arr[i+2] == -1 && arr[i+2] != 0)arr[i + 2] = 1;
			if(arr[i+3] == -1 && arr[i+3] != 0)arr[i + 3] = 1;
		}
		else if(arr[i] == -1 || arr[i] == 0){
			arr[i] = 0;
			if(arr[i+2] == -1 && arr[i+2] != 1)arr[i + 2] = 0;
			if(arr[i+3] == -1 && arr[i+3] != 1)arr[i + 3] = 0;
		}
	}
	int N; cin >> N;
	if (arr[N] == 1) cout << "SK";
	else cout << "CY";
	return 0;
}