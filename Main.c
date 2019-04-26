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
  
  


    char string[20000] = {0};
    char a, b, c, d;
    int k, ret = 1;
    char keyarray[26];
    FILE *text, *enc, *key, *dec;
    text = fopen("text.txt", "w+");
    enc = fopen("encryption.txt","w");
    key = fopen("key.txt", "r");
    dec = fopen("decryption.txt","w");
    char ch;
    int g = 0;
    //k = 14;
    //k = CaesarChecker(text);
    do
    {
        printf("Please select an option.\n");
        printf("a) Rotation Cypher.\n");
        printf("b) Subsitiution Cypher.\n");
        printf("Selection: ");
        scanf("%c", &a);
        switch (a)
        {
            case 'a':
                do
                {
                    fflush(stdin);
                    printf("Please select an option.\n");
                    printf("a) Encryption.\n");
                    printf("b) Decryption.\n");
                    printf("Selection: ");
                    scanf("%c", &b);
                    switch (b)
                    {
                        case 'a':
                            do
                            {
                            printf("Please enter the key: ");
                            fflush(stdin);
                            ret = scanf(" %d", &k);
                            if (ret == 0) 
                                {
                                    printf("I'm sorry dave. I'm afraid I can't do that. Please try again.\n");
                                }
                            else if(k < 0)
                                {
                                    printf("I'm sorry dave. I'm afraid I can't do that. Please try again. \n");
                                }
                            } while (k < 0 || ret == 0);
                            printf("Please enter text to be encrypted(It can only be Capitol letters): ");
                            fflush(stdin);
                            gets(string);
                            fprintf(text, "%s", string);
                            fclose(text);
                            text = fopen("text.txt", "r");
                            encrypt(text, enc, k);
                            break;
                        case 'b':
                            do
                            {
                                fflush(stdin);
                                printf("Please select an option.\n");
                                printf("a) Key is known.\n");
                                printf("b) Key is not known.\n");
                                scanf("%c", &c);
                                switch (c)
                                {
                                    case 'a':
                                        do
                                        {
                                        printf("Please enter the key: ");
                                        fflush(stdin);
                                        ret = scanf(" %d", &k);
                                        k;
                                        if (ret == 0) 
                                            {
                                                printf("I'm sorry dave. I'm afraid I can't do that. Please try again.\n");
                                            }
                                        else if(k < 0)
                                            {
                                                printf("I'm sorry dave. I'm afraid I can't do that. Please try again. \n");
                                            }
                                        } while (k < 0 || ret == 0);
                                        printf("Please enter text to be decrypted(It can only be Capitol letters): ");
                                        fflush(stdin);
                                        gets(string);
                                        fprintf(text, "%s", string);
                                        fclose(text);
                                        text = fopen("text.txt", "r");
                                        decrypt(text, dec, k);
                                        break;
                                    case 'b':
                                        printf("Please enter text to be decrypted(It can only be Capitol letters): ");
                                        fflush(stdin);
                                        gets(string);
                                        fprintf(text, "%s", string);
                                        fclose(text);
                                        text = fopen("text.txt", "r");
                                        k = CaesarChecker(text);
                                        fclose(text);
                                        text = fopen("text.txt", "r");
                                        printf("%d\n", k);
                                        decrypt(text, dec, k);
                                        break;
                                
                                    default:
                                        break;
                                }


                            } while (c < 'a' || c > 'b');
                            
                            break;
                        default:
                            break;
                    }
                } while (b < 'a' || b > 'b');
                

                break;
            case 'b':
                do
                {
                    fflush(stdin);
                    printf("Please select an option.\n");
                    printf("a) Encryption.\n");
                    printf("b) Decryption.\n");
                    printf("Selection: ");
                    scanf("%c", &d);
                    switch (d)
                    {
                        case 'a':
                        
                            break;
                        case 'b':

                            break;
                        default:
                            break;
                    }
                } while (d < 'a'|| d > 'b');
                
                break;
            default:
            
                break;
        }
    } while (a < 'a'|| a > 'b');
    
    


    fclose(text);
    text = fopen("text.txt", "r");
    while((ch = getc(key)) != EOF)
        {

            keyarray[g] = ch;
            g++;
        }
    //decrypt(text, dec, k);
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
    

        k = 26 - k;
    return k;
}
