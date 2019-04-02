#include <stdio.h>
#include <math.h>
void encrypt(char *x, int N, int k);
void decrypt(char *x, int N, int k);
void brutedecrypt(char *x, int N, int k);


int main()
{
    char enc[] = "TESTDECRYPTION";
    int k = 15;
    encrypt(enc, 14, k);
    printf("Encryption is: %s", enc);
   for(c= 0; c < 26; c++)
   {
        brutedecrypt(enc, 14, c);
        printf("Decryption is: %s", enc);
   }
    return 0;


}




void encrypt(char *x, int N, int k)
{
int i = 0;
for(i = 0; i < N; i++)
{
    printf("%c\t", x[i]);
    x[i] = ((x[i] + k)%26 + 65 );
    printf("%c\n", x[i]);
}
return;
}
void decrypt(char *x, int N, int k)
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