#include <stdio.h>
#include <math.h>
void encrypt(char *x, int k);
void decrypt(char *x, int N, int k);
void brutedecrypt(char *x, int N, int k);


int main()
{
    char enc[20];
    printf("Code to be Decrypted: ");
    scanf("%s", enc);
    int k = 15;
    int c;
    encrypt(enc, k);
    printf("Encryption is: %s", enc);
    return 0;


}




void encrypt(char *x, int k)
{
    int i = 0;
    do
    {
        printf("%c\t", x[i]);
        x[i] = ((x[i] + k)%26 + 65 );
        printf("%c\n", x[i]);
        i++;
    } while(x[i] != NULL);
    return;
}




void decrypt(char *x, int N, int k)
{
    int i = 0;
    do
    {
        printf("%c\t", x[i]);
        x[i] = ((x[i] - k)%26 + 65 );
        printf("%c\n", x[i]);
        i++;
    } while(x[i] != NULL);
    return;
}
void brutedecrypt(char *x, int N, int k)
{
    int i = 0;
    for(i = 0; i < N; i++)
    {
        printf("%c\t", x[i]);
        x[i] = ((x[i] - k)%26 + 65 );
        printf("%c\n", x[i]);
    }
    return;
}