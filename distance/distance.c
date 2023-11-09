#include <stdio.h>
#include <math.h>

typedef struct point point_t;
struct point {
    double x;
    double y;
    double z;
};

void create_point(point_t*);
double xyz_distance(point_t, point_t);

int main(int argc, char const *argv[])
{
    point_t a;
    point_t b;

    printf("Calculate 3D distance\n");
    printf("Input first coordinate:\n");
    create_point(&a);
    printf("First coordinate: %.1lf, %.1lf, %.1lf\n", a.x, a.y, a.z);
    printf("\n");

    printf("Input second coordinate:\n");
    create_point(&b);
    printf("Second coordinate: %.1lf, %.1lf, %.1lf\n", b.x, b.y, b.z);
    printf("\n");
    
    double dis, sqrt_dis;

    dis = xyz_distance(a, b);
    sqrt_dis = sqrt(dis);

    printf("\n");
    printf("\u221A Distance is %.1lf:\n", dis);
    printf("Distance is %.1lf:\n", sqrt_dis);

    return 0;
}

void create_point(point_t* point)
{
    printf("x1:");
    scanf("%lf", &(point->x));
    printf("y1:");
    scanf("%lf", &(point->y));
    printf("z1:");
    scanf("%lf", &(point->z));
    printf("\n");

    return;
}

double xyz_distance(point_t a, point_t b)
{
    double xPow = pow(((b.x) - (a.x)), 2);
    printf("X Diff Power: %.1lf\n", xPow);

    double yPow = pow(((b.y) - (a.y)), 2);
    printf("Y Diff Power: %.1lf\n", yPow);

    double zPow = pow(((b.z) - (a.z)), 2);
    printf("Z Diff Power: %.1lf\n", zPow);

    double d = xPow + yPow + zPow;

    return d;
}
