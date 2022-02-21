#include <iostream>
#include <cmath>

#define LIFE_TIME  5
#define GEO 2
double METER=0.000009;
double PI=3.14159265;
double RADI=6371000;
using namespace std;

class Human{
private:
    string surname;
    string name;
    string middlename;
    int age;
    float height;
    float weight;
    double** dist;
    float step;
    double* way;
public:
    void set_surname(string surna){
        surname = surna;
    }
    void set_name(string na){
        name = na;
    }
    void set_middlename(string midna){
        middlename = midna;
    }
    void set_fullname(string surna, string na, string midna){
        set_surname(surna);
        set_name(na);
        set_middlename(midna);
    }
    void set_age(int a){
        age = a;
    }
    void set_weight(float we){
        weight = we;
    }
    void set_height(float he){
        height = he;
    }
    void set_phisical(int a, float we, float he){
        set_age(a);
        set_weight(we);
        set_height(he);
    }
    Human(string surna, string na, string midna, int a, float we, float he){
        set_fullname(surna, na, midna);
        set_phisical(a, we, he);
        dist = new double*[LIFE_TIME];
        for (int i=0; i<LIFE_TIME; i++){
            dist[i] = new double[GEO];
        }
        for (int i=0; i<LIFE_TIME; i++){
            for (int j=0; j<GEO; j++){
                dist[i][j] = 0;
            }
        }
        way = new double[LIFE_TIME];
        step = 3*(he*15.8/100-1.5)/100;
    }
    string get_surname(){
        return surname;
    }
    string get_name(){
        return name;
    }
    string get_middlename(){
        return middlename;
    }
    void get_fullname(){
        cout << "Surname: " << get_surname() << '\t';
        cout << "Name: " << get_name() << '\t';
        cout << "Middlename: " << get_middlename() << '\t';
    }
    int get_age(){
        return age;
    }
    float get_weight(){
        return weight;
    }
    float get_height(){
        return height;
    }
    float get_step(){
        return step;
    }
    double** get_dist(){
        return dist;
    }
    void get_phisical(){
        cout << "Age: " << get_age() << '\t';
        cout << "Wheight: " << get_weight() << '\t';
        cout << "Height: " << get_height() << '\n';
    }
};

int main(){
    Human *alex = new Human("Alexov", "Alex", "Alexseev", 15 , 43, 186);
    cout << "Input begin point: ";
    cin >> alex->get_dist()[0][0] >> alex->get_dist()[0][1];
    double corner1 = alex->get_step()/RADI;
    double way1 = 2*RADI*sin(alex->get_step()/(RADI*2));  
    for (int i = 1 ; i<LIFE_TIME; i++){                                                                                                                        
            alex->get_dist()[i][0] = alex->get_dist()[i-1][0] + (sqrt(3)/2)*(alex->get_step()*METER);
            alex->get_dist()[i][1] = alex->get_dist()[i-1][1] + alex->get_step()*METER/2;
        printf("Latitude = %.10lf\t Longtitude = %.10lf\n", alex->get_dist()[i][0], alex->get_dist()[i][1]);
    }
    return 0;
}