#pragma once

bool unlocked = false;
int lockAttempts = 3;
std::vector<char> password{ '1','4','5','2','3' };

bool compareVector(std::vector<char> array1, std::vector<char> array2)
{
    for (int i = 0; i < array1.size(); i++)
    {
        if (array1.at(i) != array2.at(i))
        {
            return false;
        }
    }
    return true;
}

void printVector(std::vector<char> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array.at(i) << " - ";
    }
}

void printBoard(char array[3][7])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << array[i][j];
        }
        std::cout << "\n";
    }
}

void lockScreen()
{
    std::vector<char> lockInput{};
    int posX{ 1 };
    int posY{ 0 };
    int moves{ 5 };
    char input{ ' ' };
    char lockBoard[3][7]
    {
        {'|', '1', '-', '2', '-', '3', '|'},
        {'|', '4', '-', '5', '-', '6', '|'},
        {'|', '7', '-', '8', '-', '9', '|'},
    };

    while (true) {
        system("cls");

        if (lockBoard[posY][posX] != '*')
        {
            moves--;
            lockInput.push_back(lockBoard[posY][posX]);
        }

        lockBoard[posY][posX] = '*';

        printBoard(lockBoard);
        std::cout << "Input: "; printVector(lockInput);
        std::cout << "\nMoves left: [" << moves << "]";
        std::cout << "\nAttempts left: [" << lockAttempts << "]\n";

        if (compareVector(lockInput, password) == true && moves == 0)
        {
            std::cout << "\n\nPASSWORD ACCEPTED...\n";
            system("pause");
            unlocked = true;
            break;
        }
        else if (moves == 0)
        {
            lockAttempts--;
            if (lockAttempts <= 0)
            {
                std::cout << "\n\nToo many attempts! Exiting program...";
                exit(0);
            }

            std::cout << "\n\nMoves exhausted, Restarting...\n";

            system("pause");
            break;
        }

        input = _getch();

        switch (input)
        {
        case 'W':
        case 'w':
            posY--;
            if (posY < 0)
            {
                posY = 0;
                moves++;
            }
            break;
        case 'A':
        case 'a':
            posX -= 2;
            if (posX < 0)
            {
                posX = 1;
                moves++;
            }
            break;
        case 'S':
        case 's':
            posY++;
            if (posY > 2)
            {
                posY = 2;
                moves++;
            }
            break;
        case 'D':
        case 'd':
            posX += 2;
            if (posX > 6)
            {
                posX = 6;
                moves++;
            }
            break;
        }

    }
}