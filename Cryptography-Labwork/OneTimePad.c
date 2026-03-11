#include<stdio.h>
#include<string.h>
int main(){
    char plaintext[100], key[100];
    int cipher[100];
    char decrypted[100];
    int len;
    printf("Enter plaintext: ");
    scanf("%s",plaintext);
    printf("Enter key (same length as plaintext): ");
    scanf("%s",key);
    len = strlen(plaintext);

    if(strlen(key) != len){
        printf("\nError: Key length must be equal to plaintext length.\n");
        return 0;
    }

    // Encryption
    for(int i = 0; i < len; i++){
        cipher[i] = plaintext[i] ^ key[i];
    }
    printf("\nENCRYPTED MESSAGE using One-Time-Pad(numeric form):\n");
    for(int i = 0; i < len; i++){
        printf("%d ", cipher[i]);
    }
    cipher[len] = '\0';

    // Decryption
    for(int i = 0; i < len; i++){
        decrypted[i] = cipher[i] ^ key[i];
    }
    decrypted[len] = '\0';
    printf("\nDECRYPTED MESSAGE using OTP:\n");
    printf("%s",decrypted);
    printf("\n\n  -By Krishna Aryal");

    return 0;
}