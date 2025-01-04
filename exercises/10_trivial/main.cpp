#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16]{0,1};
    int cached=2;
    
    // 重载 [] 运算符，使其能够访问 `cache` 数组
    unsigned long long &operator[](int index) {
        return cache[index];
    }
    /*
    // const 重载版本，支持在常量上下文中使用
    const unsigned long long &operator[](int index) const {
        return cache[index];
    }
    */
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    //int cached = cache.cached;
    for (; cache.cached <= i; ++cache.cached) {
        cache[cache.cached] = cache[cache.cached - 1] + cache[cache.cached - 2];
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib;
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
