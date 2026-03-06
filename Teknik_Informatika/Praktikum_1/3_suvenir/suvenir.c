/* Dan - 13525052 */
#include <stdio.h>

int main() {
	int rows;
	scanf("%d", &rows);

	int row;
	int accu = 1;
	for (row = 1; row <= rows; row++) {
		int col;
		for (col = 1; col <= row; col++) {
			if (col == 1) {
				printf("%d", accu);
			} else {
				printf(" %d", accu);
			}
			accu++;
		}
		printf("\n");
	}

	return 0;
}
