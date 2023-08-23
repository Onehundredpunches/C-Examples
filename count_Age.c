#include <stdio.h>

int presentYear = 2023;

int calculateAge() {
    int age, birthYear;
    printf("Enter your bitrhyear: ");
    scanf("%d", &birthYear);

    age = presentYear - birthYear;

    printf("Your age is: %d years old \n", age);

    return age;
}


int main() {
    calculateAge();

    return 0;
}