/* Dan - 13525052 */
#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);

	int copy = input;
	int sum = 0;
	while (copy > 0) {
		sum += copy % 10;
		copy /= 10;
	}

	if (input % sum == 0) {
		printf("1\n");
	} else {
		printf("0\n");
	}
	return 0;
}
