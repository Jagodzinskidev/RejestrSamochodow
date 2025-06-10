//
// Created by Seweryn on 10.06.2025.
//

#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string brand;
    int year;
    int mileage;

public:
    Car(const std::string& brand, int year, int mileage);
    void edit(const std::string& brand, int year, int mileage);
    void display() const;
    const std::string& getBrand() const;
    int getYear() const;
    int getMileage() const;

};

#endif
