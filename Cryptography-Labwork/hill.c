#include<stdio.h>
#include<string.h>
#include<ctype.h>

int modInverse(int a){
    a = a % 26;
    for(int x=1; x<26; x++){
        if((a*x) % 26 == 1)
            return x;
    }
    return -1;
}
void encryptHill(char plain[], char cipher[], int key[2][2]){
    int l = strlen(plain);

    if(l % 2 != 0){
        plain[l] = 'X';
        plain[l+1] = '\0';
        l++;
    }
    for(int i=0; i<l; i+=2){
        int p1 = toupper(plain[i]) - 65;
        int p2 = toupper(plain[i+1]) - 65;
        cipher[i]   = 65 + ((key[0][0]*p1 + key[0][1]*p2) % 26);
        cipher[i+1] = 65 + ((key[1][0]*p1 + key[1][1]*p2) % 26);
    }
    cipher[l] = '\0';
}

void decryptHill(char cipher[], char plain[], int key[2][2]){
    int l = strlen(cipher);
    int det = (key[0][0]*key[1][1] - key[0][1]*key[1][0]) % 26;
    if(det < 0) det += 26;
    int invDet = modInverse(det);
    int invKey[2][2];

    invKey[0][0] =  key[1][1];
    invKey[1][1] =  key[0][0];
    invKey[0][1] = -key[0][1];
    invKey[1][0] = -key[1][0];

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            invKey[i][j] = invKey[i][j] * invDet;
            invKey[i][j] = (invKey[i][j] % 26 + 26) % 26;
        }
    for(int i=0; i<l; i+=2){
        int c1 = cipher[i] - 65;
        int c2 = cipher[i+1] - 65;

        plain[i]   = 65 + ((invKey[0][0]*c1 + invKey[0][1]*c2) % 26);
        plain[i+1] = 65 + ((invKey[1][0]*c1 + invKey[1][1]*c2) % 26);
    }
    plain[l] = '\0';
}
int main(){
    char plain[50], cipher[50], decrypted[50];
    int key[2][2];

    printf("Enter the plain text (uppercase only): ");
    gets(plain);
    printf("Enter 2x2 key matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d",&key[i][j]);
        }
        
    }
    encryptHill(plain, cipher, key);
    printf("\nENCRYPTED TEXT using HILL CIPHER = %s", cipher);
    decryptHill(cipher, decrypted, key);
    printf("\nDECRYPTED TEXT using HILL CIPHER = %s", decrypted);
    printf("\n\n  -By Krishna Aryal");
    return 0;
}