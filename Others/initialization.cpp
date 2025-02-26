#include <iostream>
#include <vector>

int main() {
    // Uniform initialization of a vector
    std::vector<int> numbers{1, 2, 3, 4, 5};

// Accessing vector elements
for (int num : numbers) {
    std::cout << num << " ";

}
    std::cout << std::endl;
    return 0;
}