/* Dan - 13525052 */
#include <stdio.h>

int main() {
	int d, m;
	scanf("%d %d", &d, &m);

	while (d >= 0 && m >= 0 && d != m) {
		int nd = m;
		while (nd >= 10) {
			nd = nd / 10;
		};
		nd = nd + (m % 10);

		int nm = d;
		while (nm >= 10) {
			nm = nm / 10;
		};
		nm = nm + (d % 10);

		d = d - nd;
		m = m - nm;
	}

	if (d == m || (d < 0 && m < 0)) {
		printf("Wattles\n");
	} else if (d >= 0) {
		printf("Deeper\n");
	} else {
		printf("Mebel\n");
	}

	return 0;
}
