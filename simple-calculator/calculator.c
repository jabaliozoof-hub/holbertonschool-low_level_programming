#include <stdio.h>

/**
 * main - Entry point of the simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int choice;

    printf("Simple Calculator\n");
    
    do {
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Adding...\n");
                break;
            case 2:
                printf("Subtracting...\n");
                break;
            case 3:
                printf("Multiplying...\n");
                break;
            case 4:
                printf("Dividing...\n");
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return (0);
}
