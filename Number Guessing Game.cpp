#include <iostream>
#include <string>

int main()
{
    // Define/Clarify Variables.
    bool bIsRunning = true;
    std::string input = "";
    int guessCount = 0;
    int minNumber = 0;
    int maxNumber = 0;
    int randomNumber = 0;

    while (bIsRunning)
    {
        // Displays/Outputs Instructions & Waits For User Input.
        std::cout << "***Number guessing game***\n";
        std::cout << "\nEnter the number of guesses: ";
        getline(std::cin, input);
        guessCount = std::stoi(input);

        std::cout << "Enter the miniumum number: ";
        getline(std::cin, input);
        minNumber = std::stoi(input);

        std::cout << "Enter the maximum number: ";
        getline(std::cin, input);
        maxNumber = std::stoi(input);

        // Generates Random Number Within The Range.
        srand((unsigned)time(0));
        randomNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

        // Processes Users Guesses.
        for (int i = 0; i < guessCount; ++i)
        {
            int guess = 0;

            std::cout << "\nEnter your guess: ";
            getline(std::cin, input);
            guess = std::stoi(input);

            if (guess == randomNumber)
            {
                std::cout << "Well done, you guessed the number!\n";
                break;
            }

            int guessesRemaining = guessCount - (i + 1);
            std::cout << "Your guess was too " << (guess < randomNumber ? "low. " : "high. ");
            std::cout << "You have " << guessesRemaining << (guessesRemaining > 1 ? " guesses" : " guess") << " remaining";
        }

        // Waits for Users Input To Close Application With Zero/0
        std::cout << "\nEnter 0 to exit, or any number to play again: ";
        getline(std::cin, input);
        if (std::stoi(input) == 0)
        {
            bIsRunning = false;
        }
    }
}