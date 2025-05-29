#include "HW02.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


void Dog::makeSound() {
	cout << "Dog: Woof! Woof!" << endl;
}

void Cat::makeSound() {
	cout << "Cat: Meow" << endl;
}

void Cow::makeSound() {
	cout << "Cow: Mooooooo" << endl;
}

Zoo::Zoo() {

}

Zoo::~Zoo() {
	for (auto item : this->animals) {
		delete item;
		item = nullptr;// 포인터 해제
	}
	cout << "동적 할당 해제" << endl;
}

void Zoo::addAnimal(Animal* animal) {
	// 동물을 동물원에 추가하는 함수
	// - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
	// - 같은 동물이라도 여러 번 추가될 수 있습니다.
	// - 입력 매개변수: Animal* (추가할 동물 객체)
	// - 반환값: 없음
	if (idx >= sizeof(this->animals) / sizeof(Animal)) {
		cout << "Overcrowded!!" << endl;
	}
	else {
		this->animals[this->idx++] = animal;
	}
}

void Zoo::performActions() {
	// 동물원에 있는 모든 동물의 행동을 수행하는 함수
	// - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	for (auto item : this->animals) {
		if (item == nullptr) continue;
		item->makeSound();
	}
}

Animal* createRandomAnimal() {
	// 랜덤 동물을 생성하는 함수
	// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
	// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
	// - 입력 매개변수: 없음
	// - 반환값: Animal* (생성된 동물 객체의 포인터)
	Animal* animal;
	int randNum = rand() % 3;

	switch (randNum) {
	case 0:
		return new Cat;
		break;
	case 1:
		return new Dog;
		break;
	case 2:
		return new Cow;
		break;
	}
}