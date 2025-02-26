#include <cmath> // 修正math.h为cmath，并添加命名空间std
#include <cstring>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
class Student {
  private:
    std::string name;
    int age;

  public:
    // 返回引用，允许直接修改name
    std::string &getName() {
        return name;
    }

    // 返回常量引用，只允许读取
    const std::string &getName() const {
        return name;
    }
};
// 计算 n 的平方
void squareN(int &n) {
    n = std::pow(n, 2); // 修正std:pow为std::pow
}

std::tuple<std::string, std::string, std::string> getClassInfo() {
    std::string className = "CS106L";
    std::string buildingName = "Turing Auditorium";
    std::string language = "C++";
    return {className, buildingName, language};
}

// 方法 1: 使用 auto 结构化绑定（错误示例，不会修改 nums）
void shiftByValue(std::vector<std::pair<int, int>> &nums) {
    for (auto [num1, num2] : nums) { // num1 和 num2 是值拷贝
        num1++;                      // 修改的是拷贝的值
        num2++;
    }
}

// 方法 2: 使用 auto& 结构化绑定（正确示例，会修改 nums）
void shiftByReference(std::vector<std::pair<int, int>> &nums) {
    for (auto &[num1, num2] : nums) { // num1 和 num2 是引用
        num1++;                       // 直接修改 nums 内部的值
        num2++;
    }
}

// 方法 3: 传统的索引方式（正确示例，也会修改 nums）
void shiftByIndex(std::vector<std::pair<int, int>> &nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        nums[i].first++; // 直接修改 pair 内部的值
        nums[i].second++;
    }
}

void func(int &num) { // num 是左值引用
    num = 20;
}

int main() {
    // Uniform initialization of a vector
    std::vector<int> numbers{1, 2, 3, 4, 5};

    // Accessing vector elements
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    Student student;
    // 直接修改对象的内部数据
    student.getName() = "张三"; // 可以直接赋值，因为返回的是引用

    // 1. 用于数组索引
    std::vector<int> vec;
    for (size_t i = 0; i < vec.size(); i++) {
    }

    // 2. 表示大小或长度
    int array[] = {1, 2, 3, 4, 5};
    size_t length = strlen("hello");
    size_t array_size = sizeof(array);

    // 3. 容器相关操作
    std::string str = "anbc";
    size_t pos = str.find('a');
    std::cout << pos << std::endl;

    /*     auto classInfo = getClassInfo();
        std::string className = std::get<0>(classInfo);
        std::string buildingName = std::get<1>(classInfo);
        std::string language = std::get<2>(classInfo);

        std::cout << "Come to " << buildingName << " and join us for " << className << " to learn " << language << "!"
                  << std::endl; */

    auto [className, buildingName, language] = getClassInfo();

    std::cout << "Come to " << buildingName << " and join us for " << className << " to learn " << language << "!"
              << std::endl;

    int num = 2; // 修正 num 变量的定义
    squareN(num);
    std::cout << num << std::endl; // 修正std:cout为std::cout

    std::cout << "====================================================" << std::endl;

    std::vector<std::pair<int, int>> nums = {{1, 2}, {3, 4}, {5, 6}};

    shiftByValue(nums); // 不会真正修改 nums
    std::cout << "After shiftByValue: ";
    for (const auto &p : nums) {
        std::cout << "{" << p.first << "," << p.second << "} ";
    }
    std::cout << std::endl;

    shiftByReference(nums); // 修改 nums
    std::cout << "After shiftByReference: ";
    for (const auto &p : nums) {
        std::cout << "{" << p.first << "," << p.second << "} ";
    }
    std::cout << std::endl;

    shiftByIndex(nums); // 修改 nums
    std::cout << "After shiftByIndex: ";
    for (const auto &p : nums) {
        std::cout << "{" << p.first << "," << p.second << "} ";
    }
    std::cout << std::endl;

    int x = 10;
    func(x); // ✅ 正确，x 是左值

    // func(5); // ❌ 错误，5 是右值，不能传递给 `int&`

    int a = 10;
    const int &ref = a; // const 引用相当于给原来的变量加了一个“只有读取权限的别名”

    std::cout << ref << std::endl; // 输出 10

    a = 20;                        // 修改 a
    std::cout << ref << std::endl; // 输出 20，ref 也变化

    const std::vector<int> const_vec{1, 2, 3};
    //在 C++ 中，不能将一个 const 对象的引用赋值给非 const 引用
    // std::vector<int> &bad_ref{const_vec}; /// BAD

        return 0;
}