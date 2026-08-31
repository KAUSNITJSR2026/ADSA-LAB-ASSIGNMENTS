/*Implement a function to read an arithmetic 
expression (as given in the previous problem) from 
the command line ( C:\> in Windows and $ in Linux) 
and display the computed value of the expression.  
For example: At Linux command prompt,
 $ (23 – 8) *3+ 28/4 
 followed by Enter key displays 
 52 $ */
#include <stdio.h>
#include <ctype.h>
#define max 100
int numberStack[max], numTop = -1;
char operatorStack[max];
int opTop = -1;
void pushNumber(int x){
    numberStack[++numTop] = x;
}
int popNumber(){
    return numberStack[numTop--];
}
void pushOperator(char c){
    operatorStack[++opTop] = c;
}
char popOperator(){
    return operatorStack[opTop--];
}
int operatorEmpty(){
    return opTop == -1;
}
int precedence(char c){
    switch(c){
        case '/': return 3;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}
int applyOperator(int a, int b, char c){
    switch(c){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}
int evaluateExpression(char *exp){
    for(int i=0; exp[i]; ){
        if(isdigit(exp[i])){
            int num = 0;
            while (isdigit(exp[i])){
                num = num*10 + (exp[i]-'0');
                i++;
            }
            pushNumber(num);
        }
        else if(exp[i]=='('){
            pushOperator(exp[i]);
            i++;
        }
        else if(exp[i]==')'){
            while(!operatorEmpty() && operatorStack[opTop] != '('){
                int b=popNumber(), a=popNumber();
                char c=popOperator();
                pushNumber(applyOperator(a,b,c));
            }
            popOperator();
            i++;
        }
        else{
            while(!operatorEmpty() && precedence(operatorStack[opTop]) >= precedence(exp[i])){
                int b=popNumber(), a=popNumber();
                char c=popOperator();
                pushNumber(applyOperator(a,b,c));
            }
            pushOperator(exp[i]);
            i++;
        }
    }
    while(!operatorEmpty()){
        int b=popNumber(), a=popNumber();
        char c=popOperator();
        pushNumber(applyOperator(a,b,c));
    }
    return popNumber();
}
int main(){
    char expr[max];
    printf("Enter expression: ");
    scanf("%s", expr);   // no spaces allowed
    int result = evaluateExpression(expr);
    printf("Result = %d\n", result);
    return 0;
}
