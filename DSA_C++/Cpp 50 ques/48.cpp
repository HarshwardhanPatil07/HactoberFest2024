#include <iostream>
using namespace std;

class Rectangle {
private:
    int length, width;
public:
    void setDimensions(int l, int w) {
        length = l;
        width = w;
    }

    int area() {
        return length * width;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(5, 3);
    cout << "Area of rectangle: " << rect.area();
    return 0;
}
