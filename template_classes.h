#include <iostream>
#include <typeinfo>

using namespace std;

template <class Tdata>
class VectorQueue
{
    private:
        int head, tail; // ������� ������ � ������
        int maxLength; // ������ �������
        Tdata * data; // ��������� �� ������ ������
    public:
        VectorQueue(int n = 10): maxLength(n) // �����������
        {
            data = new Tdata[maxLength]; // ������ ������
            head = 0;
            tail = head - 1;
        }

        VectorQueue(const VectorQueue &other) // ����������� �����������
        {
            this->head = other.head;
            this->tail = other.tail;
            this->maxLength = other.maxLength;
            this->data = new Tdata[other.maxLength]; // �������� ������ ��� ������ ���� �� �������
            for(int i = 0; i < maxLength; i++)
            {
                this->data[i] = other.data[i];
            }
        }

        ~VectorQueue() // ����������
        {
            delete[] data;
        }

        int isEmpty() // �������� �� �������
        {
            return (tail + 1) % maxLength == head;
        }

        int isFull() // �������� �������
        {
            return (tail + 2) % maxLength == head; 
        }

        Tdata getHead() // ������������� ������ �� ������ �������
        {
            if(isEmpty())
                return 0;
            return data[head];
        }

        int EnQueue(Tdata x) // �������� ������� � �������
        {
            if (isFull()) // ���� ������� ��������� 
                return 0;
            tail = (tail + 1) % maxLength; // ����������� ������ ���������� ��������
            data[tail] = x; // ��������� ������ � ������ �������
            return 1;
        }

        Tdata DeQueue() // ���������� �������� �� ������ �������
        {
            if(isEmpty())
                return 0;
            int temp = head;
            head = (head + 1) % maxLength;
            return data[temp];
        }

};

template <class Tdata>
class ListQueue
{
    private:
        struct item
        {
            Tdata data;
            item * next;
        } *head, * tail; //������� ������ � ������
    public:
        ListQueue() // �����������
        {
            head = tail = NULL;
        }

        ListQueue(const ListQueue &other) // ����������� �����������
        {
            item * other_node = other.head;
            while(other_node) // ���� ���������� ���� �� ����
                this->EnQueue(other_node->data); // ��������� �������� � ����� �������
        }


        ~ListQueue() // ����������
        {
            while(head)
                this->DeQueue();
        }

        int isEmpty() // �������� �� �������
        {
            return head == NULL;
        }

        int isFull() // �������� �������
        { // �� ���������, ���� ����� �������� ������ ��� ��� ���� �� ���� �������
            item * temp = new (nothrow) item; // nothrow - �������� �����������, ��� � ����������� �������, � �������, ������� ��� ��������, ������� �� ������� ����������.
            if(temp == NULL) 
                return 1;
            delete temp;
            return 0; 
        }

        Tdata getHead() // ������������� ������ �� ������ �������
        {
            if(isEmpty())
                return 0;
            return head->data;
        }

        int EnQueue(Tdata x) // �������� ������� � �������
        {
            item * temp = new (nothrow) item; // �������� ������ ��� ����� ����
            if(temp == NULL)
                return 0;
            temp->data = x; // ��������� ������ � ���� ������
            temp->next = NULL;
            if(isEmpty()) // ���� ������ ������
                head = tail = temp;
            else // ���� �� ������
            {
                tail->next = temp;
                tail = tail->next;
            }
            return 1;
        }

        Tdata DeQueue() // ���������� �������� �� ������ �������
        {
            if(isEmpty()) // ���� ������ ������
                return 0;
            Tdata temp = head->data; // ��������� ������ �� ��������� ����������
            item * tmp = head; // ���������� ��������� �� ������ ������
            if(head == tail)
                tail = head = NULL;
            else
                head = head->next;
            delete tmp; // ������� ���� ������ ������
            return temp; // ���������� �������� �� ������
        }
};
