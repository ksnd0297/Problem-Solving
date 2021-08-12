#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#pragma warning(disable: 4996)

int sectionSum[1001];

int main() {
	int C; scanf("%d", &C);
	while (C--) {
		int N, L; scanf("%d %d", &N, &L); // 6 3
		int num;
		int sum = 0;
		for (int i = 1; i <= N; i++) { // 1 2 3 1 2 3
			scanf("%d", &num); sum += num;
			sectionSum[i] = sum; // 구간 합 구하기 1 3 6 7 9 12
		}

		double cost = 123456789;
		for (int i = L; i <= N; i++) { // 3
			for (int j = 1; j <= N; j++) {
				if (j - i >= 0) {
					cost = min(cost, ((sectionSum[j] - sectionSum[j - i]) / (double)i));
				}
			}
		}
		printf("%.12lf\n", cost);
	}
	return 0;
}