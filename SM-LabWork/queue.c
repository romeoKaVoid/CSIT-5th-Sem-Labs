#include <stdio.h>
int main() {
    float lambda, mu;
    float rho, L, Lq, W, Wq;
    printf("Enter Arrival Rate of Customer(lambda): ");
    scanf("%f", &lambda);
    printf("Enter Service Rate (mu): ");
    scanf("%f", &mu);
    if(lambda >= mu) {
        printf("System is unstable(lambda must be less than mu)\n");
        return 0;
    }
    rho = lambda/mu;
    L = rho/(1-rho);
    Lq = (rho*rho)/(1-rho);
    W = 1/(mu-lambda);
    Wq = rho/mu*(1-rho);
    printf("\n--- Queue Parameters ---\n");
    printf("Utilization (rho) = %.3f\n", rho);
    printf("Average number of customers in system (L) = %.3f\n", L);
    printf("Average number in queue (Lq) = %.3f\n", Lq);
    printf("Average time in system (W) = %.3f\n", W);
    printf("Average waiting time (Wq) = %.3f\n", Wq);
    printf("\n  -By Krishna Aryal");
    return 0;
}