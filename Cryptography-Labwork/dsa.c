#include<stdio.h>
// Power function
long int power(long int base, long int exp, long int mod){
    long int result = 1;
    for(int i=0;i<exp;i++){
        result = (result*base)%mod;
    }
    return result;
}
int modInverse(int a, int m){
    for(int i=1;i<m;i++){
        if((a*i)%m == 1)
            return i;
    }
    return -1;
}
int main(){
    long int p, q, g;
    long int x, y;
    long int H;
    long int k;
    long int r, s;

    printf("Enter a prime number p: ");
    scanf("%ld",&p);
    printf("Enter another prime number q such that (p-1)mod q =0): ");
    scanf("%ld",&q);
    printf("Enter an integer g (primitive root of p): ");
    scanf("%ld",&g);

    printf("Enter private key x (<q): ");
    scanf("%ld",&x);
    y = power(g,x,p);
    printf("Public key y = %ld\n",y);

    printf("Enter hash of message H(M): ");
    scanf("%ld",&H);

    printf("Enter random k (<q): ");
    scanf("%ld",&k);

    r = power(g,k,p)%q;
    int k_inv = modInverse(k,q);
    s = (k_inv*(H + x*r))%q;
    printf("\nSignature (r,s) = (%ld,%ld)\n",r,s);

    // Verification
    int w = modInverse(s,q);
    long int u1, u2, v;
    u1 = (H*w)%q;
    u2 = (r*w)%q;
    v = ((power(g,u1,p)*power(y,u2,p))%p)%q;

    if(v==r){
        printf("Signature Verified Successfully!!\n");
    }
    else{
        printf("Signature Verification Failed!!\n");
    }
    printf("\n\n  -By Spandan Kandel");
    return 0;
}
