//Password generator
#include <iostream>
#include <ctime>
#include <string>

int main()
{
    srand(time(0));
    std::cout << "\t\t\tPassword generator\n\n";

    std::string choice;

    do
    {
        std::cout << "Choose and enter your choice (1 - easy, 2 - medium, 3 - hard): ";
        std::getline(std::cin, choice);

        if (choice != "1" && choice != "2" && choice != "3")
        {
            std::cout << "\nIncorrect input! Try again.\n\n";
        }

    } while (choice != "1" && choice != "2" && choice != "3");

    std::string password = "";

    if (choice == "1")
    {
        for (int i = 0; i < 4; ++i)
        {
            password += std::to_string(rand() % 10);
        }
    }
    else if (choice == "2")
    {
        bool isNumber;

        for (int i = 0; i < 8; ++i)
        {
            isNumber = rand() % 2;

            if (isNumber)
            {
                password += std::to_string(rand() % 10);
            }
            else
            {
                bool isLittle;
                isLittle = rand() % 2;

                if (isLittle)
                {
                    password += static_cast<char>(rand() % 26 + 97);
                }
                else
                {
                    password += static_cast<char>(rand() % 26 + 65);
                }
            }
        }
    }
    else
    {
        int symbol;

        for (int i = 0; i < 16; ++i)
        {
            symbol = rand() % 3;

            if (symbol == 0)
            {
                password += std::to_string(rand() % 10);
            }
            else if (symbol == 1)
            {
                bool isLittle;
                isLittle = rand() % 2;

                if (isLittle)
                {
                    password += static_cast<char>(rand() % 26 + 97);
                }
                else
                {
                    password += static_cast<char>(rand() % 26 + 65);
                }
            }
            else
            {
                int group = rand() % 4;

                if (group == 0)
                {
                    password += static_cast<char>(rand() % 15 + 33);
                }
                else if (group == 1)
                {
                    password += static_cast<char>(rand() % 7 + 58);
                }
                else if (group == 2)
                {
                    password += static_cast<char>(rand() % 6 + 91);
                }
                else
                {
                    password += static_cast<char>(rand() % 4 + 123);
                }
            }
        }
    }

    std::cout << "\nYour password is " << password << '\n';

    return 0;
}