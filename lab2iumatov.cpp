#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

// Задание 1
void task1() {
    deque<int> D = {1, 2, 3, 4, 5, 6, 7, 8};
    int half_size = D.size() / 2;

    cout << "Первая половина в обратном порядке: ";
    copy(D.rbegin() + half_size, D.rend(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    cout << "Вторая половина в обратном порядке: ";
    copy(D.rbegin(), D.rbegin() + half_size, ostream_iterator<int>(cout, " "));
    cout << "\n";
}

// Задание 2
void task2() {
    deque<int> D = {10, 20, 30, 40, 50};
    list<int> L = {100, 200, 300, 400, 500, 600, 700};

    auto insertdeque = L.end();
    advance(insertdeque, -5);
    L.insert(insertdeque, D.rbegin(), D.rbegin() + 5);


    cout << "Модифицированный список: ";
    for (int val : L) cout << val << " ";
    cout << "\n";
}

// Задание 3
void task3() {
    list<int> L = {10, 20, 30, 40, 50};
    vector<int> V = {5, 2};

    auto mid = next(L.begin(), L.size() / 2);

    V.push_back(*mid);
    L.erase(mid);

    cout << "Вектор после перемещения: ";
    for (int val : V) cout << val << " ";
    cout << "\n";
}

// Задание 4
void task4() {
    string name = "output.txt";
    vector<char> symbols = {'A', 'B', 'C', 'D'};

    ofstream fout(name);
    if (!fout) {
        cerr << "Ошибка открытия файла!\n";
        return;
    }

    transform(symbols.begin(), symbols.end(), ostream_iterator<int>(fout, " "), [](char c) {
        return static_cast<int>(c) * 2;
    });

    fout.close();
    cout << "Файл записан.\n";
}

// Задание 5
void task5() {
    list<int> L = {1, -2, 3, 4, -5, 6};

    auto first_negative = find_if(L.begin(), L.end(), [](int n) { return n < 0; });
    if (first_negative == L.end()) return;

    auto second_negative = find_if(next(first_negative), L.end(), [](int n) { return n < 0; });
    if (second_negative != L.end()) {
        L.erase(next(first_negative), second_negative);
    } else {
        L.erase(next(first_negative), L.end());
    }

    cout << "Модифицированный список: ";
    for (int val : L) cout << val << " ";
    cout << "\n";
}

// Задание 6
void task6() {
    list<int> L = {1, -2, 3, 4, -5, 6};
    auto half_it = next(L.begin(), L.size() / 2);

    list<int> result;
    remove_copy_if(half_it, L.end(), front_inserter(result), [](int n) { return n <= 0; });
    L.splice(L.begin(), result);

    cout << "Модифицированный список: ";
    for (int val : L) cout << val << " ";
    cout << "\n";
}

// Задание 7
void task7() {
    deque<string> D = {"ananas", "bananchik", "kokos", "citrus", "vinograd"};

    sort(D.begin(), D.end());
    cout << "Сортировка по алфавиту: ";
    for (const auto &word : D) cout << word << " ";
    cout << "\n";

    stable_sort(D.begin(), D.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    cout << "Сортировка по длине: ";
    for (const auto &word : D) cout << word << " ";
    cout << "\n";
}

// Задание 8
void task8() {
    list<string> L = {"ABC", "DEF", "KLM", "XYZ"};
    deque<string> D;

    
    adjacent_difference(L.begin(), L.end(), back_inserter(D), [](const string &left, const string &right) {
        return string(1, right[0]) + string(1, left.back());
    });

    // Удаляем первый элемент, так как adjacent_difference всегда добавляет начальный элемент
    D.erase(D.begin());

    // Выводим результат
    cout << "Дек: ";
    for (const auto &str : D) cout << str << " ";
    cout << "\n";
}


// Задание 9
void task9() {
    vector<int> V0 = {0, 1};
    vector<vector<int>> vectors = {{1, 2, 3}, {0, 1, 6}, {1, 2, 5, 6},{2,3,4},{0,5,1}};

    int count = 0;
    set<int> setV0(V0.begin(), V0.end());

    for (const auto &V : vectors) {
        set<int> setV(V.begin(), V.end());
        if (includes(setV.begin(), setV.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }

    cout << "Количество векторов, содержащих все элементы V0: " << count << "\n";
}


int main() {
    int choice;
    cout << "Выберите задание (1-9): ";
    cin >> choice;

    switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
    }

    return 0;
}