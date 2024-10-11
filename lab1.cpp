#include <stdio.h>
#include <iostream>
using namespace std;

double fraction(double x) {
    return x - int(x);
}
bool isPositive(int x) {
    return x > 0;
}
bool is2Digits(int x) {
    return x >= 10 && x <= 99 or x <= -10 && x >= -99;
}
bool isDivisor(int a, int b) {
    return (a != 0 && b % a == 0) or (b != 0 && a % b == 0);
}
bool isEqual(int a, int b, int c){
    return a == b && b == c && a == c;
}
int abs(int x) {
    return (x < 0) ? -x : x;
}
double safeDiv(int x, int y) {
    if (y == 0) {
        return 0.0;
    }
    return double(x) / y;
}

bool is35(int x) {
    return (x % 3 == 0 && x % 5 != 0) || (x % 5 == 0 && x % 3 != 0);
}

string makeDecision(int x, int y) {
    // Сравнение x и y и формирование строки результата
    if (x > y) {
        return to_string(x) + " > " + to_string(y);
    } else if (x < y) {
        return to_string(x) + " < " + to_string(y);
    } else {
        return to_string(x) + " == " + to_string(y);
    }
}

string day(int x) {
    switch (x) {
        case 1:
            return "ponedelnik";
        case 2:
            return "vtornik";
        case 3:
            return "sreda";
        case 4:
            return "chetverg";
        case 5:
            return "pyatnica";
        case 6:
            return "subbota";
        case 7:
            return "voskresenye";
        default:
            return "not a day of the week";
    }
}

string listNums(int x) {
    string result = "";
    for (int i = 0; i <= x; ++i) {
        result += to_string(i);
        if (i < x) {
            result += " ";
        }
    }
    return result;
}

string reverseListNums(int x) {
    string result = "";
    for (int i = x; i >= 0; --i) {
        result += to_string(i);
        if (i > 0) {
            result += " ";
        }
    }
    return result;
}

int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

string chet(int x) {
    string result = "";
    for (int i = 0; i <= x; i += 2) {  // Шаг цикла 2, чтобы обрабатывать только четные числа
        result += to_string(i);   // Добавляем текущее четное число к строке
        if (i + 2 <= x) {
            result += " ";  // Добавляем пробел, если следующее число тоже четное и входит в диапазон
        }
    }
    return result;
}


int numLen(long x) {
    int length = 0;
    if (x == 0) {
        return 1; // Если число равно 0, то количество знаков 1
    }
    if (x < 0) {
        x = -x; // Если число отрицательное, делаем его положительным
    }
    while (x > 0) {
        x /= 10;  // Уменьшаем число, удаляя последнюю цифру
        length++; // Увеличиваем счетчик количества цифр
    }
    return length;
}

int findFirst(int arr[], int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            return i; // Возвращаем индекс первого вхождения
        }
    }
    return -1; // Если число не найдено, возвращаем -1
}

int main() {
    int choice1, choice2;
    cout << "Выберите действие:\n";
    cout << "1. Блок 'Методы'\n";
    cout << "2. Блок 'Условия'\n";
    cout << "3. Блок 'Циклы'\n";
    cin >> choice1;
    switch (choice1) {
        case 1: {
            cout << "Выберите действие:\n";
            cout << "1. Задача 1 Дробная часть числа\n";
            cout << "2. Задача 4 Проверка на положительность числа\n";
            cout << "3. Задача 5 Проверка, является ли число двузначным\n";
            cout << "4. Задача 8 Делитель\n";
            cout << "5. Задача 9 Равенство\n";
            cin >> choice2;
            switch (choice2) {
                case 1: {
                    double x;
                    cout << "Введите вещественное число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Drobnaya chast' chisla: " << fraction(x) << endl;
                    break;
                }
                case 2: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    if (isPositive(x)) {
                        cout << "true";
                    } else {
                        cout << "false";
                    }
                    break;
                }
                case 3: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    if (is2Digits(x)) {
                        cout << "true";
                    } else {
                        cout << "false";
                    }
                    break;
                }
                case 4: {
                    int a, b;
                    cout << "Введите 2 числа: ";
                    while (!(cin >> a >> b)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    if (isDivisor(a, b)) {
                        cout << "true";
                    } else {
                        cout << "false";
                    }
                    break;
                }
                case 5: {
                    int a, b, c;
                    cout << "Введите 3 числа: ";
                    while (!(cin >> a >> b >> c)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    if (isEqual(a, b, c)) {
                        cout << "true";
                    } else {
                        cout << "false";
                    }
                }
                    break;
            }
            break;
        }
        case 2: {
            cout << "Выберите действие:\n";
            cout << "1. Задача 1 Модуль числа \n";
            cout << "2. Задача 2 Безопасное деление.\n";
            cout << "3. Задача 3 Тридцать пять\n";
            cout << "4. Задача 4 Строка сравнения. \n";
            cout << "5. Задача 9 День недели. \n";
            cin >> choice2;
            switch (choice2) {
                case 1: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Modul' chisla: " << abs(x) << endl;
                }
                    break;
                case 2: {
                    int x, y;
                    cout << "Введите два числа: ";
                    while (!(cin >> x >> y)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Результат деления: " << safeDiv(x, y);
                    break;
                }
                case 3: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    if (is35(x)) {
                        cout << "true";
                    } else {
                        cout << "false";
                    }
                    break;
                }
                case 4: {
                    int x, y;
                    cout << "Введите 2 числа: ";
                    while (!(cin >> x >> y)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "result " << makeDecision(x, y);
                    break;
                }
                case 5: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "День недели " << day(x);
                    break;
                }

            }
            break;
        }
        case 3: {
            cout << "Выберите действие:\n";
            cout << "1. Задание 1 Числа подряд\n";
            cout << "2. Задание 2 Числа наоборот\n";
            cout << "3. Задание 4 Степень числа\n";
            cout << "4. Задание 3 Четные числа\n";
            cout << "5. Задание 5 Длина числа\n";
            cin >> choice2;
            switch (choice2) {
                case 1: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Числа от 1 до x: " << listNums(x) << endl;
                }
                    break;
                case 2: {
                    int x, y;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Числа от х до 1: " << reverseListNums(x);
                    break;
                }
                case 3: {
                    int x, y;
                    cout << "Введите 2 числа: ";
                    while (!(cin >> x >> y)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Числа в степени равно: " << pow(x, y);
                    break;
                }
                case 4: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Четные числа от 0 до х равны: " << chet(x);
                    break;
                }
                case 5: {
                    int x;
                    cout << "Введите число: ";
                    while (!(cin >> x)) {
                        cout << "Error. Try again";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Длина числа " << numLen(x);
                    break;
                }

            }
            break;
        }
    }
}