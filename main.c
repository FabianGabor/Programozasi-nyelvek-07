#include <stdio.h>

struct coord { int x, y; };
struct vector {
    struct coord start;
    struct coord end;
} typedef vector;

void disszor (char c, int n)
{
    for (int i=0; i<n; i++)
        printf("%c ", c);
    printf("\n");
}

int primecheck (int n)
{
    if (n<2) return 0;
    if (n==2) return 1;
    if (n % 2 == 0) return 0;
    for (int i=3; i*i<n; i+=2)
        if (n % i == 0) return 0;
    return 1;
}

void vector_scalar_mult (struct vector *v, int s)
{
    //v->end = { {(v->end.x - v->start.x) * s}, {(v->end.x - v->start.x) * s} };
    v->end.x = (v->end.x - v->start.x) * s;
    v->end.y = (v->end.y - v->start.y) * s;
}


int main()
{
    // 1. Hozz létre egy egész típusú változót, adj neki kezdőértéket! Egy típusos mutatóval duplázd meg az értékét!
    int a = 10;
    int *p;
    p = &a;
    printf("p = %d\n", *p);
    *p *= 2;
    printf("p = %d\n", *p);

    // 2. Készíts függvényt dísszor néven, ami csillagokat ír ki egymás mellé, a paraméterében kapott számban! Készíts még egy díszsor függvényt, ami ugyanezt tetszőleges karakterrel tudja!
    disszor('*', 5);

    // 3. Készíts függvényt, ami visszaadja, hogy a paraméteréül kapott szám prímszám-e!
    int check_if_prime;
    printf("Enter number to check if prime: ");
    scanf("%d", &check_if_prime);
    printf("%s\n", ((primecheck(check_if_prime)==1)?"PRIME":"NOT PRIME") );

    // 4. Készíts függvényt, ami megduplázza egy paraméteréül kapott vektor hosszát azzal, hogy megváltoztatja az x1, y1 koordinátáit! (x0,y0, x1, y1)!
    vector v = {{2,0},{6,5}};

    printf("Coords : (%d,%d)(%d,%d) \n", v.start.x, v.start.y, v.end.x, v.end.y);
    printf("Vector : (%d,%d) \n", v.end.x - v.start.x, v.end.y - v.start.y);
    vector_scalar_mult(&v,2);
    printf("Vector : (%d,%d) \n", v.end.x - v.start.x, v.end.y - v.start.y);


    // 5. Hozz létre egy 5 elemű, egész számokat tartalmazó tömböt, majd mutató segítségével változtasd meg egy tetszőleges elemét! Az elem sorszámát és új értékét a felhasználó adja meg!
    int arr[5] = {2,3,5,7,11};
    int index, val;
    printf("Hanyadik elemet valtoztatod? : ");
    scanf("%d", &index);
    printf("Milyen ertekre? : ");
    scanf("%d", &val);
    int *arr_pointer = arr;

    arr_pointer[index-1] = val;
    *(arr_pointer+index-1) = val;

    for (int i=0; i<5; i++)
        printf("%d ", *(arr_pointer+i));
    printf("\n");

    return 0;
}
