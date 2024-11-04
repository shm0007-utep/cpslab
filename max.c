#include<stdio.h>
int main(){

    int num[] = {5,2,3,4,9};
    int max = num[0];
    for(int i = 1; i< 5; i++){
        if(max< num[i])
            max = num[i];
    }
    int *ptrMax = &num[0];
    for(int i = 1; i< 5; i++){
        if(*ptrMax< num[i])
            ptrMax = &num[i];
    }
    printf("Max %d Ptr %d ",max,*ptrMax);
    
}