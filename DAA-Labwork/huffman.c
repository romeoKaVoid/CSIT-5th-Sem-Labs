#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char data, int freq)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printCodes(struct Node* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void sortNodes(struct Node* arr[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j]->freq > arr[j+1]->freq)
            {
                struct Node* temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void Huffman(char data[], int freq[], int n)
{
    struct Node* arr[MAX];

    for (int i = 0; i < n; i++)
        arr[i] = createNode(data[i], freq[i]);

    while (n > 1)
    {
        sortNodes(arr, n);

        struct Node* left = arr[0];
        struct Node* right = arr[1];

        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        arr[1] = newNode;
        arr[0] = arr[n-1];
        n--;
    }

    int arrCode[MAX];
    printf("\nHuffman Codes:\n");
    printCodes(arr[0], arrCode, 0);
}

int main()
{
    int n;
    char data[MAX];
    int freq[MAX];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters:\n");
    for (int i = 0; i < n; i++)
        scanf(" %c", &data[i]);

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    Huffman(data, freq, n);

    printf("\n\n\tBy Krishna Aryal");
    return 0;
}