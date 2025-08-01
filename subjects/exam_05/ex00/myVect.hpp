#pragma once

#include <iostream>

class vect2{
	private:
		int data[2];
	public:
		vect2(int x = 0, int y = 0){
			data[0] = x;
			data[1] = y;
		}
		vect2& operator=(const vect2& other){
			if(this != &other)
			{
				data[0] = other.data[0];
				data[1] = other.data[1];
			}
			return (*this);
		}
		vect2 operator+(const vect2& other){
			return vect2(data[0]+other.data[0], data[1]+ other.data[1]);
		}
		vect2 operator-(const vect2& other){
			return vect2(data[0]-other.data[0], data[1]- other.data[1]);
		}
		vect2 operator*(int scalal){
			return vect2(data[0]*scalal, data[1]*scalal);
		}
		int& operator[](int idx)
		{
			return data[idx];
		}
		const int& operator[](int idx) const
		{
			return data[idx];
		}
};

std::ostream& operator<<(std::ostream& os, const vect2& other){
	return os << "{" << other[0] << ", "<< other[1]<<"}";
}