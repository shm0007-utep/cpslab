#include<stdio.h>
void swap(int *ptr2a, int *ptr2b){
    int temp = (*ptr2a);
    (*ptr2a) = (*ptr2b);
    (*ptr2b) = temp;
    return;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Before Swap %d %d\n",a,b);
    swap(&a,&b);
    printf("After Swap %d %d\n",a,b);

}
