#include <stdio.h>
#include <math.h>
void encrypt(char *x, int k);
void decrypt(char *x, int N, int k);
void brutedecrypt(char *x, int N, int k);
void subencrypt(FILE *x, FILE *y, char *z);
void subdecrypt(char *x, char *y, char *z);

int main()
{
  
  
  
    char keyarray[26];
    FILE *text, *enc, *key;
    text = fopen("text.txt", "r");
    enc = fopen("encryption.txt","w+");
    key = fopen("key.txt", "r");
    char ch;
    int g = 0;
    while((ch = getc(key)) != EOF)
        {

            keyarray[g] = ch;
            g++;
        }
  
    subencrypt(text, enc, keyarray);

    fclose(text);
    fclose(enc);
    fclose(key);
    fscanf()
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
void subencrypt(FILE *x, FILE *y, char *z)
{
    
    char c;
    while((c = getc(x)) != EOF)
    {
        if(c >= 65 && c <= 90)
        {
            int ch = z[c - 65];
            putc(ch, y);
            
        }
        else
        {
            putc(c, y);
        }
        
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

