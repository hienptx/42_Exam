#include <iostream>
#include <string>
#include <sstream>

class bigint {
private:
    std::string digits; // Store digits in normal order

public:
    const std::string& getDigits() const { return digits; }
    
    void normalize() {
        size_t pos = digits.find_first_not_of('0');
        if (pos == std::string::npos) {
            digits = "0";
        } else {
            digits = digits.substr(pos);
        }
    }

    // Constructors
    bigint(int n = 0) {
        std::ostringstream oss;
        oss << n;
        digits = oss.str();
    }
    
    bigint(const std::string& s) : digits(s) {
        normalize();
    }
    
    // Addition
    bigint operator+(const bigint& other) const {
        std::string result;
        int carry = 0;
        int i = digits.length() - 1;
        int j = other.digits.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += digits[i--] - '0';
            if (j >= 0) sum += other.digits[j--] - '0';
            
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
        }
        
        return bigint(result);
    }
    
    bigint& operator+=(const bigint& other) {
        *this = *this + other;
        return *this;
    }

    // // Const overload that doesn't modify *this but returns the summed value
    // bigint operator+=(const bigint& other) const {
    //     return *this + other;
    // }
    
    // Increment operators
    bigint& operator++() {
        *this += bigint(1);
        return *this;
    }
    
    bigint operator++(int) {
        bigint temp = *this;
        ++(*this);
        return temp;
    }

    // Const overloads: operate on a copy and return the appropriate value
    bigint operator++() const {
        return *this + bigint(1);
    }

    bigint operator++(int) const {
        // Postfix on a const object can't modify it; return the original value
        return *this;
    }
    
    // Digit shift operators
    bigint operator<<(int shift) const {
        if (digits == "0") return *this;
        return bigint(digits + std::string(shift, '0'));
    }
    
    bigint& operator<<=(int shift) {
        *this = *this << shift;
        return *this;
    }
    
    bigint operator>>(int shift) const {
        if (shift >= (int)digits.length()) return bigint(0);
        std::string result = digits.substr(0, digits.length() - shift);
        return bigint(result.empty() ? "0" : result);
    }
    
    bigint operator>>(const bigint& shift) const {
        int shiftAmount = 0;
        std::istringstream iss(shift.digits);
        iss >> shiftAmount;
        if (iss.fail()) shiftAmount = 0;
        return *this >> shiftAmount;
    }
    
    bigint& operator>>=(int shift) {
        *this = *this >> shift;
        return *this;
    }
    
    bigint& operator>>=(const bigint& shift) {
        *this = *this >> shift;
        return *this;
    }
    
    // Comparison operators
    bool operator<(const bigint& other) const {
        if (digits.length() != other.digits.length()) {
            return digits.length() < other.digits.length();
        }
        return digits < other.digits;
    }
    
    bool operator>(const bigint& other) const {
        return other < *this;
    }
    
    bool operator<=(const bigint& other) const {
        return !(*this > other);
    }
    
    bool operator>=(const bigint& other) const {
        return !(*this < other);
    }
    
    bool operator!=(const bigint& other) const {
        return digits != other.digits;
    }
    
    bool operator==(const bigint& other) const {
        return digits == other.digits;
    }
};

std::ostream& operator<<(std::ostream& os, const bigint& num);