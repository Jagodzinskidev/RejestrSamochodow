//
// Created by Seweryn on 10.06.2025.
//

#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    int mileage;

public:
    Car(const std::string& brand, const std::string& model, int year, int mileage);
    void edit(const std::string& newBrand, const std::string& newModel, int newYear, int newMileage);
    void display() const;
    const std::string& getBrand() const;
    const std::string& getModel() const;
    int getYear() const;
    int getMileage() const;
};

#endif
