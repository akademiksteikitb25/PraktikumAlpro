/* Dan - 13525052 */
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; n > 1; i++) {
		if ((n & 1) == 0) {
			n = n >> 1;
		} else {
			n = 3 * n + 1;
		}
	}
	printf("%d\n", i);
	return 0;
}
