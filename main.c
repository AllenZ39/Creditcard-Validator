#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAXINPUT 20


void removeSpaces(char* s){
    const char* d = s;
    do{
        while (*d == ' ') {
            ++d;
        }
    }while (*s++ = *d++);
}

int isNumber(int len, char s[MAXINPUT]){    //Checks whether the input contains only digits
    int i;
    for (i=0;i<len; i++)
        if (!isdigit(s[i]))
        {
            return 0;
        }
    return 1;
}

int validPrefix(char s[MAXINPUT]){          //Checks whether the input has a valid prefix number
    char c = s[0];
    int p = c - '0';
    if(p==3 || p==4 || p==5 || p==6){
        return 1;
    }
    return 0;
}

int validSum(int len, char s[MAXINPUT]){    //Implementing luhn test
    char rev[MAXINPUT];
    int r = s[len-1]-'0';               //The last digit of the input
    int i, odd, even;
    int sum = 0;
    memset(rev, '\0', sizeof(rev));
    s[len-1] = '\0';
    strcpy(rev, strrev(s));             //reversing the input string

    for(i=0; i<strlen(rev); i+=2){
        if((i+1)<strlen(rev)){
            even = rev[i+1]-'0';
            sum+=even;
        }
        odd = 2*(rev[i]-'0');
        if(odd>9){
            odd = odd-9;
        }
        sum+=odd;
    }
    if((sum+r)%10==0){
        return 1;
    }
    else{
        return 0;
    }
}

void main()
{
    char input[MAXINPUT];
    int d, length;
    do{
        printf("Enter 1 to check a credit card number, enter 2 to exit the program.\n");
        fgets(input, MAXINPUT, stdin);
        input[strcspn( input, "\n" )] = '\0';
        d = atoi(input);
        length = strlen(input);
        if(d==1){
            printf("Please enter the credit card number you want to validate.\n");
            fgets(input, MAXINPUT, stdin);
            input[strcspn( input, "\n" )] = '\0';
            removeSpaces(input);
            length = strlen(input);
            if(isNumber(length, input)==1 && (length>= 13 && length<=16) && validPrefix(input)==1 && validSum(length, input)==1){
                printf("This is a valid credit card number.\n\n");
                d = 3;
            }
            else{
                printf("This is an invalid credit card number.\n\n");
                d = 3;
            }
        }
        else if(d==2){
            break;
        }
    }while(isNumber(length, input)!=1 || (d!=1 && d!=2));
    printf("Ended.\n");
}
