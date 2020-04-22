#include <stdio.h>
#include <string.h>
int main(void) {
    char a[50];
    printf("Input a: ");
    gets(a);
    int count = 0;
    while(a[count] == '#'){
            count++;
    }printf("The number of #:%d\n",count);
    if(count < 4){
        printf("%s\n",a);
    }else{
        strcpy(a,a+count-3);
        printf("%s\n",a);
    }
	return 0;
}
