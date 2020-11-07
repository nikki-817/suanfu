#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
FILE *fp;
char str[1000];
int stack[1000];
int m[6][6]={{0,-1,-1,-1,-1,-1},{1,1,-1,-1,-1,1},{1,1,1,-1,-1,1},{1,1,1,0,0,1},{1,-1,-1,-1,-1,-1},{1,1,1,0,0,1}};
int change(char c){
    switch(c){
        case '+':
            return 1;
        case '*':
            return 2;
        case 'i':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        default:
            return -1;
    }
}
int main(int argc, char *argv[]){
    int top=0;
    int flag=0;
    int i=0;
    fp = fopen(argv[1], "r");
    //fp = fopen("input.txt", "r");
    fscanf(fp, "%s", str);
    while(1){
        if(i==strlen(str)){
            while(1){
                if(top==1&&stack[top]==6){
                    exit(0);
                }
                else{
                    if(stack[top]==3){
                        stack[top]=6;
                        printf("R\n");
                    }
                    else if(top>=3){
                        if(stack[top-2]==6&&stack[top-1]==1&&stack[top]==6){
                            stack[top-1]=0;
                            stack[top]=0;
                            top-=2;
                            printf("R\n");
                        }
                        else if(stack[top-2]==6&&stack[top-1]==2&&stack[top]==6){
                            stack[top-1]=0;
                            stack[top]=0;
                            top-=2;
                            printf("R\n");
                        }
                        else if(stack[top-2]==4&&stack[top-1]==6&&stack[top]==5){
                            stack[top-1]=0;
                            stack[top]=0;
                            stack[top-2]=6;
                            top-=2;
                            printf("R\n");
                        }
                        else{
                            printf("E\n");
                            exit(0);
                        }
                    }
                    else{
                        printf("E\n");
                        exit(0);
                    }
                }
            }
        }
        if(change(str[i]) == -1){
            printf("E\n");
            exit(0);
        }
        if(stack[top]==6){
            if(m[stack[top-1]][change(str[i])] == -1)
               flag=0;
            else if(m[stack[top-1]][change(str[i])] == 1)
                flag=1;
            else{
                printf("E\n");
                exit(0);
            }
        }
        else{
            if(m[stack[top]][change(str[i])] == -1)
               flag=0;
            else if(m[stack[top]][change(str[i])] == 1)
                flag=1;
            else{
                printf("E\n");
                exit(0);
            }
        }
        if(flag == 0){
            stack[++top]=change(str[i]);
            printf("I%c\n", str[i]);
            i++;
        }
        else{
            if(stack[top]==3){
                stack[top]=6;
                printf("R\n");
            }
            else if(top>=3){
                if(stack[top-2]==6&&stack[top-1]==1&&stack[top]==6){
                    stack[top-1]=0;
                    stack[top]=0;
                    top-=2;
                    printf("R\n");
                }
                else if(stack[top-2]==6&&stack[top-1]==2&&stack[top]==6){
                    stack[top-1]=0;
                    stack[top]=0;
                    top-=2;
                    printf("R\n");
                }
                else if(stack[top-2]==4&&stack[top-1]==6&&stack[top]==5){
                    stack[top-1]=0;
                    stack[top]=0;
                    stack[top-2]=6;
                    top-=2;
                    printf("R\n");
                }
                else{
                    printf("RE\n");
                    exit(0);
                }
            }
            else{
                printf("RE\n");
                exit(0);
            }
        }
    }
    fclose(fp);
    return 0;
}
