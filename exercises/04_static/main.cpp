#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
// 答：在修饰变量的时候，static 修饰的静态局部变量只执行初始化一次，而且延长了局部变量的生命周期，
// 直到程序运行结束以后才释放。
// static 修饰一个函数，则这个函数的只能在本文件中调用，不能被其他文件调用。
static int func(int param) {
    static int static_ = param;
    //std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect"); //static不能被赋值为4
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
