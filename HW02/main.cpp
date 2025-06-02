#include "HW02.h"
#include <iostream>

// �ʼ� ���
// Animal �⺻ Ŭ���� ����
// Animal Ŭ������ makeSound() ��� ���� ���� �Լ� ����
// Animal Ŭ���� ��ӹ޾� �پ��� ���� Ŭ���� ����
// �� �ڽ� Ŭ�������� makeSound() �������Ͽ� ���� �Ҹ� ���

// ���� ���
// Zoo Ŭ���� ����
// createRandomAnimal() �Լ� ����


int main() {

	// rand() seed 
	srand((unsigned int)time(NULL));

	Animal* arrAnimals[3] = {new Cat, new Dog, new Cow};
	Zoo* zoo=new Zoo;

	for (Animal* item : arrAnimals) {
		item->makeSound();
		delete item;	// ���� �Ҵ� ����
	}

	cout << "------------ZOO------------" << endl;

	for (int i = 0; i < zoo->getSize(); i++) {
		zoo->addAnimal(createRandomAnimal());
	}

	zoo->performActions();

	delete zoo;	//���� �Ҵ� ����


	return 0;
}