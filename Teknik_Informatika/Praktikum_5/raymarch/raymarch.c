#include "sdf.h"
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

// #define DEBUG_PRINT

#ifdef DEBUG_PRINT

void print_arr_int(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
#define PRINT_ARR_INT(x, l) print_arr_int(x, l)

#else

void print_arr_int(int *arr, int len) {}
#define PRINT_ARR_INT(x, l)

#endif

typedef long long ll;
typedef unsigned long long ull;

typedef struct {
    Point point;
    float radius;
} Anomaly;

int main() {
    int k;
    scanf("%d", &k);

    Anomaly *malies = (Anomaly *)malloc(sizeof(Anomaly) * k);

    for (int i = 0; i < k; i++) {
        float cx, cy, r;
        scanf("%f %f %f", &cx, &cy, &r);

        Anomaly a;
        a.point = MakePoint(cx, cy);
        a.radius = r;

        malies[i] = a;
    }

    int n;
    scanf("%d", &n);

    for (int route_i = 0; route_i < n; route_i++) {
        float px, py, vx, vy, max_dist;
        scanf("%f %f %f %f %f", &px, &py, &vx, &vy, &max_dist);

        Point pos = MakePoint(px, py);
        Vector dir = MakeVector(vx, vy);
        Normalize(&dir);

        float stepped = 0;
        int steps = 0;

        float all_min_dist = FLT_MAX;
		int hit = 0;

        while (stepped < max_dist) {
			steps++;
			// printf("Pos: %f %f\n", pos.x, pos.y);
            float min_dist = FLT_MAX;
            for (int j = 0; j < k; j++) {
                float d = SDF_Circle(pos, malies[j].point, malies[j].radius);
				// printf("%d: %f\n", j, d);
                if (d < 0.01) {
					// printf("%f %f\n", malies[j].point.x, malies[j].point.y);
                    printf(
                        "Rute %d: HIT ANOMALY. Titik tembak: (%.2f, %.2f), "
                        "Jumlah langkah: %d\n",
                        route_i + 1, px, py, steps);
					hit = 1;
                    break;
                }
                if (d < min_dist) {
                    min_dist = d;
                }
            }

			if (hit) {
				break;
			}

            if (min_dist < all_min_dist) {
                all_min_dist = min_dist;
            }
			if (max_dist - stepped < min_dist) {
				min_dist = max_dist - stepped;
			}
            pos = Move(pos, dir, min_dist);
            stepped += min_dist;
        }

		if (hit) {
			continue;
		}

        printf("Rute %d: MISS. Jarak terdekat ke anomali: %.2f\n", route_i + 1,
               all_min_dist);
    }
    return 0;
}
