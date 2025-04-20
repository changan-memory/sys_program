#include <stdio.h>

void print3(){
    printf("hello print 3\n");
}

void print2(){
    printf("hello print 2\n");
    print3();
}
void print1(){
    printf("hello print 1\n");
    print2();
}
int addToTop(int top){
    int res =  0;
    int i = 1;
    for(; i <= top; ++i){
        res += i;
    }
    return res;
    print1();
}

int main(){
    printf("debug begin\n");
    
    int top = 100;
    int sum = addToTop(top);
    
    printf("sum is : %d\n", sum);
    
    printf("debug end\n");
    return 0;
}
