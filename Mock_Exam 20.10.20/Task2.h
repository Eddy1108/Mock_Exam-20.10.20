#pragma once

struct Values
{
    char name{ ' ' };
    int value;
};

bool sortByValue(Values inst1, Values inst2) { return inst1.value < inst2.value; }

void generateValues(std::vector<Values>& array)
{
    array.at(0).name = 'A';     //Dont know how i would do this any easier, oops.
    array.at(1).name = 'B';
    array.at(2).name = 'C';
    array.at(3).name = 'D';
    array.at(4).name = 'E';
    array.at(5).name = 'F';
    array.at(6).name = 'G';
    array.at(7).name = 'H';
    array.at(8).name = 'I';
    array.at(9).name = 'J';
    for (int i = 0; i < 10; i++)
    {
        array.at(i).value = rand() % 20 + 1;    //assign random value between 1-20 for each element
    }
}

void task2()
{
    system("cls");
    std::vector<Values> values(10);     //initialize the vector with 10 Values
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    generateValues(values);
    int i = 0;
    while (i < 2) {
        std::cout << "No \tName \tValue \tHealth Bar \n-------------------------------------------------------------\n";
        for (int i = 0; i < values.size(); i++)
        {
            std::cout << i << "\t" << values.at(i).name << "\t" << values.at(i).value << "\t";
            for (int j = 0; j < values.at(i).value; j++)
            {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }

        std::sort(values.begin(), values.end(), sortByValue);     //sort the array based on the value.
        i++;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    system("pause");
}