/* Dan - 13525052 */
#include <stdio.h>

int first(int x) {
	while (x >= 10) {
		x /= 10;
	}
	return x;
}

int last(int x) {
	return x % 10;
}

int main() {
	int d, m;
	scanf("%d %d", &d, &m);

	while (d >= 0 && m >= 0 && d != m) {
		int nd = d - (first(m) + last(m));
		int nm = m - (first(d) + last(d));
		d = nd;
		m = nm;
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
