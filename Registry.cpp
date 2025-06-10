//
// Created by Seweryn on 10.06.2025.
//
#include "Registry.h"
#include <iostream>
#include <cstdlib> // malloc, free, realloc

Registry::Registry() {
    cars = nullptr;
    size = 0;
}

Registry::~Registry() {
    for (int i = 0; i < size; ++i) {
        delete cars[i];
    }
    free(cars);
}

void Registry::addCar(const std::string& brand, int year, int mileage) {
    Car** newCars = (Car**)realloc(cars, (size + 1) * sizeof(Car*));
    if (newCars == nullptr) {
        std::cerr << "Blad alokacji pamieci!\n";
        return;
    }
    cars = newCars;
    cars[size] = new Car(brand, year, mileage);
    ++size;
}

void Registry::deleteCar(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Nieprawidlowy indeks!\n";
        return;
    }

    delete cars[index];

    for (int i = index; i < size - 1; ++i) {
        cars[i] = cars[i + 1];
    }

    --size;
    Car** newCars = (Car**)realloc(cars, size * sizeof(Car*));
    if (newCars != nullptr || size == 0) {
        cars = newCars;
    }
}

void Registry::editCar(int index, const std::string& brand, int year, int mileage) {
    if (index < 0 || index >= size) {
        std::cout << "Nieprawidlowy indeks!\n";
        return;
    }
    cars[index]->edit(brand, year, mileage);
}

void Registry::displayAll() const {
    if (size == 0) {
        std::cout << "Brak samochodow w rejestrze.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << i << ". ";
        cars[i]->display();
    }
}

void Registry::searchByBrand(const std::string& brand) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getBrand() == brand) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) std::cout << "Brak samochodow o podanej marce.\n";
}

void Registry::searchByYear(int year) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getYear() == year) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) std::cout << "Brak samochodow z podanego rocznika.\n";
}

void Registry::searchByMaxMileage(int maxMileage) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getMileage() <= maxMileage) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) std::cout << "Brak samochodow o przebiegu rownym badz mniejszym niz " << maxMileage << "km.\n";
}
