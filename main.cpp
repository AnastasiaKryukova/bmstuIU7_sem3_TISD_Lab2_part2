#include <iostream>


using namespace std;

class MyStack {
public:
    int size_stack; //Размер стека
     //Создаем указатель, который может хранить только адрес переменной типа int, но пока данный указатель не ссылается ни на какой объект и хранит случайное значение
    int *tail; //Указатель на последний входящий элемент - изменяется
    int *beginStk; //"Фиксированный" указатель на начало стека - не  двигается
    int *endStk; //"Фиксированный" указатель на конец стека - не двигается


    MyStack(int volume, int *ptail, int *pbegin, int *pend) //Инициализирует объект с размером очереди volume
    {

        int *Stk = new int[volume];
        ptail = Stk;
        pbegin = Stk;
        pend = pbegin + volume -1;

        size_stack = volume;
        tail = ptail;
        beginStk = pbegin;
        endStk = pend;

//        delete [] Que;
//        Que = nullptr;
//        beginQue = nullptr;
//        endQue = nullptr;
//        head = nullptr;
//        tail = nullptr;
    }

    ~MyStack() {}

    void PrintStk() // Печать адресов - проверка
    {
        cout << "begin = " << beginStk << "\n";
        cout << "tail = " << tail << "\n";
        cout << "end = " << endStk << "\n";
    }

    void PrStk() // Печать элементов - проверка
    {
        for (int i=0; i<size_stack; i++)
        {
            cout << *(beginStk+i) << "\n";
        }
    }

    bool push(int value) // Вставляет элемент в стек. Возвращает true, если операция прошла успешно
    {
        if(tail == beginStk && *tail == '\0') // Для первого элемента в очереди при первом вхождении
        {
            *tail = value;
        }

        else if(tail < endStk) // Ввод данных в очередь до его конца, включая последний элемент
        {
            tail++;
            *tail = value;
        }
        else if(tail == endStk)
        {
            cout << "You cannot add an element\n" << "Stack is full\n";
        }

        return true;
    }

    bool pop() // Удаляет элемент из стека. Возвращает true, если операция прошла успешно
    {
        if(*beginStk == '\0' && *tail == '\0')
            cout << "Stack is empty\n";

        else if(tail <= endStk)
        {
            *tail = '\0';
            tail--;
        }

        return true;
    }

    int Front() // Получает первый элемент из стека. Если стек пуст, возвращает -1
    {
        if(*beginStk == '\0')
        {
            cout << "Stack is empty\n";
            return -1;
        }

        return *beginStk;
    }

    int Rear() // Получает последний элемент из стека. Если стек пуст, возвращает -1
    {
        if(*beginStk == '\0')
        {
            cout << "Stack is empty\n";
            return -1;
        }

        return *endStk;
    }

    bool isEmpty() // Проверяет, пуст ли стек или нет
    {
        if(*beginStk == '\0')
        {
            cout << "Stack is empty\n";
            return -1;
        }
        cout << "Stack is NOT empty\n";
        return 1;
    }

    bool isFull() // Проверяет, заполнен ли стек или нет
    {
        if(*endStk != '\0')
        {
            cout << "Stack is full\n";
            return -1;
        }
        return 1;
    }

};


int main()
{
    int sz_stk{3};
    int ptrtail, ptrbegin, ptrend;
    MyStack Stack(sz_stk, &ptrtail, &ptrbegin, &ptrend); //Создание объекта класса с размером стека
    int x;

    cout << "1 - печать указателей\n" << "2 - печать элементов\n" << "3 - ввод элементов\n";
    cout << "4 - удаление элементов\n" << "5 - печать первого элемента стека\n" << "6 - печать последнего элемента стека\n";
    cout << "7 - проверка пустоты стека\n" << "8 - проверка заполненности стека\n";
    cout << "\vВведите номер операции = ";

    while(cin>>x)
    {
        switch(x)
        {
            case 1:
            {
                Stack.PrintStk();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 2:
            {
                Stack.PrStk();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 3:
            {
                int value_input;
                cout << "\vВведите элемент = ";
                cin >> value_input;
                Stack.push(value_input);
                cout << "\vВведите номер операции = ";
                break;
            }
            case 4:
            {
                Stack.pop();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 5:
            {
                Stack.Front();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 6:
            {
                Stack.Rear();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 7:
            {
                Stack.isEmpty();
                cout << "\vВведите номер операции = ";
                break;
            }
            case 8:
            {
                Stack.isFull();
                cout << "\vВведите номер операции = ";
                break;
            }
            default:
            {
                cout << "Ошибка ввода\n";
                cout << "\vВведите номер операции = ";
                break;
            }
        }
    }


    return 0;
}

