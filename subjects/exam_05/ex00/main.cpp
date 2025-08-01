#include "myVect.hpp"
#include <iostream>

int main() {
    // Test constructors
    vect2 v1;              // Default constructor
    vect2 v2(3, 4);        // Parameterized constructor
    vect2 v3(1, 2);
    vect2 v4 = v3;
    
    std::cout << "Initial vectors:" << std::endl;
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << std::endl;
    
    // Test addition
    vect2 sum = v2 + v3;
    std::cout << "Addition: " << v2 << " + " << v3 << " = " << sum << std::endl;
    
    // Test subtraction
    vect2 diff = v2 - v3;
    std::cout << "Subtraction: " << v2 << " - " << v3 << " = " << diff << std::endl;
    
    // Test scalar multiplication
    vect2 scaled = v2 * 2;
    std::cout << "Scalar multiplication: " << v2 << " * 2 = " << scaled << std::endl;
    
    // Test the specific example from requirements
    vect2 test(2, 2);
    vect2 result = test * 2;
    std::cout << "Test case: " << test << " * 2 = " << result << std::endl;
    std::cout << "Is (vect2(2,2) * 2) == vect2(4,4)? " << 
                 (result[0] == 4 && result[1] == 4 ? "true" : "false") << std::endl;
    std::cout << std::endl;
    
    // Test array access operator
    std::cout << "Array access test:" << std::endl;
    std::cout << "v2[0] = " << v2[0] << ", v2[1] = " << v2[1] << std::endl;
    
    // Test modifying through array access
    v2[0] = 10;
    v2[1] = 20;
    std::cout << "After modification: " << v2 << std::endl;
    
    // Test chaining operations
    vect2 complex = (v3 + vect2(1, 1)) * 3;
    std::cout << "Complex operation: (" << v3 << " + {1, 1}) * 3 = " << complex << std::endl;
    
    return 0;
}