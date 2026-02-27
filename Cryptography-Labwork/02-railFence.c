#include<stdio.h>
#include<string.h>
void encryptRF(char plain[],char cipher[],int key){
    int l = strlen(plain);
    int row=0,dir=1, index = 0;
    for (int r = 0; r < key; r++)
    {
        row =0;
        dir = 1;
        for (int i = 0; i < l; i++)
        {
            if (row == r)
            {
                cipher[index++] = plain[i];
            }
            row = row + dir;
            if (row==key-1 || row ==0)
            {
                dir = -dir;
            }
        }
    }
    cipher[index] = '\0';
}
void decryptRF(char cipher[], char plain[], int key){
    int l = strlen(cipher);
    int rail[key][l];
    int row = 0, dir = 1;
    for(int i=0;i<key;i++)
        for(int j=0;j<l;j++)
            rail[i][j] = 0;

    for(int i=0;i<l;i++){
        rail[row][i] = 1;
        row = row + dir;

        if(row == key-1 || row == 0)
            dir = -dir;
    }

    int index = 0;
    for(int i=0;i<key;i++)
        for(int j=0;j<l;j++)
            if(rail[i][j] == 1)
                rail[i][j] = cipher[index++];

    row = 0; dir = 1;
    for(int i=0;i<l;i++){
        plain[i] = rail[row][i];
        row += dir;

        if(row == key-1 || row == 0)
            dir = -dir;
    }
    plain[l] = '\0';
}
int main()
{
    char plain[50], cipher[50], decrypted[50];
    int key;
    printf("Enter the plain text: ");
    gets(plain);
    printf("Enter the key value: ");
    scanf("%d",&key);
    encryptRF(plain,cipher,key);
    printf("\nENCRYPTED TEXT using RAIL FENCE = %s",cipher);
    decryptRF(cipher,decrypted,key);
    printf("\nDECRYPTED TEXT using RAIL FENCE = %s",decrypted);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}