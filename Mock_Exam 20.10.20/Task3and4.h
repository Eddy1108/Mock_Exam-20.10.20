#pragma once

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

void task3(bool task4 = false)
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

    if (task4 == true) {
        addRandomPellets(gameBoard);     //adds random pellets
    }

    while (true) {
        system("cls");
        gameBoard[lastY][lastX] = ' ';              //remove player from previous position
        gameBoard[currentY][currentX] = 'E';        //update the player on the board
        printGameBoard(gameBoard);                  //then print it
        std::cout << "Points: [" << points << "] \nPress [Q] to Quit";

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
        case 'Q':
        case 'q':
            return;
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