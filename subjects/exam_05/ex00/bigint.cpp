#include <iostream>
#include <string>
#include <algorithm>

class bigint {
private:
    std::string digits; // Least significant digit first

    static std::string addStrings(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0, sum = 0;
        size_t i = 0;
        while (i < a.size() || i < b.size() || carry) {
            sum = carry;
            if (i < a.size()) sum += a[i] - '0';
            if (i < b.size()) sum += b[i] - '0';
            result += (sum % 10) + '0';
            carry = sum / 10;
            ++i;
        }
        return result;
    }

    static int compare(const std::string& a, const std::string& b) {
        if (a.size() != b.size())
            return a.size() < b.size() ? -1 : 1;
        for (size_t i = a.size(); i-- > 0;) {
            if (a[i] != b[i])
                return a[i] < b[i] ? -1 : 1;
        }
        return 0;
    }

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == '0')
            digits.pop_back();
    }

public:
    bigint(unsigned long long num = 0) {
        if (num == 0) {
            digits = "0";
        } else {
            while (num > 0) {
                digits += (num % 10) + '0';
                num /= 10;
            }
        }
    }

    bigint(int num) : bigint((unsigned long long)num) {}

    bigint(const std::string& num) {
        digits = num;
        std::reverse(digits.begin(), digits.end());
        removeLeadingZeros();
    }

    bigint(const bigint& other) : digits(other.digits) {}

    bigint& operator=(const bigint& other) {
        digits = other.digits;
        return *this;
    }

    // Addition
    bigint operator+(const bigint& other) const {
        bigint result;
        result.digits = addStrings(this->digits, other.digits);
        return result;
    }

    bigint& operator+=(const bigint& other) {
        digits = addStrings(this->digits, other.digits);
        return *this;
    }

    // Pre-increment
    bigint& operator++() {
        *this += 1;
        return *this;
    }

    // Post-increment
    bigint operator++(int) {
        bigint temp = *this;
        ++(*this);
        return temp;
    }

    // Digit shift left (base-10)
    bigint operator<<(int shift) const {
        if (*this == 0) return *this;
        bigint result = *this;
        result.digits.insert(result.digits.begin(), shift, '0');
        return result;
    }

    bigint& operator<<=(int shift) {
        if (*this == 0) return *this;
        digits.insert(digits.begin(), shift, '0');
        return *this;
    }

    // Digit shift right (base-10)
    bigint operator>>(int shift) const {
        bigint result = *this;
        if (digits.size() <= static_cast<size_t>(shift)) {
            result = 0;
        } else {
            result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
        }
        result.removeLeadingZeros();
        return result;
    }

    bigint& operator>>=(int shift) {
        if (digits.size() <= static_cast<size_t>(shift)) {
            digits = "0";
        } else {
            digits.erase(digits.begin(), digits.begin() + shift);
        }
        removeLeadingZeros();
        return *this;
    }

    // Comparisons
    bool operator<(const bigint& other) const {
        return compare(digits, other.digits) < 0;
    }

    bool operator>(const bigint& other) const {
        return compare(digits, other.digits) > 0;
    }

    bool operator<=(const bigint& other) const {
        return compare(digits, other.digits) <= 0;
    }

    bool operator>=(const bigint& other) const {
        return compare(digits, other.digits) >= 0;
    }

    bool operator==(const bigint& other) const {
        return compare(digits, other.digits) == 0;
    }

    bool operator!=(const bigint& other) const {
        return !(*this == other);
    }

    // Public method for output
    std::string to_string() const {
        std::string out = digits;
        std::reverse(out.begin(), out.end());
        return out;
    }
};

// Output operator (non-friend)
std::ostream& operator<<(std::ostream& os, const bigint& b) {
    return os << b.to_string();
}
