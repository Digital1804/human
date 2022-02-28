#include <iostream>
#include "hmnmdel.h"

using namespace std;

int main() {
    Human* alex = new Human("Alexov", "Alex", "Alexseev", 15, 43, 186, 4);
    double x, y;
    cout << "Input begin point: ";
    cin >> x >> y;
    alex->human_way(x, y);
    for (int i = 1; i < alex->get_life_time(); i++) {
        printf("Latitude = %.10lf\t Longtitude = %.10lf\n", alex->get_dist()[i][0], alex->get_dist()[i][1]);
    }
    cout << alex->full_way() << '\t' << alex->get_life_time();
    return 0;
}