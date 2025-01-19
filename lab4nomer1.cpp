#include <iostream>

using namespace std;

class LineSegment {
private:
    double x, y;

public:
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

    // Метод для проверки пересечения отрезков и возврата отрезка пересечения
    bool intersect(const LineSegment& seg2, LineSegment& intersection) const {
        double max_start = max(x, seg2.x);
        double min_end = min(y, seg2.y);

        if (max_start <= min_end) {
            intersection = LineSegment(max_start, min_end);  // Сохраняем отрезок пересечения
            return true;  // Пересекаются
        } else {
            return false;  // Не пересекаются
        }
    }
};

int main() {
    double start1, end1, start2, end2;
    cout << "Введите координаты начала и конца первого отрезка: ";
    cin >> start1 >> end1;
    LineSegment seg1(start1, end1);

    cout << "Введите координаты начала и конца второго отрезка: ";
    cin >> start2 >> end2;
    LineSegment seg2(start2, end2);

    cout << "Первый отрезок: " << seg1 << endl;
    cout << "Второй отрезок: " << seg2 << endl;

    LineSegment intersection(0, 0);  // Объект для хранения пересечения
    if (seg1.intersect(seg2, intersection)) {
        cout << "Отрезки пересекаются. Пересечение: " << intersection << endl;
    } else {
        cout << "Отрезки не пересекаются." << endl;
    }

    return 0;
}
