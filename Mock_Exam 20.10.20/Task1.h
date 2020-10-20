#pragma once
void task1()
{
    system("cls");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int one{ 0 };
    int two{ 0 };
    int three{ 0 };
    int four{ 0 };
    int five{ 0 };
    int six{ 0 };
    int temp{ 0 };
    std::cout << "Throwing 2000 dice...\n";

    for (int i = 0; i < 2000; i++)
    {
        temp = rand() % 6 + 1;
        switch (temp)
        {
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        case 3:
            three++;
            break;
        case 4:
            four++;
            break;
        case 5:
            five++;
            break;
        case 6:
            six++;
            break;
        }
    }
    std::cout << "Results: \nOnes: \t" << one << " times \nTwos: \t" << two << " times \nThrees: " << three << " times \nFours: \t" << four << " times \nFives: \t" << five << " times \nSixes: \t" << six << " times" << std::endl;
    system("pause");

}