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
#include "Task3and4.h"

char menuInput{ ' ' };

int main()
{
    while (unlocked == false) 
    {
    lockScreen();
    }
    
    while (true) 
    {
        system("cls");
        std::cout << "Welcome to the menu! \nPlease select a task: \nTask[1]: Dice \nTask[2]: Random Values \nTask[3]: Pac-Man \nTask[4]: Pac-Man with Pellets \nQuit[5]\n";
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
            task3(true);
            break;
        case '5':
            std::cout << "\nGoodbye!\n";
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