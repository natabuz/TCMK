#include "lint.h"

void Exit()
{
    cout << "Для выхода нажмите Enter..." << endl;

    cin.get();

    exit(-1);
}

int main(int argc, char* argv[]) 
{
     setlocale(LC_ALL, "Russian");
	
     if(argc != 5 && argc != 6) 
     {
		cout << "Неверно заданы параметры командной строки("<< argc <<")!" << endl;
        Exit();
     }
    
    char *file_name_1 = argv[1];
    char *file_name_2 = argv[3];
    char *file_name_3 = argv[4];
    char operation = argv[2][0];

    bool binary = false;
    Lint a, b, c;
    string result, num1, num2;
    
    if (argc == 5)
    {
        num1 = a.read(file_name_1);
        num2 = b.read(file_name_2);
        a = num1;
        b = num2;
    }
    else
    {
        binary = true;

        a = a.binread(file_name_1);
        b = b.binread(file_name_2);
    }
    
    switch (operation)
    {
    case '+':
        c = a + b;
        result = c.trim().toString();
        break;
    case '-':
        c = a - b;
        result = c.trim().toString();
        break;
    case '*':
        c = a * b;
        result = c.trim().toString();
        break;
    case '/':
        if (b == Lint("0"))
        {
            cout << "Деление на 0 невозможно!" << endl;
            Exit();
        }
        else
        {
            c = a / b;
            result = c.trim().toString();
        }
        break;
    case '%':
        if (b == Lint("0"))
        {
            cout << "Деление на 0 невозможно!" << endl;
            Exit();
        }
        else
        {
            c = a % b;
            result = c.trim().toString();
        }
        break;
    case '^':
        if (b.isNegative())
        {
            cout << "Степень не может быть отрицательной!" << endl;
            Exit();
        }
        else
        {
            c = a ^ b;
            result = c.trim().toString();
        }
        break;
    default:
        cout << "Неверная операция!" << endl;
        Exit();
    }
	
    if (binary == false)
    {
        c.write(result, file_name_3);
    }
    else
    {
        c.binwrite(c, file_name_3);
    }
	
    return 0;
}