#include <iostream>
#include <typeinfo>

using namespace std;

template <class Tdata>
class VectorQueue
{
    private:
        int head, tail; // индексы головы и хвоста
        int maxLength; // размер массива
        Tdata * data; // указатель на массив данных
    public:
        VectorQueue(int n = 10): maxLength(n) // конструктор
        {
            data = new Tdata[maxLength]; // создаём массив
            head = 0;
            tail = head - 1;
        }

        VectorQueue(const VectorQueue &other) // конструктор копирования
        {
            this->head = other.head;
            this->tail = other.tail;
            this->maxLength = other.maxLength;
            this->data = new Tdata[other.maxLength]; // выделяем память под массив того же размера
            for(int i = 0; i < maxLength; i++)
            {
                this->data[i] = other.data[i];
            }
        }

        ~VectorQueue() // деструктор
        {
            delete[] data;
        }

        int isEmpty() // проверка на пустоту
        {
            return (tail + 1) % maxLength == head;
        }

        int isFull() // проверка полноты
        {
            return (tail + 2) % maxLength == head; 
        }

        Tdata getHead() // неразрушающее чтение из головы очереди
        {
            if(isEmpty())
                return 0;
            return data[head];
        }

        int EnQueue(Tdata x) // добавить элемент в очередь
        {
            if (isFull()) // если очередь заполнена 
                return 0;
            tail = (tail + 1) % maxLength; // увеличиваем индекс последнеги элемента
            data[tail] = x; // сохраняем данные в ячейку массива
            return 1;
        }

        Tdata DeQueue() // извлечение элемента из головы очереди
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
        } *head, * tail; //индексы головы и хвоста
    public:
        ListQueue() // конструктор
        {
            head = tail = NULL;
        }

        ListQueue(const ListQueue &other) // конструктор копирования
        {
            item * other_node = other.head;
            while(other_node) // если копируемый стек не пуст
                this->EnQueue(other_node->data); // добавляем элементы в новую очередь
        }


        ~ListQueue() // деструктор
        {
            while(head)
                this->DeQueue();
        }

        int isEmpty() // проверка на пустоту
        {
            return head == NULL;
        }

        int isFull() // проверка полноты
        { // не заполнена, если можно выделить память под ещё хотя бы один элемент
            item * temp = new (nothrow) item; // nothrow - сообщает компилятору, что и объявленная функция, и функции, которые она вызывает, никогда не создают исключений.
            if(temp == NULL) 
                return 1;
            delete temp;
            return 0; 
        }

        Tdata getHead() // неразрушающее чтение из головы очереди
        {
            if(isEmpty())
                return 0;
            return head->data;
        }

        int EnQueue(Tdata x) // добавить элемент в очередь
        {
            item * temp = new (nothrow) item; // выделяем память под новый узел
            if(temp == NULL)
                return 0;
            temp->data = x; // сохраняем данные в узел списка
            temp->next = NULL;
            if(isEmpty()) // если список пустой
                head = tail = temp;
            else // если не пустой
            {
                tail->next = temp;
                tail = tail->next;
            }
            return 1;
        }

        Tdata DeQueue() // извлечение элемента из головы очереди
        {
            if(isEmpty()) // если список пустой
                return 0;
            Tdata temp = head->data; // сохраняем данные во временную переменную
            item * tmp = head; // запоминаем указатель на голову списка
            if(head == tail)
                tail = head = NULL;
            else
                head = head->next;
            delete tmp; // удаляем узел головы списка
            return temp; // возвращаем значение из списка
        }
};
