#include <iostream>

using namespace std;

class LineSegment {
private:
    double x, y;

public:
    // Конструкторы
    LineSegment() : x(0), y(1) {}
    LineSegment(double start, double end) : x(start), y(end) {
        if (x > y) {
            swap(x, y);
        }
    }
    LineSegment(const LineSegment& other) : x(other.x), y(other.y) {}

    // Перегрузка оператора вывода для отображения отрезка
    friend ostream& operator<<(ostream& os, const LineSegment& segment) {
        os << "Отрезок: [" << segment.x << ", " << segment.y << "]";
        return os;
    }

    // Унарный оператор !
    LineSegment operator!() const {
        return LineSegment(0, y);
    }

    // Операции приведения типа
    operator int() const {  // Приведение к int
        return static_cast<int>(y);  // Целая часть координаты y
    }

    explicit operator double() const {  // Приведение к double
        return x;  // Координата x
    }

    // Бинарный оператор +
    LineSegment operator+(int value) const {
        return LineSegment(x + value, y);  // Увеличение x на value
    }

    // Бинарный оператор >
    bool operator>(const LineSegment& other) const {
        return x <= other.x && y >= other.y;  // Левый диапазон включает правый
    }

int main() {
    LineSegment seg1(1, 5), seg2(2, 6);

    // Тестирование операторов
    cout << "Первый отрезок: " << seg1 << endl;
    cout << "Второй отрезок: " << seg2 << endl;

    // Унарный оператор !
    cout << "!Первый отрезок: " << !seg1 << endl;

    // Приведение к int
    int y_int = seg1;
    cout << "Приведение к int (y): " << y_int << endl;

    // Приведение к double
    double x_double = static_cast<double>(seg1);
    cout << "Приведение к double (x): " << x_double << endl;

    // Бинарный оператор +
    LineSegment seg3 = seg1 + 3;
    cout << "Первый отрезок + 3: " << seg3 << endl;

    // Бинарный оператор >
    if (seg1 > seg2) {
        cout << "Первый отрезок включает второй." << endl;
    } else {
        cout << "Первый отрезок не включает второй." << endl;
    }

    return 0;
}
