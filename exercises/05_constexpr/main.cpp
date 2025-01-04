#include "../exercise.h"
// 答：问题是递归深度超出了编译器的 constexpr 限制，导致编译失败。让fibonacci的计算发生在运算时而不是编译时
constexpr unsigned long long fibonacci(int i) {//此处constepr也去掉
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 40; //原来是90
    //constexpr auto ANS = fibonacci(ANS_N); //改之前
    auto ANS = fibonacci(ANS_N); //改之后，保留90的输入能跑但会很慢
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
