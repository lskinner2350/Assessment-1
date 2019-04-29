#include <stdio.h>
#include <math.h>



/* 
encrypt is the function that performs the rotation encryption.
FILE x is the unencrypted text(input).
FILE y is the encrypted text(output).
int k is the rotation amount.
*/
void encrypt(FILE *x, FILE *y, int k);
/*
decrypt is the function that performs the rotation decryption.
FILE x is the encrypted text(input).
FILE y is the decrypted text(output).
int k is the rotation amount.
CeasarChecker is used to calcule k is the key is not known.
*/
void decrypt(FILE *x, FILE *y, int k);
/*
subencrypt is the function that perfroms a substitution encryption.
FILE x is the unencrypted text(input).
FILE y is the encrypted text(output).
char *z is the array that contains the key alphabet.
*/
void subencrypt(FILE *x, FILE *y, char *z);
/*
subencrypt is the function that perfroms a substitution encryption.
FILE x is the encrypted text(input).
FILE y is the decrypted text(output).
char *z is the array that contains the key alphabet.
*/
void subdecrypt(FILE *x, FILE *y, char *z);
/*
CeasarChecker perfroms a statistical analysis on the text to calculate the most common letter.
This is then used to calculate the key to be used to decypher the text using roation.
FILE *x is the encrypted text.
*/
int CaesarChecker(FILE *x);

int main()
{
  
  


    char string[20000] = {0}; // temporary string to store text as its inputted.
    char a, b, c, d, e; // integers used for the switch cases for the menu system.
    char reader; // used to print out bthe results from file
    int k; // integer to store rotation key.
    int ret = 1; // used to check if the inputted key is a valid result.
    int trigger = 0; // used to check if the inputted substitution key is valid.
    char keyarray[26] = {0}; // array to store the substitution key
    FILE *text, *enc, *dec; // files to store the text in.
    text = fopen("text.txt", "w+");
    enc = fopen("encryption.txt","w");
    dec = fopen("decryption.txt","w");
    char ch;
    int g = 0; // counter used to check arrays.
   
   
    /*
    Simple menu system using switch cases.
    do while loops are used to make sure the user inputs a correct value.
    Anything special will be explained below.

    */
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
                    fflush(stdin); // clears standard input so that scanf stopped toing stupid things and to stop loops skipping over scanf's.
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
                            ret = scanf(" %d", &k); // using the fact that scanf will return the number of correctly inputted data types to make sure that a number is inputted.
                            if (ret == 0) // if statement containing the error for a non integer key.
                                {
                                    printf("I'm sorry dave. I'm afraid I can't do that. Please try again.\n"); // Meme error message.
                                }
                            else if(k < 0) // error check for negative key.
                                {
                                    printf("I'm sorry dave. I'm afraid I can't do that. Please try again. \n");
                                }
                            } while (k < 0 || ret == 0); // do while loop to make sure a key is entered.
                            printf("Please enter text to be encrypted(It can only be Capitol letters): ");
                            fflush(stdin);
                            gets(string); // scans standard input for the text and storesw it in the temporary string.
                            fprintf(text, "%s", string); // prints string to file.
                            fclose(text); // closing file to stop silliy errors 
                            text = fopen("text.txt", "r"); // read only version so I can't mess it up.
                            encrypt(text, enc, k); // calls the encrypt function.
                            fclose(enc);
                            enc = fopen("encryption.txt", "r");
                            while((reader = getc(enc)) != EOF) // prints encrypted text to screen directly from the file.
                            {
                                printf("%c", reader);
                            }
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
                                        k = 26 - k;
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
                                        fclose(dec);
                                        dec = fopen("decryption.txt", "r");
                                        while((reader = getc(dec)) != EOF)
                                        {
                                            printf("%c", reader);
                                        }
                                        break;
                                    case 'b':
                                        printf("Please enter text to be decrypted(It can only be Capitol letters): ");
                                        fflush(stdin);
                                        gets(string);
                                        fprintf(text, "%s", string);
                                        fclose(text);
                                        text = fopen("text.txt", "r");
                                        k = CaesarChecker(text); // teakes the text and perfroms statistical analysis to work out key.
                                        fclose(text);
                                        text = fopen("text.txt", "r");
                                        printf("%d\n", k);
                                        decrypt(text, dec, k);
                                        fclose(dec);
                                        dec = fopen("decryption.txt", "r");
                                        while((reader = getc(dec)) != EOF)
                                        {
                                            printf("%c", reader);
                                        }
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
                            do
                            {
                                fflush(stdin);
                                printf("\nPlease enter the key: ");
                                gets(keyarray); // scans for the key array.
                                for(g = 0; g < 26; g++) // for loop that checks that the keyarray has been filled.
                                {
                                    if(keyarray[g] == 0)
                                    {
                                        trigger = 1; // true/false variable to check the error.
                                        printf("I'm sorry dave. I'm afraid I can't do that. Please try again.\n");
                                    }
                                }
                            } while (trigger == 1); // 
                            printf("Please enter text to be encrypted(It can only be Capitol letters): ");
                            fflush(stdin);
                            gets(string);
                            fprintf(text, "%s", string);
                            fclose(text);
                            text = fopen("text.txt", "r");
                            subencrypt(text, enc, keyarray);
                            fclose(enc);
                            enc = fopen("encryption.txt", "r");
                            while((reader = getc(enc)) != EOF)
                            {
                                printf("%c", reader);
                            }    
                            break;
                        case 'b':
                            do
                                {
                                    fflush(stdin);
                                    printf("\nPlease select an option.\n");
                                    printf("a) Key is known.\n");
                                    printf("b) Key is not known.\n");
                                    printf("Selection: ");
                                    scanf("%c", &d);
                                    switch (d)
                                    {
                                        case 'a':
                                            do
                                            {
                                                fflush(stdin);
                                                printf("\nPlease enter the key: ");
                                                gets(keyarray);
                                                for(g = 0; g < 26; g++)
                                                {
                                                    if(keyarray[g] == 0)
                                                    {
                                                        trigger = 1;
                                                        printf("I'm sorry dave. I'm afraid I can't do that. Please try again.\n");
                                                    }
                                                }
                                            } while (trigger == 1);
                                            printf("Please enter text to be decrypted(It can only be Capitol letters): ");
                                            fflush(stdin);
                                            gets(string);                         
                                            fprintf(text, "%s", string);
                                            fclose(text);
                                            text = fopen("text.txt", "r");
                                            subdecrypt(text, dec, keyarray);
                                            fclose(dec);
                                            dec = fopen("decryption.txt", "r");
                                            while((reader = getc(dec)) != EOF)
                                            {
                                                printf("%c", reader);
                                            }
                                            
                                            break;
                                        case 'b' :
                                            printf("One does not simply decrypt without a key.\n"); // Meme because I can't do substitution decryption without a key.
                                            break;
                                        default:
                                            break;
                                    }


                                } while (d < 'a' || d > 'b');

                                

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
    // closing all the files so the OS doesn't hate me.
    fclose(text);
    fclose(enc);
    fclose(dec);
    return 0;


}




