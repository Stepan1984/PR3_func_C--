//#include <cmath>
#include <sstream>
#include <string.h>

using namespace std;

template <class TData, class TQueue>
int find_odd_max(TQueue queue, TData &max)
{
    bool k = false; // флаг наличия нечётного числа в очереди
    stringstream ss;
    TData Ttmp;
    string stmp;
    int itmp, symbol_dot = '.';
    while(!queue.isEmpty()) // пока очередь не пуста
    {
        Ttmp = queue.DeQueue(); // достаём из очереди элемент
        itmp = static_cast<int>(Ttmp);
        ss << Ttmp; // преобразуем его в строку
        ss >> stmp;
        if(strchr(stmp.c_str(), symbol_dot) || itmp & 1) // если в числе есть точка или оно нечётное
        {
            max = Ttmp; // запоминаем число как нечётный максимум
                k = 1; // запоминаем, что нашли хотя бы одно нечётное число
                break; // перываем выполнение цикла, т.к. нашли первое число
        }
    }

    while(!queue.isEmpty()) // пока очередь не пуста
    {
        Ttmp = queue.DeQueue(); // достаём из очереди элемент
        itmp = static_cast<int>(Ttmp);
        ss << Ttmp; // преобразуем число в строку
        ss >> stmp;
        if((strchr(stmp.c_str(), symbol_dot) || itmp & 1) && Ttmp > max ) // если в числе есть точка
            max = Ttmp;
    }
    if(k) // если нашли хотя бы одно число
        return 1; // поиск успешный
    else 
        return 0; // не успешный поиск
}