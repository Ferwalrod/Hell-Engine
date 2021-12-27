#pragma once

template<class T>
class HArray {
private:
	int tam = 10;
	int Num = 0;
	T data[];
	void resize() {
		tam += 5;
		T newData[tam];
		for (int i = 0; i < Num; i++) {
			newData[i] = data[i];
		}
		delete [] data;
		data = newData;
	}
public:

	HArray() :tam(10), Num(0) { data[10]; }
	HArray(int _tam) :tam(_tam), Num(0) { data[tam]; }

	T& operator[](int i) {
		return data[i];
	}
	int size() {
		return Num;
	}
	void push(T& obj) {
		if (Num == tam) {
			resize();
		}
		data[Num] = obj;
		Num++;
	}
	void pop() {
		Num--;
	}
};

template<class T>
class HList {

};
template<class T>
class HStack {

};
template<class T>
class HMap {

};
