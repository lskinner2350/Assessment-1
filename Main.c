#include <stdio.h>
#include <math.h>
void encrypt(char *x, int k);
void decrypt(char *x, int N, int k);
void brutedecrypt(char *x, int N, int k);
void subencrypt(char *x, char *y, char *z);// x[] is string to be encypted y[] is the encyption and z[] is the key.
void subdecrypt(char *x, char *y, char *z);

int main()
{
    char text[20];
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char enc[20];
    printf("Code to be Encrypted: ");
    scanf("%s", text);
    int k = 15;
    int c;
    subencrypt(text, enc, key);
    printf("Encryption is: %s", enc);
    return 0;


}




void encrypt(char *x, int k)
{
    int i = 0;
    while(x[i] != 0)
    {
        printf("%c\t", x[i]);
        x[i] = ((x[i] + k)%26 + 65 );
        printf("%c\n", x[i]);
        i++;
    }
    return;
}




void decrypt(char *x, int N, int k)
{
    int i = 0;
    while(x[i] != 0)
    {
        printf("%c\t", x[i]);
        x[i] = ((x[i] - k)%26 + 65 );
        printf("%c\n", x[i]);
        i++;
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
void subencrypt(char *x, char *y, char *z)
{
    int i = 0;
    char c;
    while(x[i] != 0)
    {
        c = x[i];
        y[i] = z[c - 65];
        i++;

    }
    return;
}
void subdecrypt(char *x, char *y, char *z)
{
    int i = 0;
    char c;
    while(x[i] != 0)
    {
        c = x[i];
        if(c >= 65 && c <= 90)
        {
            y[i] = z[c - 65];
        }
        else
        {
            
        y[i] = c;
        }
        i++;

    }
    return;
}

