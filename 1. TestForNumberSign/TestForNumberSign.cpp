#include <iostream>
#include <cstdlib>

// ���Բ��� # �ŵ�Ч��
#define NO_NUMBER_SIGN(x) x

// ����һ�� # �ŵ�Ч��
#define SINGLE_NUMBER_SIGN(x) #x

// �������� # �ŵ�Ч��
#define DOUBLE_NUMBER_SIGN(x, y) x##y

int main()
{
	// ���Բ��� # �ŵ�Ч����hello ����˫���ű���error C2065: ��hello��: δ�����ı�ʶ����
	std::cout << NO_NUMBER_SIGN("hello") << std::endl;
	// ����һ�� # �ŵ�Ч����world �Ӳ���˫���Ŷ����ԣ���Ϊ # �����ַ�����
	std::cout << SINGLE_NUMBER_SIGN(world) << std::endl;
	// �������� # �ŵ�Ч����������������
	std::cout << DOUBLE_NUMBER_SIGN("wang", "ying") << std::endl;
	system("pause");
	return 0;
}