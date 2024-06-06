#include<stdio.h>
#include<string.h>
void main()
{
    char password[20];
    char confirm_pass[20];
    char user_name[20];
    int match,age,i;
    printf("Enter The Password :");
    scanf("%s",password);
    printf("\nConfirm the password and reenter:");
    scanf("%s",confirm_pass);
    match=strcmp(confirm_pass,password);
    if(match==0)
    {
        printf("\nEnter the username: ");
        scanf("%s",&user_name);
        printf("\nEnter the age: ");
        scanf("%d",&age);
        printf("\nUsername:");
        puts(user_name);
        printf("\nAge=%d",age);
    }
    else
    {
       printf("\n Invalid password....");
    }
}
