#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modInverse(int e, int phi){
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while(newr != 0){
        int q = r / newr;
        int temp = newt;
        newt = t - q * newt;
        t = temp;

        temp = newr;
        newr = r - q * newr;
        r = temp;
    }
    if(t < 0)
        t += phi;

    return t;
}

// Power function
long long power(long long base, long long exp, long long mod){
    long long result = 1;
    for(int i = 0; i < exp; i++){
        result = (result * base) % mod;
    }
    return result;
}

int main(){
    int p, q, n, phi, e, d;
    char message[100];
    long long cipher[100];
    char decrypted[100];

    printf("Enter prime p: ");
    scanf("%d", &p);
    printf("Enter prime q: ");
    scanf("%d", &q);

    n = p * q;
    phi = (p-1)*(q-1);

    // Choose e
    for(e = 2; e < phi; e++){
        if(gcd(e, phi) == 1)
            break;
    }
    d = modInverse(e, phi);
    printf("\nPublic Key (e,n) = (%d,%d)", e, n);
    printf("\nPrivate Key (d,n) = (%d,%d)", d, n);

    // getchar(); // clear buffer

    printf("\n\nEnter text message: ");
    scanf("%s",message);

    int len = strlen(message);

    // Encryption
    printf("\nEncrypted message:\n");
    for(int i = 0; i < len; i++){
        cipher[i] = power((int)message[i], e, n);
        printf("%lld ", cipher[i]);
    }

    // Decryption
    printf("\n\nDecrypted message:\n");
    for(int i = 0; i < len; i++){
        decrypted[i] = (char)power(cipher[i], d, n);
        printf("%c", decrypted[i]);
    }
    decrypted[len] = '\0';
    printf("\n\n  -By Krishna Aryal");
    return 0;
}