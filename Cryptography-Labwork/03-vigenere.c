#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encryptVig(char plain[],char cipher[],char key[]){
    int l=strlen(plain);
    int k=strlen(key);
    for (int i = 0,j=0; i < l; i++,j++)
    {
        if (j>=k)
        {
            j = 0;
        }
        int p = toupper(plain[i])-65;
        int keyVal = toupper(key[j])-65;
        cipher[i] = 65 + ((p+keyVal) % 26);
    }
    cipher[l] = '\0';
}
void decryptVig(char cipher[],char plain[],char key[]){
    int l = strlen(cipher);
    int k = strlen(key);

    for (int i = 0,j=0; i < l; i++,j++)
    {
        if (j>=k)
        {
            j = 0;
        }
        int c = toupper(cipher[i])-65;
        int keyVal = toupper(key[j])-65;

        plain[i] = 65 + ((c-keyVal+26) %26);
    }
    plain[l] = '\0';
}
int main()
{
    char plain[50],cipher[50],decrypted[50],key[10];
    printf("Enter the plain text: ");
    gets(plain);
    printf("Enter the key value: ");
    gets(key);
    encryptVig(plain,cipher,key);
    printf("ENCRYPTED TEXT using VIGENERE = %s",cipher);
    decryptVig(cipher,decrypted,key);
    printf("\nDECRYPTED TEXT using VIGENERE = %s",decrypted);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}