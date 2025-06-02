#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal {
protected:

public:
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	void makeSound();
};

class Cat : public Animal {
public:
	void makeSound();
};

class Cow : public Animal {
public:
	void makeSound();
};

class Zoo {
private:
	// animals 크기 제한
	static const int size = 10;
	Animal* animals[size] = {};
	int idx = 0;
public:
	void addAnimal(Animal* animal);
	void performActions();
	int getSize();
	~Zoo();
};

Animal* createRandomAnimal();

#endif // !ANIMAL_H

