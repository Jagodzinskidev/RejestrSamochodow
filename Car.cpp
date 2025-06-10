//
// Created by Seweryn on 10.06.2025.
//
#include "Car.h"
#include <iostream>

Car::Car(const std::string& brand, int year, int mileage)
    : brand(brand), year(year), mileage(mileage) {}

void Car::edit(const std::string& newBrand, int newYear, int newMileage) {
    brand = newBrand;
    year = newYear;
    mileage = newMileage;
}

void Car::display() const {
    std::cout << "Marka: " << brand
              << ", Rok zakupu: " << year
              << ", Przebieg: " << mileage << " km\n";
}

const std::string& Car::getBrand() const {
    return brand;
}
