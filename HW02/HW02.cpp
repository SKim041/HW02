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
		item = nullptr;// ������ ����
	}
	cout << "���� �Ҵ� ����" << endl;
}

void Zoo::addAnimal(Animal* animal) {
	// ������ �������� �߰��ϴ� �Լ�
	// - Animal ��ü�� �����͸� �޾� ������ �迭�� �����մϴ�.
	// - ���� �����̶� ���� �� �߰��� �� �ֽ��ϴ�.
	// - �Է� �Ű�����: Animal* (�߰��� ���� ��ü)
	// - ��ȯ��: ����
	if (idx >= sizeof(this->animals) / sizeof(Animal)) {
		cout << "Overcrowded!!" << endl;
	}
	else {
		this->animals[this->idx++] = animal;
	}
}

void Zoo::performActions() {
	// �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
	// - ��� ���� ��ü�� ���� ���������� �Ҹ��� ���� �����̴� ������ �����մϴ�.
	// - �Է� �Ű�����: ����
	// - ��ȯ��: ����
	for (auto item : this->animals) {
		if (item == nullptr) continue;
		item->makeSound();
	}
}

Animal* createRandomAnimal() {
	// ���� ������ �����ϴ� �Լ�
	// - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
	// - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
	// - �Է� �Ű�����: ����
	// - ��ȯ��: Animal* (������ ���� ��ü�� ������)
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