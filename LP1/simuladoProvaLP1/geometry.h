
#include <iostream>

using namespace std;


class Points {
	public:
		Point(int , int);

		getX() const;
		getY() const;

		setX(const int);
		setY(const int);
	private:
		int X, Y, K;
};

Points(int x = 0, int y = 0) : X(y), Y(y) {}

	int getX() {
                return X
        }

        int getY() {
                return Y;
        }

        void setX(const int newX) {
                X = newX;
        }

        void setY(const int newY) {
                Y = newY;
        }



