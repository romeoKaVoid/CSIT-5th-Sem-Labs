#include<stdio.h>
long long power(long long base, long long exp, long long mod){
    long long result = 1;
    for(int i = 0; i < exp; i++){
        result = (result * base) % mod;
    }
    return result;
}
int main(){
    long long p, g;
    long long a, b;
    long long A, B;
    long long keyAlice, keyBob;

    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter primitive root g: ");
    scanf("%lld", &g);

    printf("\nEnter private key of Alice: ");
    scanf("%lld", &a);
    printf("Enter private key of Bob: ");
    scanf("%lld", &b);

    A = power(g, a, p);
    B = power(g, b, p);

    printf("\nPublic value of Alice (A) = %lld", A);
    printf("\nPublic value of Bob (B) = %lld", B);

    keyAlice = power(B, a, p);
    keyBob = power(A, b, p);

    printf("\n\nShared Key computed by Alice = %lld", keyAlice);
    printf("\nShared Key computed by Bob = %lld", keyBob);

    printf("\n\n  -By Krishna Aryal");
    return 0;
}