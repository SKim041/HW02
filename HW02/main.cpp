#include "HW02.h"
#include <iostream>

// 필수 기능
// Animal 기본 클래스 정의
// Animal 클래스에 makeSound() 라는 순수 가상 함수 포함
// Animal 클래스 상속받아 다양한 동물 클래스 생성
// 각 자식 클래스에서 makeSound() 재정의하여 동물 소리 출력

// 도전 기능
// Zoo 클래스 정의
// createRandomAnimal() 함수 구현


int main() {

	// rand() seed 
	srand((unsigned int)time(NULL));

	Animal* arrAnimals[3] = {new Cat, new Dog, new Cow};
	Zoo* zoo=new Zoo;

	for (Animal* item : arrAnimals) {
		item->makeSound();
		delete item;	// 동적 할당 해제
	}

	cout << "------------ZOO------------" << endl;

	for (int i = 0; i < zoo->getSize(); i++) {
		zoo->addAnimal(createRandomAnimal());
	}

	zoo->performActions();

	delete zoo;	//동적 할당 해제


	return 0;
}