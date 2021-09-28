#include <iostream>


//вариант 3
using namespace std;

class Image {
    int* img;
    int mx, my;
public:
    Image(int tmx, int tmy) :mx(tmx), my(tmy) {
        img = new int[mx * my]();
    }
    virtual ~Image() {
        delete[] img;
    }

    int get(int x, int y) {
        if (x >= mx || y >= my || x < 0 || y < 0) {
            throw 1;
        }
        return img[y * my + x];
    }

    int set(int x, int y, int color) {
        if (x >= mx || y >= my || x < 0 || y < 0) {
            throw 1;
        }
        img[y * my + x] = color;
    }

    friend bool operator ==(const Image& arrInt, const Image& arrInt2);
};

bool operator == (const Image& arrInt, const Image& arrInt2) {
    if ((arrInt.mx != arrInt2.mx) || (arrInt.my != arrInt2.my)) {
        return false;
    }
    for (int i = 0; i < (arrInt.mx) * (arrInt.my); i++) {
        if (arrInt.img[i] != arrInt2.img[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    try
    {
        Image frst(2, 2);
        frst.set(0, 0, 1);
        frst.set(1, 0, 2);
        frst.set(0, 1, 3);
        frst.set(1, 1, 4);

        Image scnd(1, 1);
        if (scnd == frst) {
            cout << "identical" << endl;
        }
        else {
            cout << "unidentical" << endl;
        }

        cout << scnd.get(0, 0) << endl;
        cout << scnd.get(1, 0) << endl;
        cout << scnd.get(0, 1) << endl;
        cout << scnd.get(1, 1) << endl;

        scnd.set(3, 3, 1);
    }
    catch (int)
    {
        cout << "Out of range" << endl;
    }
}