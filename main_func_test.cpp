#include "function_template.h"
#include "template_classes.h"
#include <iostream>

#include <sstream>


using namespace std;

template <class TQueue, class TData>
void input(TQueue &, TData &, bool );

int main(void)
{
    setlocale(LC_ALL, "Rus");
    VectorQueue<double> d_queue;
    VectorQueue<unsigned> u_queue;
    double dtmp;
    unsigned utmp;



    int menu;
    do
    {
        system("cls");
        cout << "Меню" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Найти максимальный нечётный" << endl;
        cout << "3. Выход" << endl;
        cin >> menu;
        cin.get();

        switch(menu)
        {
            case 1:
                input(d_queue, dtmp, 1); // ввод double
                input(u_queue, utmp, 0); // ввод unsigned
                break;
            case 2:
                if(d_queue.isEmpty()) // если очередь с эл-ми double пуста
                    cout << "Очередь dQ пустая" << endl;
                else
                    cout << "Нечётный максимум в dQ: " <<  (find_odd_max(d_queue, dtmp)? to_string(dtmp) : "dboba") << endl;
                if(u_queue.isEmpty()) // если очередь с эл-ми unsigned пуста
                    cout << "Очередь uQ пустая" << endl;
                else
                    cout << "Нечётный максимум в uQ: " << (find_odd_max(u_queue, utmp)? to_string(utmp) : "uboba") << endl;
                while(cin.get() != '\n');
                break;
            case 4: // для debug
                cout << d_queue.getHead() << endl;
                cout << u_queue.getHead() << endl;
                while(cin.get() != '\n');
        }
    }while(menu != 3);

    return 0;
}

template <class TQueue, class TData>
void input(TQueue &queue, TData &tmp, bool data_type)
{
    if(queue.isFull()) // если очередь заполнена
    {
        cout << "Очередь заполнена" << endl;
        while(cin.get() != '\n');
        return;
    }
    string input;
    char flag; 
    int i, length; 
    TData value;
    do
    {
        flag = 1; // устанавливаем флаг корректности числа 
        system("cls");
        cout << "Введите " << (data_type? "double" : "unsigned int" ) << " : " << endl ;
        cin >> input; // запрашиваем ввод числа 
        cin.get();
        length = input.length();
        if(!data_type && input[0] == '-' || input[0] != '-' && !isdigit(input[0])  ||  !input.compare("-0") ) // если unsigned и первый знак "-" или первый знак не "-" и не цифра или ввели "-0"  
        {
            cout << "Некорректное значение, повторите попытку " << endl;
            cout << "ENTER - для повторного ввода" << endl;
            flag = 0;
            while(cin.get() != '\n');
            continue; // переход к следующей итерации цикла
        }
        
        if(length == 1)
            break;
            
        i = 1; // итератор прохода по строке начиная со 2 символа
        while(input[i] != '\0') // пока не конец строки
        {
            if(!isdigit(input[i]) && input[i] != '.') // если не цифра и не точка
            {
                cout << "Некорректное значение, повторите попытку" << endl;
                cout << "ENTER - для повторного ввода" << endl;
                flag = 0;
                while(cin.get() != '\n');
                break; // выходим из цикла прохода по строке
            } 
            i++;
        }

    }while(!flag); // пока число некорректно 

    stringstream ss;
    ss << input; // преобразуем string 
    ss >> value; // в TData
    queue.EnQueue(value); // добавляем элемент в очередь

    return;
}

template<class T>
string to_string(T value)
{
    string stmp;
    stringstream ss;
    ss << value;
    ss >> stmp;
    return stmp;
}
