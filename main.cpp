#include <iostream>
#include "include/CustomAllocator.h"

/**
 *
 * I know i have the implementation of my custom allocator in the
 * header files ..... im rushing this implementation ... but hey it works
 */
int main() {
    std::cout << "Custom Allocator Tester : " << std::endl;
    CustomAllocator allocator{};
    for (int i = 0 ; i < 258 ; i++) {
        allocator.allocate();
    }
    // allocator.deallocate(num);
    return 0;
}