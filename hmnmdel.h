#pragma once
#include <iostream>
#include <string>

#ifndef hmnmdel
#define hmnmdel

class Human {
private:
    std::string surname;
    std::string name;
    std::string middlename;
    int age;
    float height;
    float weight;
    double** dist;
    double step;
    double* way;
    int life_time;
    double full;
public:
    Human(std::string surna, std::string na, std::string midna, int a, float we, float he, int lt);
    void set_lifetime(int lt);
    void set_surname(std::string surna);
    void set_name(std::string na);
    void set_middlename(std::string midna);
    void set_fullname(std::string surna, std::string na, std::string midna);
    void set_age(int a);
    void set_weight(float we);
    void set_height(float he);
    void set_phisical(int a, float we, float he);
    std::string get_surname();
    std::string get_name();
    std::string get_middlename();
    void get_fullname();
    int get_age();
    int get_life_time();
    float get_weight();
    float get_height();
    float get_step();
    double** get_dist();
    void get_phisical();
    void human_way(double x_null, double y_null);
    double full_way();
};

#endif