// ConsoleApplication44.cpp: определ€ет точку входа дл€ консольного приложени€.
//
//все работает, только до того, как вывод€тс€ результаты умножени€ матриц, срабатывает деструктор ноунеймовской строки(vector)
#include "stdafx.h"
#include <iostream>
using namespace std;

class Matrix;

class vector {
	int size;
	int *mass;
	void createMass(int size) {
		mass = new int[size];
	}
public:
	void addvalues() {
		for (int i = 0; i < size; i++) {
			cin >> mass[i];
		}
	}
	void addNull() {
		for (int i = 0; i < size; i++) {
		mass[i]=0;
		}
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << mass[i]<<' ';
		}
	}
	vector(){
		size = 1;
		createMass(size);
		mass[0] = 0;
	}
	vector(int size1) {
		size = size1;
		createMass(size);
	}
	vector(int* a) {
		size = sizeof(a) / sizeof(a[0]);
		createMass(size);
		for (int i = 0; i < size; i++) {
			mass[i] = a[i];
		}
	}
	vector(vector& a){
		size = a.size;
		createMass(size);
		for (int i = 0; i < size; i++) {
			mass[i] = a.mass[i];
		}
	}
	~vector() {
		delete[]mass;
		cout << endl << "–аботает деструктор вектора" ;
	}

	friend vector operator*(vector& , Matrix &);
};
class Matrix {
	int sizeofMatrix;
	int **matrix;
	void createMatrix(int sizeofMatrix) {
		matrix = new int*[sizeofMatrix];
		for (int i = 0; i < sizeofMatrix; i++) {
			matrix[i] = new int[sizeofMatrix];
		}
	}
public:
	void addvaluesofMatrix() {
		for (int i = 0; i < sizeofMatrix; i++) {
			for (int j = 0; j<sizeofMatrix; j++) {
				cin >> matrix[i][j];
			}
		}
	}
	Matrix() {
		sizeofMatrix = 1;
		createMatrix(sizeofMatrix);
		matrix[0][0] = 0;
	}
	Matrix(int sizeofMatrix1) {
		sizeofMatrix = sizeofMatrix1;
		createMatrix(sizeofMatrix1);
	}
	Matrix(int** a) {
		sizeofMatrix = sizeof(a)[0] / sizeof(a[0][0]);
		createMatrix(sizeofMatrix);
		for (int i = 0; i < sizeofMatrix; i++) {
			for (int j = 0; i < sizeofMatrix; j++) {
				matrix[i][j] = a[i][j];
			}
		}
	}
	Matrix(Matrix & a) {
		sizeofMatrix = a.sizeofMatrix;
		createMatrix(sizeofMatrix);
		for (int i = 0; i < sizeofMatrix; i++) {
			for (int j = 0; j < sizeofMatrix; j++) {
				matrix[i][j] = a.matrix[i][j];
			}
		}
	}
	~Matrix() {
		for (int i = 0; i < sizeofMatrix; i++)
		{
			delete[]matrix[i];
		}
		cout << endl << "–аботает деструктор матрицы";
	}
	friend vector operator*(vector &, Matrix &);
};
vector operator*(vector &v1, Matrix &m1) {
	vector n = vector(v1.size);
	n.addNull();
	for (int i = 0; i < v1.size; i++) {
		for (int j = 0; j < v1.size; j++) {
			n.mass[i] += v1.mass[j] * m1.matrix[j][i];
			;
		}
	}
	return n;
}

	;
int main()
{
	setlocale(0, "");
	vector* a1 = new vector(2);
	a1->addvalues();
	Matrix* m1 = new Matrix(2);
	m1->addvaluesofMatrix();
	vector* rez = new vector((*a1)*(*m1));
	rez->show();
	delete a1;
	delete m1;
	delete rez;
    return 0;
}
