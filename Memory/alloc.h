//
// Created by 27673 on 2022/7/21.
//

#ifndef TINYWEB_ALLOC_H
#define TINYWEB_ALLOC_H

#include <cstddef>
#include <cstdlib>


enum {
    ALIGN_ = 8
};  //上调边界
enum {
    MAX_BYTES_ = 128
};
enum {
    NFREELISTS_ = MAX_BYTES_ / ALIGN_
};


template<int inst>
class alloc {
public:
    static void *allocate(size_t size);

    static void deallocate(void *ptr, size_t n);

    static size_t get_heap_size(){return heap_size;}
private:
    union obj {
        union obj *free_list_link;
        char client_data[1];
    };
private:
    static size_t ROUND_UP(size_t size) {  //边界上调函数
        return ((size + ALIGN_ - 1) & ~(ALIGN_ - 1));
    }

    static size_t FREELIST_INDEX(size_t bytes) {
        return (ROUND_UP(bytes) / ALIGN_ - 1);
    }

    static void *refill(size_t n);

    static char *chunk_alloc(size_t size, int &nobjs);

    static obj *volatile free_list[NFREELISTS_];
    static char *start_free;
    static char *end_free;
    static size_t heap_size;
};

template<int inst>
typename alloc<inst>::obj *volatile
        alloc<inst>::free_list[NFREELISTS_] = {nullptr};

template<int inst>
char *alloc<inst>::start_free = nullptr;

template<int inst>
char *alloc<inst>::end_free = nullptr;

template<int inst>
size_t alloc<inst>::heap_size = 0;

template<int inst>
void *alloc<inst>::allocate(size_t size) {
    if (size > MAX_BYTES_) {
        return malloc(size);
    }
    auto result = free_list[FREELIST_INDEX(size)];
    if (nullptr == result) {
        void *res = refill(ROUND_UP(size));
        return res;
    }
    free_list[FREELIST_INDEX(size)] = result->free_list_link;
    return nullptr;
}

template<int inst>
void alloc<inst>::deallocate(void *ptr, size_t n) {
    if (n > MAX_BYTES_) {
        free(ptr);
    }
    obj *qtr = (obj *) ptr;
    qtr->free_list_link = free_list[FREELIST_INDEX(n)];
    free_list[FREELIST_INDEX(n)] = qtr;
}

template<int inst>
void *alloc<inst>::refill(size_t size) {  //n 为已经调整好的边界
    int nobjs = 20;
    char *ptr = chunk_alloc(size, nobjs);
    if (nobjs == 1) {
        return ptr;
    }
    free_list[FREELIST_INDEX(size)] = (obj *) (ptr + size);
    obj *current_obj, *next_obj = (obj *) (ptr + size);
    int cnt = nobjs - 2;
    while (cnt-- > 0) {
        current_obj = next_obj;
        next_obj = (obj *) ((char *) next_obj + size);
        current_obj->free_list_link = next_obj;
    }
    next_obj->free_list_link = nullptr;
    return ptr;
}

template<int inst>
char *alloc<inst>::chunk_alloc(size_t size, int &nobjs) {
    size_t left_bytes = end_free - start_free;
    size_t need_bytes = size * nobjs;
    char *res = start_free;
    if (left_bytes > need_bytes) {
        start_free += need_bytes;
        return res;
    } else if (left_bytes >= size) {
        nobjs = (int) (left_bytes / size);
        start_free += (nobjs * size);
        return res;
    } else {
        //扩充战备池  并重新 获取内存
        size_t bytes_to_get = 2 * need_bytes + ROUND_UP(heap_size >> 4);
        //如果 手上还有剩余  就 添加到链表
        if (left_bytes > 0) {
            //手上剩余的内存 一定为 8 的整数倍
            ((obj *) (start_free))->free_list_link = free_list[FREELIST_INDEX(left_bytes)];
            free_list[FREELIST_INDEX(left_bytes)] = (obj *) start_free;
            start_free += left_bytes;
        }
        start_free = (char *) malloc(bytes_to_get);
        if (nullptr == start_free) {
            for (size_t si = size; si <= MAX_BYTES_; si += ALIGN_) {
                if (free_list[FREELIST_INDEX(si)] != nullptr) {
                    start_free = (char *) free_list[FREELIST_INDEX(si)];
                    end_free += si;
                    free_list[FREELIST_INDEX(si)] = ((obj *) start_free)->free_list_link;
                    return chunk_alloc(size, nobjs);
                }
            }
            end_free = nullptr;
            //FIXME:  在这里要抛出bad::alloc 异常
        }
        heap_size += bytes_to_get;
        end_free = start_free + bytes_to_get;
        return chunk_alloc(size, nobjs);
    }
}


#endif //TINYWEB_ALLOC_H