void encrypt(FILE *x, FILE *y, int k)
{
    char c, ch; // variables to store characters while the encryption is performed.
    while((c = fgetc(x)) != EOF) // calls each charcter from the input file.
    {
        if(c >= 65 && c <= 90) // checks that the character is a capital letter.
        {
        c = c - 65; // shifts the letter back to 0 - 26.
        ch = (c + k)%26 + 65; // equation for rotation encryption.
        putc(ch, y); // prints character to output file.
        }
        else
        {
          putc(c, y); // prints character to output file that are not capital letters.
        }
        


    }
    return;
}

void decrypt(FILE *x, FILE *y, int k) // works exactly the same as encrypt function.
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
                if(c == z[i]) // looks for the input character in the keyarray.
                {
                    char ch = alphabet[i]; // takes the position of the input character in the Aplhabet and replaces the input character with it.
                    putc(ch, y); // places the output character into the output file.
                }
                else{}
            }
            
        }
        else
       {
            putc((int)c, y); // places any non capital letter values straight into the output file.
     }
        
     }
    return;
}
void subencrypt(FILE *x, FILE *y, char *z)
{
    char c;
    while((c = fgetc(x)) != EOF) // Rretreives the character from the input file.
    {
        
        if(c >= 65 && c <= 90) // Checks that it is a capital letter.
        {
            char ch = z[c - 65]; // takes the position of the input character and the standard alphabet and replaces it with the character in the same position in the keyarray.
            putc(ch, y); // takes the output charcater and places it in the output file.
            
        }
        else
       {
            putc((int)c, y); // places any non capital letter values straight into the output file.
     }
      
    }
    return;
}
int CaesarChecker(FILE *x)
{
    int k; // final key.
    char c; // character variable.
    int i, g; // counters
    int h = 1; 
    int letters[26];
    for(i = 0; i < 26; i++)
        {
            letters[i] = 0;
        }
    while((c = fgetc(x)) != EOF) // calls character from input.
        {
            if (c >= 65 && c <= 90) // only checks capital letters
                letters[c - 65]++; // counts up each time a character appears.
        }
    char maximum; // value of most common character
    maximum = letters[0];
    int common = 1;
    for(g = 1; g < 26; g++) // counts through the frequency array.
    {
    if(letters[g] > maximum)// if the frequency of a letter is greater than the current max it stores the frequency and also which letter it is.
        {
            maximum = letters[g];
            common = h + 1;
        }
        h++;
    }
    k = common - 5; // assumes the most common letter is 'e' so uses its position on the alphabet to calculate the key.
    if (k <= 0) // mathemagic to make all answrs positive and also useful for decryption. 
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
