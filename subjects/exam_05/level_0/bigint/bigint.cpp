#include "bigint.hpp"

std::ostream& operator<<(std::ostream& os, const bigint& num) {
    os << num.getDigits();
    return os;
}
