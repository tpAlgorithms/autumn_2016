#include <vector>
#include <cstdio> 
//#include <algorithm>

typedef int data_t;

bool less(const data_t &lhs, const data_t &rhs) {
    return lhs < rhs;
}

int cmp(const data_t &lhs, const data_t &rhs) {
    if (lhs < rhs) {
        return -1;
    } else if (lhs > rhs) {
        return 1;
    } else {
        return 0;
    }
}

// a < b   less(a, b)
// a > b   less(b, a)
// a <= b  !less(b, a)
// a >= b  !less(a, b)
// a == b  !less(a, b) && !less(b,a)


void heap_sift_down(data_t *data, size_t size, size_t head) {
    while (2 * head + 1 < size) {
        size_t child = 2 * head + 1;
        if (child + 1 < size && data[child + 1] > data[child]) {
            child += 1;
        }
        if (data[head] >= data[child]) {
            return;
        }
        std::swap(data[head], data[child]);
        head = child;
    }
}

void heap_make(data_t *data, size_t size) {
    for (size_t child = size -1; ; child -= 2) {
        heap_sift_down(data, size, (child - 1) / 2);
        if (child <= 2) break;
    }
}
void sort(data_t *begin, data_t *end) {
    size_t size = end - begin;
    heap_make(begin, size);
    for (; size > 1;) {
        --size;
        std::swap(begin[0], begin[size]);
        heap_sift_down(begin, size, 0);
    }
}

void sort(data_t *data, size_t size) {
    sort(data, &data[size]);
}

int main() {
    std::vector<data_t> data;
        
    int value;
    while (scanf("%d", &value) == 1) {
        data.push_back(value);
    }

    sort(&data[0], data.size());

    for (size_t pos = 0; pos < data.size(); ++pos) {
        printf("%d\n", data[pos]);
    }
    
    return 0;
}

