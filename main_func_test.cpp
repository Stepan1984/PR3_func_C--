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
        cout << "����" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ����� ������������ ��������" << endl;
        cout << "3. �����" << endl;
        cin >> menu;
        cin.get();

        switch(menu)
        {
            case 1:
                input(d_queue, dtmp, 1); // ���� double
                input(u_queue, utmp, 0); // ���� unsigned
                break;
            case 2:
                if(d_queue.isEmpty()) // ���� ������� � ��-�� double �����
                    cout << "������� dQ ������" << endl;
                else
                    cout << "�������� �������� � dQ: " <<  (find_odd_max(d_queue, dtmp)? to_string(dtmp) : "dboba") << endl;
                if(u_queue.isEmpty()) // ���� ������� � ��-�� unsigned �����
                    cout << "������� uQ ������" << endl;
                else
                    cout << "�������� �������� � uQ: " << (find_odd_max(u_queue, utmp)? to_string(utmp) : "uboba") << endl;
                while(cin.get() != '\n');
                break;
            case 4: // ��� debug
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
    if(queue.isFull()) // ���� ������� ���������
    {
        cout << "������� ���������" << endl;
        while(cin.get() != '\n');
        return;
    }
    string input;
    char flag; 
    int i, length; 
    TData value;
    do
    {
        flag = 1; // ������������� ���� ������������ ����� 
        system("cls");
        cout << "������� " << (data_type? "double" : "unsigned int" ) << " : " << endl ;
        cin >> input; // ����������� ���� ����� 
        cin.get();
        length = input.length();
        if(!data_type && input[0] == '-' || input[0] != '-' && !isdigit(input[0])  ||  !input.compare("-0") ) // ���� unsigned � ������ ���� "-" ��� ������ ���� �� "-" � �� ����� ��� ����� "-0"  
        {
            cout << "������������ ��������, ��������� ������� " << endl;
            cout << "ENTER - ��� ���������� �����" << endl;
            flag = 0;
            while(cin.get() != '\n');
            continue; // ������� � ��������� �������� �����
        }
        
        if(length == 1)
            break;
            
        i = 1; // �������� ������� �� ������ ������� �� 2 �������
        while(input[i] != '\0') // ���� �� ����� ������
        {
            if(!isdigit(input[i]) && input[i] != '.') // ���� �� ����� � �� �����
            {
                cout << "������������ ��������, ��������� �������" << endl;
                cout << "ENTER - ��� ���������� �����" << endl;
                flag = 0;
                while(cin.get() != '\n');
                break; // ������� �� ����� ������� �� ������
            } 
            i++;
        }

    }while(!flag); // ���� ����� ����������� 

    stringstream ss;
    ss << input; // ����������� string 
    ss >> value; // � TData
    queue.EnQueue(value); // ��������� ������� � �������

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
