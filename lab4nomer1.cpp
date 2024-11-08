#include <iostream>
#include <optional>

using namespace std;

class LineSegment {
private:
    double x1, x2;

public:
    LineSegment() : x1(0), x2(1) {}

    LineSegment(double start, double end) : x1(start), x2(end) {
        if (x1 > x2) {
            swap(x1, x2);
        }
    }
    LineSegment(const LineSegment& other) : x1(other.x1), x2(other.x2) {}

    // Перегрузка оператора вывода для отображения отрезка
    friend ostream& operator<<(ostream& os, const LineSegment& segment) {
        os << "Отрезок: [" << segment.x1 << ", " << segment.x2 << "]";
        return os;
    }

    // Метод для нахождения пересечения двух отрезков на координатной прямой
    static optional<LineSegment> intersect(const LineSegment& seg1, const LineSegment& seg2) {
        double max_start = max(seg1.x1, seg2.x1);
        double min_end = min(seg1.x2, seg2.x2);

        if (max_start <= min_end) {
            return LineSegment(max_start, min_end); // Возвращаем пересечение как новый отрезок
        }
        return nullopt; 
    }


    double getStart() const { return x1; }
    double getEnd() const { return x2; }
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

    auto intersection = LineSegment::intersect(seg1, seg2);
    if (intersection) {
        cout << "Отрезки пересекаются. Пересечение: " << *intersection << endl;
    } else {
        cout << "Отрезки не пересекаются." << endl;
    }

    return 0;
}