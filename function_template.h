//#include <cmath>
#include <sstream>
#include <string.h>

using namespace std;

template <class TData, class TQueue>
int find_odd_max(TQueue queue, TData &max)
{
    bool k = false; // ���� ������� ��������� ����� � �������
    stringstream ss;
    TData Ttmp;
    string stmp;
    int itmp, symbol_dot = '.';
    while(!queue.isEmpty()) // ���� ������� �� �����
    {
        Ttmp = queue.DeQueue(); // ������ �� ������� �������
        itmp = static_cast<int>(Ttmp);
        ss << Ttmp; // ����������� ��� � ������
        ss >> stmp;
        if(strchr(stmp.c_str(), symbol_dot) || itmp & 1) // ���� � ����� ���� ����� ��� ��� ��������
        {
            max = Ttmp; // ���������� ����� ��� �������� ��������
                k = 1; // ����������, ��� ����� ���� �� ���� �������� �����
                break; // �������� ���������� �����, �.�. ����� ������ �����
        }
    }

    while(!queue.isEmpty()) // ���� ������� �� �����
    {
        Ttmp = queue.DeQueue(); // ������ �� ������� �������
        itmp = static_cast<int>(Ttmp);
        ss << Ttmp; // ����������� ����� � ������
        ss >> stmp;
        if((strchr(stmp.c_str(), symbol_dot) || itmp & 1) && Ttmp > max ) // ���� � ����� ���� �����
            max = Ttmp;
    }
    if(k) // ���� ����� ���� �� ���� �����
        return 1; // ����� ��������
    else 
        return 0; // �� �������� �����
}