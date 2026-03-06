#include <stdio.h>

/* Program lamawaktu */
/* Menghitung perbedaan antara masukan waktu awal dan waktu akhir */

/* KAMUS */
int h1, h2, h2, m1, m2, m3, s1, s2, s3;


int main()
{
    scanf("%d%d%d", &h1, &m1, &s1);
    scanf("%d%d%d", &h2, &m2, &s2);

    s3 = s2-s1;
    if (s3 < 0)
    {
        s3 += 60;
        m2 -= 1;
    }
    
    m3 = m2-m1;
    if (m3 < 0)
    {
        m3 += 60;
        h2 -= 1;
    }
    
    h3 = h2-h1;

    printf("%d %d %d\n", h3, m3, s3);
    return 0;
}