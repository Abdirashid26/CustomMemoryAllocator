//
// Created by fabdirashid on 16/01/2025.
//

#ifndef CUSTOMALLOCATOR_H
#define CUSTOMALLOCATOR_H
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>


class CustomAllocator {
    public:
    char* pool;
    int block_size;
    std::vector<void*> blocks;

    CustomAllocator() {
        this->pool = new char[1024*1024]; //this will give me a memeory pool of 1MB
        this->block_size = 1024*4;
        int num_of_blocks = (1024*1024) / block_size;
        std::cout << "num of blocks: " << num_of_blocks << std::endl;
        for (int i = 0; i < num_of_blocks; i++) {
            blocks.push_back(pool + i*block_size);
        }
    };

    void* allocate() {
        if (blocks.empty()) {
            std::cerr << "No more memory to allocate" << std::endl;
            return nullptr;
        }
        void* ptr = blocks.back();
        blocks.pop_back();
        std::cout << "allocated at: " << ptr << std::endl;
        return ptr;
    }

    void deallocate(void* p) {
        blocks.push_back(p);
    }

    ~CustomAllocator() {
        delete[] pool;
    }

};


#endif //CUSTOMALLOCATOR_H
