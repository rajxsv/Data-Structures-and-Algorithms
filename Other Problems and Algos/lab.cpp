#include <stdio.h>

int main()
{
    FILE *input;
    input = fopen("input.txt", "r");
    struct student
    {
        char name[30];
        int rollNo;
        int cgpa;
        char address[100];
    };
    struct student arr[20];
    for (int i = 1; i <= 20; i++)
    {
        fscanf(input, "%s %d %d %s", &(arr[i].name), &(arr[i].rollNo), &(arr[i].cgpa), &(arr[i].address));
    }
    for (int i = 1; i <= 20; i++)
    {
        printf("%s %d %d %s\n", arr[i].name, arr[i].rollNo, arr[i].cgpa, arr[i].address);
        
    }
    
    fclose(input);
    return 0;
}