#include <stdio.h>
#include <ctype.h>
#define max 100
char s[max];
int top = -1;
void push(char c) {
    s[++top] = c;
}
char pop() {
    return s[top--];
}
int empty() {
    return top == -1;
}
int pt(char op) {
    switch(op) {
        case '/': return 3;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}
void itp(char* in, char* post) {
    int i, k = 0;
    for (i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if (isdigit(c)) {
            post[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!empty() && s[top] != '(') {
                post[k++] = pop();
            }
            pop();
        }
        else {
            while (!empty() && pt(s[top]) >= pt(c)) {
                post[k++] = pop();
            }
            push(c);
        }
    }
    while (!empty()) {
        post[k++] = pop();
    }
    post[k] = '\0';
}
int main() {
    char in[max], post[max];
    printf("Enter infix: ");
    scanf("%s", in);
    itp(in, post);
    printf("Postfix: %s\n", post);
    return 0;
}
