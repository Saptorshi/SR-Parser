/*Shift Reduce Parser*/

#include <stdio.h>
#include <string.h>
#include "stack.h"

char stackTop, temp [4];;

void checkAction();

int main(){
    printf("-------------------------------------\n\tSHIFT REDUCE PARSER\n-------------------------------------\n");
    printf("\tGrammer:\n");
    printf("\tE -> E + E\n\tE -> E * E\n\tE -> @\n");
    printf("-------------------------------------\n");

    char input [20];
    int i, j, lengthOfStack;


    printf("Enter the input string to be PARSED:\n");
    gets(input);
    push('$');// setting the bottom of the stack with $

    for(i = 0; input[i] != '\0'; i ++){
        push(input[i]); // shift operation
        checkAction();
    }

    lengthOfStack = strlen(stackElement);
    //printf("%d\n", lengthOfStack);

    printf("-------------------------------------\n");

    while(lengthOfStack > 2){

        j = 0;
        //printf("2j is %d \n",j);
        for(i = lengthOfStack - 1; i >= lengthOfStack - 3; i --){
            temp [j]= stackElement [i];
            printf("j is %d --> %c\n", j, temp[j]);
            j++;
        }
        temp [j] = '\0';
        printf("TEMP ARRAY [%s]\n", temp);

        if( (strcmp(temp, "E+E")==0) || (strcmp(temp, "E*E")==0) ){
            printf("TRUE\n");
            /*
            printf("%c\n", pop());
            printf("%c\n", pop());
            printf("%c\n", pop());
            */

            for(i = lengthOfStack - 1; i > lengthOfStack - 3; i--) // used the for loop to replace the value for pop() operations with blanck space
                stackElement[i] = ' ';


            stackElement[lengthOfStack-3] = 'E'; // equivalent to push() operation
            //push ('E');

            printf("STACK [%s]\n", stackElement);
            printf("----------------------\n");
            getch();
            lengthOfStack = lengthOfStack - 2;
        }else{
            printf("FALSE\n");
            printf("ERROR : String NOT ACCEPTED!\n");
            exit(0);
        }
    }

    printf("STRING PARSED SUCCESSFULLY! ^_^\n");

}

void checkAction(){
    stackTop = pop();
    //printf("%c\n",pop());
    //getch();

    switch(stackTop){
    case '@':
        //reduce and move the pointer
        //pop();
        push('E');
        break;

    case '+':
        //pop();
        push('+');
        break;

    case '*':
        //pop();
        push('*');
        break;
    default:
        printf("ERROR : STRING NOT ACCEPTED!!\n");
        exit(0);
        break;
    }
}
