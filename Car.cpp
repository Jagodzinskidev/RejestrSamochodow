//
// Created by Seweryn on 10.06.2025.
//
#include "Car.h"
#include <iostream>

Car::Car(const std::string& brand, const std::string& model, int year, int mileage)
    : brand(brand), model(model), year(year), mileage(mileage) {}

void Car::edit(const std::string& newBrand, const std::string& newModel, int newYear, int newMileage) {
    brand = newBrand;
    model = newModel;
    year = newYear;
    mileage = newMileage;
}

void Car::display() const {
    std::cout << "Marka: " << brand
              << ", Model: " << model
              << ", Rok zakupu: " << year
              << ", Przebieg: " << mileage << " km\n";
}

const std::string& Car::getBrand() const {
    return brand;
}

const std::string& Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

int Car::getMileage() const {
    return mileage;
}

