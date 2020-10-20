#pragma once

bool unlocked = true;
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