// Mock_Exam 20.10.20.cpp

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "LockScreen.h"
#include "Task1.h"
#include "Task2.h"

char menuInput{ ' ' };

void printGameBoard(char array[11][21]) 
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}

void addRandomPellets(char array[11][21]) 
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (j % 2 == 0) {   //skip the invalid spaces
                j++;
            }
            if (array[i][j] == ' ') 
            {
                int temp = rand() % 10 + 1;
                if (temp % 2 == 0)      //50% of the empty spaces should get pellets
                {
                    array[i][j] = '-';
                }
            }
        }
    }
}

void task3() 
{
    system("cls");
    int currentX{ 1 };
    int currentY{ 1 };
    int lastX{ 1 };
    int lastY{ 1 };
    int points{ 0 };
    char pInput{ ' ' };
    char gameBoard[11][21]
    {
        {'|', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '|'},
        {'|', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '|'},
        {'|', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '|'},
    };

    addRandomPellets(gameBoard);     //adds random pellets

    while (true) {
        system("cls");
        gameBoard[lastY][lastX] = ' ';              //remove player from previous position
        gameBoard[currentY][currentX] = 'E';        //update the player on the board
        printGameBoard(gameBoard);                  //then print it
        std::cout << "Points: [" << points << "]";

        pInput = _getch();

        lastX = currentX;
        lastY = currentY;
        switch (pInput)
        {
        case 'W':
        case'w':
            currentY--;
            break;
        case 'A':
        case 'a':
            currentX -= 2;
            break;
        case 'S':
        case 's':
            currentY++;
            break;
        case 'D':
        case 'd':
            currentX += 2;
            break;
        }

        if (gameBoard[currentY][currentX] == '#' || gameBoard[currentY][currentX] == '|') 
        {
            currentX = lastX;
            currentY = lastY;
        }

        if (gameBoard[currentY][currentX] == '-') 
        {
            points += 5;
        }
    }
    
    system("pause");
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

int main()
{
    while (unlocked == false) 
    {
    lockScreen();
    }
    
    while (true) 
    {
        system("cls");
        std::cout << "Welcome to the menu! \nPlease select a task: \nTask[1] \nTask[2] \nTask[3] \nTask[4] \nQuit[5]\n";
        std::cin >> menuInput;
        switch (menuInput)
        {
        case '1':
            task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            task3();
            break;
        case '4':
            break;
        case '5':
            std::cout << "\n\nGoodbye!";
            return 0;
            break;
        default:
            std::cout << "\n\nWrong input... Do you want to try again? (Y/N) ";
            std::cin >> menuInput;
            if (menuInput == 'N' || menuInput == 'n') 
            {
                return 0;
            }
            break;
        }
    }
    system("pause");
}