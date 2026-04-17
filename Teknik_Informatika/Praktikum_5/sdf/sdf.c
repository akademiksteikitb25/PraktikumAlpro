#include "sdf.h"
#include <math.h>
#include <stdbool.h>

/* ***************************************************************** */
/* DEFINISI KONSTRUKTOR                                              */
/* ***************************************************************** */
Point MakePoint(float x, float y)
/*  I.S. x dan y terdefinisi
    F.S. Menghasilkan Point dengan koordinat (x, y) */
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

Vector MakeVector(float dx, float dy)
/*  I.S. dx dan dy terdefinisi
    F.S. Menghasilkan Vector dengan komponen (dx, dy) */
{
    Vector v;
    v.dx = dx;
    v.dy = dy;
    return v;
}

/* ***************************************************************** */
/* OPERASI MATEMATIKA & VEKTOR                                       */
/* ***************************************************************** */
float Jarak(Point p1, Point p2)
/*  I.S. p1 dan p2 terdefinisi
    F.S. Menghasilkan jarak Euclidean antara p1 dan p2
    Rumus jarak Euclidean: sqrt((x2-x1)^2 + (y2-y1)^2) */
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

void Normalize(Vector *v)
/*  I.S. v terdefinisi dan memiliki panjang tidak nol
    F.S. v menjadi vektor satuan (panjang = 1.0) jika panjang awalnya tidak nol
    Rumus normalize: v = v / ||v||
    ||v|| = sqrt(dx^2 + dy^2) */
{
    float l = sqrt(v->dx * v->dx + v->dy * v->dy);
    v->dx /= l;
    v->dy /= l;
}

/* ***************************************************************** */
/* OPERASI DASAR                                                     */
/* ***************************************************************** */
float SDF_Circle(Point p, Point center, float radius)
/*  I.S. p, center, dan radius terdefinisi
    F.S. Menghasilkan nilai signed distance dari titik p ke lingkaran
         berpusat di center dengan jari-jari radius.
         Nilai negatif berarti titik berada di dalam lingkaran,
         nol berarti tepat di tepi, dan positif berarti di luar lingkaran.
    SDF dihitung sebagai jarak dari titik p ke pusat lingkaran dikurangi
   jari-jari. */
{
    float d = Jarak(p, center);
    return d - radius;
}

Point Move(Point p, Vector v, float step)
/*  I.S. p, v, dan step terdefinisi
    F.S. Menghasilkan titik baru hasil perpindahan titik p sejauh step
         ke arah vektor v */
{
    Normalize(&v);
    p.x += v.dx * step;
    p.y += v.dy * step;
    return p;
}
