#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <mutex>

template <size_t BlockSize, size_t BlockNum = 10>
class MemoryPool {
public:
    MemoryPool() {
        std::lock_guard<std::mutex> lock(mutex_);
        // Init empty memory pointer
        freeBlockHead_ = nullptr;
        memChunkHead_ = nullptr;
    }
    ~MemoryPool() {
        std::lock_guard<std::mutex> lock(mutex_);
        // Destruct automatically
        while (memChunkHead_) {
            MemChunk* nextPtr = memChunkHead_->next;
            delete memChunkHead_;
            memChunkHead_ = nextPtr;
        }
    }
    void* Allocate() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (freeBlockHead_ == nullptr) {
            // Malloc MemChunk
            MemChunk* newChunk = new MemChunk;
            newChunk->next = nullptr;
            // Set this chunk's first block as free block head
            freeBlockHead_ = &(newChunk->blocks[0]);
            // Link the new chunk's all blocks
            for (int i = 1; i < BlockNum; i++) {
                newChunk->blocks[i - 1].next = &(newChunk->blocks[i]);
            }
            newChunk->blocks[BlockNum - 1].next = nullptr;
            if (memChunkHead_ == nullptr) {
                memChunkHead_ = newChunk;
            } else {
                // Add newChunk to chunk list
                newChunk->next = memChunkHead_;
                memChunkHead_ = newChunk;
            }
        }
        // alloct thr current free block to the object
        void* freeBlock = freeBlockHead_;
        freeBlockHead_ = freeBlockHead_->next;
        return freeBlock;
    }
    void* Allocate(size_t size) {
        std::lock_guard<std::mutex> lock(arrayMutex_);
        // Calculate objects num
        int n = size / BlockSize;
        // allocate n objects in continuosmemory
        void* ptr = Allocate();
        for (size_t i = 1; i < n; i++) {
            Allocate();
        }
        return ptr;
    }
    void Free(void* ptr) {
        std::lock_guard<std::mutex> lock(mutex_);
        // free object memory
        FreeBlock* block = static_cast<FreeBlock*>(ptr);
        block->next = freeBlockHead_;
        freeBlockHead_ = block;
    }

private:
    struct FreeBlock {
        char data[BlockSize];
        FreeBlock* next;
    };
    struct MemChunk {
        FreeBlock blocks[BlockNum];
        MemChunk* next;
    };
    FreeBlock* freeBlockHead_;
    MemChunk* memChunkHead_;
    std::mutex mutex_;
    std::mutex arrayMutex_;
};

#endif