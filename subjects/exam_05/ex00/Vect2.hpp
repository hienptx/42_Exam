#pragma once
#include <iostream>

class vect2 {
private:
    int data[2];

public:
    vect2(int x = 0, int y = 0) {
		data[0]= x;
		data[1] =y;
	}
    
    vect2 operator+(const vect2& other) const {
        return vect2(data[0] + other.data[0], data[1] + other.data[1]);
    }
    
    vect2 operator-(const vect2& other) const {
        return vect2(data[0] - other.data[0], data[1] - other.data[1]);
    }
    
    vect2 operator*(int scalar) const {
        return vect2(data[0] * scalar, data[1] * scalar);
    }
    
    int& operator[](int index) {
        return data[index];
    }
    
    const int& operator[](int index) const {
        return data[index];
    }
    
};

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    return os << "{" << v[0] << ", " << v[1] << "}";
}