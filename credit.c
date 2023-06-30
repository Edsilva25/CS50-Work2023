#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Prompt the user for a credit card number
    long cardNumber = get_long("Number: ");

    // Variable to store the number of digits in the credit card number
    int numDigits = 0;

    // Variable to store the sum of the digits in the credit card number
    int sum = 0;

    // Variable to store the first two digits of the credit card number
    int firstTwoDigits = 0;

    // Variable to keep track of whether the card number is valid
    bool isValid = false;

    // Calculate the sum of the digits and the number of digits in the credit card number
    long temp = cardNumber;
    while (temp > 0)
    {
        // Get the last digit of the number
        int digit = temp % 10;

        // If it's an odd digit position, add it to the sum directly
        if (numDigits % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            // If it's an even digit position, multiply the digit by 2
            // and add the digits of the result to the sum
            int product = digit * 2;
            sum += product % 10 + product / 10;
        }

        // If this is the second to last iteration, store the first two digits of the card number
        if (temp < 100 && temp > 9)
        {
            firstTwoDigits = temp;
        }

        // Increment the number of digits and divide the number by 10 to remove the last digit
        numDigits++;
        temp /= 10;
    }

    // Check if the card number is valid and determine the card type
    if (sum % 10 == 0)
    {
        if (numDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
            isValid = true;
        }
        else if (numDigits == 16 && firstTwoDigits >= 51 && firstTwoDigits <= 55)
        {
            printf("MASTERCARD\n");
            isValid = true;
        }
        else if ((numDigits == 13 || numDigits == 16) && (firstTwoDigits / 10 == 4))
        {
            printf("VISA\n");
            isValid = true;
        }
    }

    // If the card number is not valid or the type couldn't be determined, print "INVALID"
    if (!isValid)
    {
        printf("INVALID\n");
    }

    return 0;
}