#ifndef SDF_H
#define SDF_H

#include <stdbool.h>

/* ***************************************************************** */
/* DEFINISI TYPE DASAR                                               */
/* ***************************************************************** */
/* ADT untuk merepresentasikan titik 2 dimensi pada bidang Cartesian. */
typedef struct {
    float x; /* koordinat horizontal titik*/
    float y; /* koordinat vertikal titik */
} Point;

/* ADT untuk merepresentasikan vektor 2 dimensi. */
typedef struct {
    float dx; /* komponen arah sumbu X */
    float dy; /* komponen arah sumbu Y */
} Vector;

/* ***************************************************************** */
/* NOTASI AKSES                                                      */
/* ***************************************************************** */
#define X(P) (P).x
#define Y(P) (P).y

#define DX(V) (V).dx
#define DY(V) (V).dy

/* ***************************************************************** */
/* DEFINISI KONSTRUKTOR                                              */
/* ***************************************************************** */
Point MakePoint(float x, float y);
/*  I.S. x dan y terdefinisi
    F.S. Menghasilkan Point dengan koordinat (x, y) */

Vector MakeVector(float dx, float dy);
/*  I.S. dx dan dy terdefinisi
    F.S. Menghasilkan Vector dengan komponen (dx, dy) */

/* ***************************************************************** */
/* OPERASI MATEMATIKA & VEKTOR                                       */
/* ***************************************************************** */
float Jarak(Point p1, Point p2);
/*  I.S. p1 dan p2 terdefinisi
    F.S. Menghasilkan jarak Euclidean antara p1 dan p2
    Rumus jarak Euclidean: sqrt((x2-x1)^2 + (y2-y1)^2) */

void Normalize(Vector *v);
/*  I.S. v terdefinisi dan memiliki panjang tidak nol
    F.S. v menjadi vektor satuan (panjang = 1.0) jika panjang awalnya tidak nol
    Rumus normalize: v = v / ||v||
    ||v|| = sqrt(dx^2 + dy^2) */

/* ***************************************************************** */
/* OPERASI DASAR                                                     */
/* ***************************************************************** */
float SDF_Circle(Point p, Point center, float radius);
/*  I.S. p, center, dan radius terdefinisi
    F.S. Menghasilkan nilai signed distance dari titik p ke lingkaran
         berpusat di center dengan jari-jari radius.
         Nilai negatif berarti titik berada di dalam lingkaran,
         nol berarti tepat di tepi, dan positif berarti di luar lingkaran.
    SDF dihitung sebagai jarak dari titik p ke pusat lingkaran dikurangi
   jari-jari. */

Point Move(Point p, Vector v, float step);
/*  I.S. p, v, dan step terdefinisi
    F.S. Menghasilkan titik baru hasil perpindahan titik p sejauh step
         ke arah vektor v */

#endif
