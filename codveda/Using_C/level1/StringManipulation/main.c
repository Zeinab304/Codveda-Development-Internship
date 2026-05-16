#include <stdio.h>
#include <stdlib.h>

enum Bool{False,True};

int main()
{
    char str[20];
    printf ( "Enter string: ");
    scanf("%s", &str);
    printf ( "\nLength of string: %d" ,strlen(str));
    printf ( "\nReversed string: ");
    for(int i=strlen(str)-1; i>=0; i--)
    {
        printf ("%c",str[i]);
    }
    printf ( "\nNumber of vowels: ");
    int count = 0;
    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
    }
    printf ( "%d",count);
    printf ( "\nNumber of consonants: %d" , (strlen(str) - count));
    printf ( "\nString Palindrome: ");
    enum Bool isPalindrome = True;
    for(int i=0; i<strlen(str)/2; i++)
    {
        if(tolower(str[i]) != tolower(str[strlen(str)-1-i]))
        {
            isPalindrome = False;
            break;
        }
    }
    printf ( (isPalindrome ? "Yes" : "No"));
    return 0;
}
