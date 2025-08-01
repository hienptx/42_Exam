#include <iostream>

class vect2 {
private:
    int data[2];

public:
    // Default constructor
    vect2() {
        data[0] = 0;
        data[1] = 0;
    }
    
    // Parameterized constructor
    vect2(int x, int y) {
        data[0] = x;
        data[1] = y;
    }
    
    // Copy constructor
    vect2(const vect2& other) {
        data[0] = other.data[0];
        data[1] = other.data[1];
    }
    
    // Assignment operator
    vect2& operator=(const vect2& other) {
        if (this != &other) {
            data[0] = other.data[0];
            data[1] = other.data[1];
        }
        return *this;
    }
    
    // Index operator for accessing components
    int& operator[](int index) {
        return data[index];
    }
    
    const int& operator[](int index) const {
        return data[index];
    }
    
    // Addition operator
    vect2 operator+(const vect2& other) const {
        return vect2(data[0] + other.data[0], data[1] + other.data[1]);
    }
    
    // Subtraction operator
    vect2 operator-(const vect2& other) const {
        return vect2(data[0] - other.data[0], data[1] - other.data[1]);
    }
    
    // Scalar multiplication operator
    vect2 operator*(int scalar) const {
        return vect2(data[0] * scalar, data[1] * scalar);
    }
    
    // Unary minus operator
    vect2 operator-() const {
        return vect2(-data[0], -data[1]);
    }
    
    // Compound assignment operators
    vect2& operator+=(const vect2& other) {
        data[0] += other.data[0];
        data[1] += other.data[1];
        return *this;
    }
    
    vect2& operator-=(const vect2& other) {
        data[0] -= other.data[0];
        data[1] -= other.data[1];
        return *this;
    }
    
    vect2& operator*=(int scalar) {
        data[0] *= scalar;
        data[1] *= scalar;
        return *this;
    }
    
    // Increment operators
    vect2& operator++() { // prefix
        ++data[0];
        ++data[1];
        return *this;
    }
    
    vect2 operator++(int) { // postfix
        vect2 temp(*this);
        ++data[0];
        ++data[1];
        return temp;
    }
    
    // Decrement operators
    vect2& operator--() { // prefix
        --data[0];
        --data[1];
        return *this;
    }
    
    vect2 operator--(int) { // postfix
        vect2 temp(*this);
        --data[0];
        --data[1];
        return temp;
    }
    
    // Equality operator
    bool operator==(const vect2& other) const {
        return (data[0] == other.data[0]) && (data[1] == other.data[1]);
    }
    
    // Inequality operator
    bool operator!=(const vect2& other) const {
        return !(*this == other);
    }
};

// Output stream operator
std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}

// Scalar multiplication (scalar * vector)
vect2 operator*(int scalar, const vect2& v) {
    return vect2(v[0] * scalar, v[1] * scalar);
}

