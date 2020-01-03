# CABC

#### arry

```c
int luckyNumber[] = {4, 3, 9, 2, 75}; //第一种
int luckyNumber[10]; //
char phrase[20] = "Array"; //

printf("%d, %s", luckyNumber[0],phrase[19])
```

```c
int main()
{
    sayHi("Mike", 40);
    return 0;
}
void sayHi(char name[], int age){
    printf("Hello %s, you are %d\n", name, age);
}
```

```c
#include <stdio.h>
#include <stdlib.h>

double cube(double num){
    double result = num * num * num;
    return result;
    printf("Hi, there");
}
int main(){
    printf("Answer: %f", cube(3.0));
    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[30];
    char major[30];
    int age;
    double gpa;
};

int main(){
    
    struct Student student1;
    sutdent1.age = 22;
    sutdent1.gpa = 3.2;
    strcpy( student1.name, "Jim");
    strcpy( student1.major, "Business");
    
    printf("%s %d %s %f",student.name, student.age, student.major, student.gpa)
}
```

```c
int main(){
    
    int secretNumber = 8;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;
    
    while(guess != secretNumber && outOfGuesses == 0){
        if(guessCount < guessLimit){
            printf("Enter a number: ");
            scanf("%d", &guess);
            guessCount++;
        } else {
            outOfGuess = 1;
        }
    }
    if(outOfGuesses == 1){
        printf("Out of guesses");
    } else {
        printf("You Win!");
    }
}
```

