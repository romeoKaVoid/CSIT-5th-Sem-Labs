#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
int main()
{
    int i, n;
    int inCircle = 0;
    double x, y, z, pi;
    printf("Enter number of random points: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (i = 0; i < n; i++){
        // Generate random numbers between 0 and 1
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1){
            inCircle++;
        }
    }
    pi = 4.0 * inCircle / n;
    printf("Estimated value of Pi = %lf\n", pi);
    printf("\n  -By Krishna Aryal");
    return 0;
}
