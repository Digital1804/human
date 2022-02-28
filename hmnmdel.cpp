#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include "hmnmdel.h"

double METER = 0.000009;
double PI = 3.14159265;
double RADI = 6371000;

using namespace std;

Human::Human(string surna, string na, string midna, int a, float we, float he, int lt) {
    while (lt < 3) {
        cout << "Life time of hyman must be more than 2, input new life time: ";
        cin >> lt;
    }
    life_time = lt;
    set_fullname(surna, na, midna);
    set_phisical(a, we, he);
    dist = new double* [lt];
    for (int i = 0; i < lt; i++) {
        dist[i] = new double[3];
    }
    for (int i = 0; i < lt; i++) {
        for (int j = 0; j < 3; j++) {
            dist[i][j] = 0;
        }
    }
    way = new double[lt];
    step = 3 * (he * 15.8 / 100 - 1.5) / 100;
    full = 0;
}
void Human::set_lifetime(int lt) {
    life_time = lt;
}
void Human::set_surname(string surna) {
    surname = surna;
}
void Human::set_name(string na) {
    name = na;
}
void Human::set_middlename(string midna) {
    middlename = midna;
}
void Human::set_fullname(string surna, string na, string midna) {
    set_surname(surna);
    set_name(na);
    set_middlename(midna);
}
void Human::set_age(int a) {
    age = a;
}
void Human::set_weight(float we) {
    weight = we;
}
void Human::set_height(float he) {
    height = he;
}
void Human::set_phisical(int a, float we, float he) {
    set_age(a);
    set_weight(we);
    set_height(he);
}
string Human::get_surname() {
    return surname;
}
string Human::get_name() {
    return name;
}
string Human::get_middlename() {
    return middlename;
}
void Human::get_fullname() {
    cout << "Surname: " << get_surname() << '\t';
    cout << "Name: " << get_name() << '\t';
    cout << "Middlename: " << get_middlename() << '\t';
}
int Human::get_age() {
    return age;
}
int Human::get_life_time() {
    return life_time;
}
float Human::get_weight() {
    return weight;
}
float Human::get_height() {
    return height;
}
float Human::get_step() {
    return step;
}
double** Human::get_dist() {
    return dist;
}
void Human::get_phisical() {
    cout << "Age: " << get_age() << '\t';
    cout << "Wheight: " << get_weight() << '\t';
    cout << "Height: " << get_height() << '\n';
}
void Human::human_way(double x_null, double y_null) {
    srand(time(NULL));
    dist[0][0] = x_null;
    dist[0][1] = y_null;
    double corner1 = step / RADI;
    double way1 = 2 * RADI * sin(step / (RADI * 2));
    for (int i = 1; i < life_time; i++) {
        int x, y;
        double alfa = static_cast <double>(rand() % 12) / (static_cast <double>(rand() % 12 + 1));
        double speed = static_cast <double>(rand() % 3) + step;
        while (alfa > 2)    alfa -= 2;
        if (alfa < 0.5) {
            x = 1;
            y = 1;
        }
        else if (alfa < 1) {
            x = -1;
            y = 1;
        }
        else if (alfa < 1.5) {
            x = -1;
            y = -1;
        }
        else {
            x = 1;
            y = -1;
        }
        dist[i][0] = dist[i - 1][0] + x * speed * (sqrt(3) / 2) * (step * METER);
        dist[i][1] = dist[i - 1][1] + y * speed * step * METER / 2;
        dist[i-1][2] = speed * step;
    }
}
double Human::full_way() {
    for (int i = 0; i < life_time; i++) {
        full += dist[i][2];
    }
    return full;
}