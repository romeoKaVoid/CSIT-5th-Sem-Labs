#include<stdio.h>
#include<string.h>
int main()
{
    char plaintext[100], ciphertext[100], key[100], decrypted[100];
    printf("Enter the plaintext: ");
    scanf("%s",plaintext);

    again:
    printf("Enter the key(same length as plaintext): ");
    scanf("%s",key);
    int len = strlen(plaintext);
    if (strlen(key) != len)
    {
        printf("\nError!! Key length doesn't match plaintext!!\n");
        goto again;
    }
    
    //Encryption
    for (int i = 0; i < len; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
    ciphertext[len] = '\0';
    printf("\nENCRYPTED MESSAGE using VERNAM(in numbers):\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",ciphertext[i]);
    }

    //Decryption
    for (int i = 0; i < len; i++)
    {
        decrypted[i] = ciphertext[i] ^ key[i];
    }
    decrypted[len] = '\0';
    printf("\nDECRYPTED MESSAGE using VERNAM:\n");
    printf("%s",decrypted);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}