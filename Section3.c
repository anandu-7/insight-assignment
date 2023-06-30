#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void f(int array[],int n);

int main(void){
    int n;
    
    printf("Enter the size of the input array:");
    scanf("%d",&n);
    int a[n];
    
    for(int i = 0 ; i < n ;i++){
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    printf("Input array:");
    for(int i = 0 ; i < n; i++){
        printf("%d ",a[i]);
    }
    puts("");
    f(a,n);
}

void f(int a[],int n){
    
    int g_array[n][2];
    int k = 0;
    int abs_sum;
    int min_abs_sum = abs(a[0] + a[1]);//to get a starting value of min_abs_sum to start comparing.
    
    // to find the minimum absolute sum among the pair of elements in the array.
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ;j++){
                abs_sum = abs(a[i] + a[j]);
                if(min_abs_sum >= abs_sum){
                    min_abs_sum = abs_sum;
                }
        }
    }
    
    //adding all pairs with same minimum absolute sum to a new 2d array named g_array.
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ;j < n ;j++){
            abs_sum = abs(a[i]+a[j]);
            if(abs_sum == min_abs_sum){
                g_array[k][0] = a[i];
                g_array[k][1] = a[j];
                k++;
            }
        }
    }
    
    /* --to print all pairs with same absolute sum(ie,same distance from zero)--
    
    for(int i = 0 ; i < k ;i++){
       printf("[%d,%d] ",g_array[i][0],g_array[i][1]);
       
    */
    
    puts("");
    int abs_diff;
    int min_abs_diff = abs(abs(g_array[0][0]) - abs(g_array[0][1]));
    
    //finding minimum absolute difference among the pairs of elements in g_array.
    for(int i = 1 ; i < k ;i++){
        abs_diff = abs(abs(g_array[i][0]) - abs(g_array[i][1]));
        if(abs_diff <= min_abs_diff){
            min_abs_diff = abs_diff;
        }
    }
    
    //printing the first element from g_array whose abs_diff == min_abs_diff.
    for(int i = 0 ; i < k ;i++){
        if(abs_diff == min_abs_diff){
            printf("[%d,%d] ",g_array[i][0],g_array[i][1]);
            break;
        }
    }
    //to print all possible outputs.
    /*
    puts("");
    for(int i = 0 ; i < k ;i++){
        if(abs_diff == min_abs_diff){
            printf("[%d,%d] ",g_array[i][0],g_array[i][1]);
        }
    }
    */
    
}


























