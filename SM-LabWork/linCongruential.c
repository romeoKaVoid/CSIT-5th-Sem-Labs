#include <stdio.h>
int main() {
    int a, c, m;
    int n, X0, Xn;

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of c: ");
    scanf("%d", &c);
    printf("Enter the value of m (modulus): ");
    scanf("%d", &m);
    printf("Enter the seed value (X0): ");
    scanf("%d", &X0);
    printf("Enter how many random numbers to generate: ");
    scanf("%d", &n);
    Xn = X0;
    printf("\nGenerated Random Numbers:\n");
    for(int i = 0; i < n; i++) {
        Xn = (a * Xn + c) % m;
        printf("X%d = %d\n", i+1, Xn);
    }
    printf("\n  -By Krishna Aryal");
    return 0;
}