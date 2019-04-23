#include <stdio.h>
#include <math.h>
void encrypt(FILE *x, FILE *y, int k);
void decrypt(FILE *x, FILE *y, int k);
void brutedecrypt(FILE *x, FILE *y, int k);
void subencrypt(FILE *x, FILE *y, char *z);
void subdecrypt(FILE *x, FILE *y, char *z);
int CaesarChecker(FILE *x);

int main()
{
  
  
    int k;
    char keyarray[26];
    FILE *text, *enc, *key, *dec;
    text = fopen("text.txt", "r");
    enc = fopen("encryption.txt","w");
    key = fopen("key.txt", "r");
    dec = fopen("decryption.txt","w");
    char ch;
    int g = 0;
    //k = 14;
    k = CaesarChecker(text);
    fclose(text);
    text = fopen("text.txt", "r");
    while((ch = getc(key)) != EOF)
        {

            keyarray[g] = ch;
            g++;
        }
   
    printf("%d\n", k);
    decrypt(text, dec, k);
    //encrypt(text, enc, k);
    fclose(text);
    fclose(enc);
    fclose(key);
    fclose(dec);
    
    return 0;


}




void encrypt(FILE *x, FILE *y, int k)
{
    char c, ch;
    while((c = fgetc(x)) != EOF)
    {
        if(c >= 65 && c <= 90)
        {
        c = c - 65;
        ch = (c + k)%26 + 65;
        putc(ch, y);
        }
        else
        {
          putc(c, y);
        }
        


    }
    return;
}

void decrypt(FILE *x, FILE *y, int k)
{
  char c, ch;
    while((c = fgetc(x)) != EOF)
    {
        if(c >= 65 && c <= 90)
        {
        c = c - 65;
        ch = (c + k)%26 + 65;
        fputc(ch, y);
        }
        else
        {
          fputc(c, y);
        }
        


    }
    return;
}
void brutedecrypt(FILE *x, FILE *y, int k)
{
    char ch, cha;
    while((ch = fgetc(x)) != EOF)
    {
        if(ch >= 65 && ch <= 90)
        {
        cha = (ch + k)%26 + 65;
        printf("%d\n", cha);
        fputc(cha, y);
        }
        else
        {
          fputc(ch, y);
        }
        
    }
    return;
}

void subdecrypt(FILE *x, FILE *y, char *z)
{
    int i = 0;  
    char c;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while((c = fgetc(x)) != EOF)
    {
        
        if(c >= 65 && c <= 90)
        {
            for(i = 0; i < 26; i++)
            {
                if(c == z[i])
                {
                    char ch = alphabet[i];
                    putc(ch, y);
                }
                else{}
            }
            
        }
        else
       {
            putc((int)c, y);
     }
        
     }
    return;
}
void subencrypt(FILE *x, FILE *y, char *z)
{
    char c;
    while((c = fgetc(x)) != EOF)
    {
        
        if(c >= 65 && c <= 90)
        {
            char ch = z[c - 65];
            putc(ch, y);
            
        }
        else
       {
            putc((int)c, y);
     }
      
    }
    return;
}
int CaesarChecker(FILE *x)
{
    int k;
    char c;
    int i, g;
    int h = 1;
    int letters[26];
    for(i = 0; i < 26; i++)
        {
            letters[i] = 0;
        }
    while((c = fgetc(x)) != EOF)
        {
            if (c >= 65 && c <= 90)
                letters[c - 65]++;
        }
    int maximum;
    maximum = letters[0];
    int common = 1;
    for(g = 1; g < 26; g++)
    {
    if(letters[g] > maximum)
        {
            maximum = letters[g];
            common = h + 1;
        }
        h++;
    }
    k = common - 5;
    if (k <= 0)
    {
        k = (-1)*k;
        k = 26 - k;
    }
    else
    {
        k = 26 - k;
        k = 26 - k;
    }
    
        printf("%d\n", k);
        k = 26 - k;
    return k;
}
