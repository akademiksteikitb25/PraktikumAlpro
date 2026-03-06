/* Dan - 13525052 */
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int width = n - 1;

	int p;
	int layer;
	int sublayer;

	/* layer dan sublayer daun */
	for (layer = 0; layer < width; layer++) {
		for (sublayer = layer; sublayer <= width; sublayer++) {
			/* spasi di kiri pohon */
			for (p = 0; p < width - sublayer; p++) {
				printf(" ");
			} 

			/* bagian kiri pohon */
			for (p = 0; p < sublayer; p++) {
				printf("*");
			} 
			/* bagian tengah pohon */
			printf("*");
			/* bagian kanan pohon */
			for (p = 0; p < sublayer; p++) {
				printf("*");
			} 
			printf("\n");
		}
	}

	/* batang bagian bawah */
	for (sublayer = 0; sublayer < n; sublayer++) {
		for (p = 0; p < width - 1; p++) {
			printf(" ");
		}
		printf("***\n");
	}

	return 0;
}
