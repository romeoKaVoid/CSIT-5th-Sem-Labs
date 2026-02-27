#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(char text[],char cipher[], int key){
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        cipher[i] = text[i] + key;
        if (isupper(text[i]) && (cipher[i]>'Z'))
        {
            cipher[i] = cipher[i] - 26;
        }
        if (islower(text[i]) && (cipher[i]>'z'))
        {
            cipher[i] = cipher[i] - 26;
        }
    }
    cipher[length] = '\0';
}
void decrypt(char text[],char plain[], int key){
    int length=strlen(text);
    for (int i = 0; i < length; i++)
    {
        plain[i] = text[i] - key;
        if (isupper(text[i]) && (plain[i]<'A'))
        {
            plain[i] = plain[i] + 26;
        }
        if (islower(text[i]) && (plain[i] < 'a'))
        {
            plain[i] = plain[i] + 26;
        }
    }
    plain[length] = '\0';
}
int main()
{
    char plain[50],cipher[50],decrypted[50];
    int key;
    printf("Enter the plain text: ");
    scanf("%s",plain);
    printf("Enter the key value: ");
    scanf("%d",&key);
    printf("\n\n PLAIN TEXT = %s",plain);
    encrypt(plain,cipher,key);
    printf("\nENCRYPTED TEXT using CAESAR = %s",cipher);
    decrypt(cipher,decrypted,key);
    printf("\nDECRYPTED TEXT using CAESAR = %s",decrypted);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}