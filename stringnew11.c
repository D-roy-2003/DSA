#include<stdio.h>
#include<string.h>
void main()
{
    // ={'l','a','n','g','u','a','g','e'}; 
    char alpha[50];
    printf("\n Enter the string:");
    gets(alpha);
    int vowel=0,consonant=0,i;
    for(i=0;i<=strlen(alpha);i++)
    {
        scanf("\n %c",&alpha[i]);     
        if(alpha[i]=='a' || alpha[i]=='e' || alpha[i]=='i' || alpha[i]=='o' || alpha[i]=='u' )
        vowel++;
        else
        consonant++;
    }
    
    
    printf("The number of vowels=%d",vowel);
    printf("The number of consonants=%d",consonant);
}
