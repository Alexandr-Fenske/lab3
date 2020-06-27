#include "myinput.h"
#include <iostream>

vector<double> input_numbers(size_t count) // функция ввода чисел
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

