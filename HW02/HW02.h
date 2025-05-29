#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal {
protected:

public:
	Animal() {}
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	Dog() {}
	void makeSound();
};

class Cat : public Animal {
public:
	Cat() {}
	void makeSound();
};

class Cow : public Animal {
public:
	Cow() {}
	void makeSound();
};

class Zoo {
private:
	Animal* animals[10] = {};
	int idx = 0;
public:
	Zoo();
	void addAnimal(Animal* animal);
	void performActions();
	~Zoo();
};

Animal* createRandomAnimal();

#endif // !ANIMAL_H

