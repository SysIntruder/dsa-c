#include <stdio.h>
#include <math.h>

typedef struct coord coord_t;
struct coord
{
    double x;
    double y;
    double z;
};

void init_coord(coord_t*);
double distance(coord_t, coord_t);

int main(int argc, char const* argv[])
{
    coord_t a;
    coord_t b;

    printf("Calculate 3D distance\n");
    printf("Input first coordinate:\n");
    init_coord(&a);
    printf("First coordinate: %.1lf, %.1lf, %.1lf\n", a.x, a.y, a.z);
    printf("\n");

    printf("Input second coordinate:\n");
    init_coord(&b);
    printf("Second coordinate: %.1lf, %.1lf, %.1lf\n", b.x, b.y, b.z);
    printf("\n");

    double d = distance(a, b);

    printf("\n\u221A Distance is %.1lf:\n", d);
    printf("Distance is %.1lf:\n", sqrt(d));

    return 0;
}

void init_coord(coord_t* coord)
{
    printf("x:");
    scanf("%lf", &(coord->x));
    printf("y:");
    scanf("%lf", &(coord->y));
    printf("z:");
    scanf("%lf", &(coord->z));
    printf("\n");

    return;
}

double distance(coord_t a, coord_t b)
{
    double x = pow(((b.x) - (a.x)), 2);
    printf("X Diff Power: %.1lf\n", x);

    double y = pow(((b.y) - (a.y)), 2);
    printf("Y Diff Power: %.1lf\n", y);

    double z = pow(((b.z) - (a.z)), 2);
    printf("Z Diff Power: %.1lf\n", z);

    double d = x + y + z;

    return d;
}
