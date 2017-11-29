#include <iostream>
#include <cstdlib>

// 测试不带 # 号的效果
#define NO_NUMBER_SIGN(x) x

// 测试一个 # 号的效果
#define SINGLE_NUMBER_SIGN(x) #x

// 测试两个 # 号的效果
#define DOUBLE_NUMBER_SIGN(x, y) x##y

int main()
{
	// 测试不带 # 号的效果：hello 不加双引号报错（error C2065: “hello”: 未声明的标识符）
	std::cout << NO_NUMBER_SIGN("hello") << std::endl;
	// 测试一个 # 号的效果：world 加不加双引号都可以，因为 # 将其字符串化
	std::cout << SINGLE_NUMBER_SIGN(world) << std::endl;
	// 测试两个 # 号的效果：连接两个对象
	std::cout << DOUBLE_NUMBER_SIGN("wang", "ying") << std::endl;
	system("pause");
	return 0;
}