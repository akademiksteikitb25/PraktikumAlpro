#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    int dh, dm, ds;

    scanf("%d %d %d", &h1, &m1, &s1);
    scanf("%d %d %d", &h2, &m2, &s2);

    dh = h2 - h1;
    dm = m2 - m1;
    ds = s2 - s1;

    printf("%d %d %d\n", dh, dm, ds);

    return 0;
}