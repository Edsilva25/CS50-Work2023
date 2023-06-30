#include <cs50.h>
#include <stdio.h>

int main(void)
// Asking for the name.
{
    string name = get_string("What's your name? ");
    // Printing the name
    printf("hello, %s\n", name);
}