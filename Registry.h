//
// Created by Seweryn on 10.06.2025.
//

#ifndef REGISTRY_H
#define REGISTRY_H

#include "Car.h"

class Registry {
private:
    Car** cars;
    int size;

public:
    Registry();
    ~Registry();

    void addCar(const std::string& brand, const std::string& model, int year, int mileage);
    void deleteCar(int index);
    void editCar(int index, const std::string& brand, const std::string& model, int year, int mileage);
    void displayAll() const;
    void searchByBrand(const std::string& brand) const;
    void searchByModel(const std::string& model) const;
    void searchByYear(int year) const;
    void searchByMaxMileage(int maxMileage) const;

    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};

#endif
