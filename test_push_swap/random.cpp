#include <iostream>
#include <random>
#include <string>

int	main(int argc, char *argv[]){
	int		min;
	int		max;
	int		len;

	min = -2147483648;
	max = __INT_MAX__;
	if (argc < 2)
		len = 100;
	else
		len = atoi(argv[1]);

	// 시드값을 얻기 위한 random_device 생성
	std::random_device rd;

	// random_device를 통해 난수 생성 엔진을 초기화한다.
	std::mt19937 gen(rd());

	// 0부터 1000까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의
	std::uniform_int_distribution<int> dis(min, max);

	for (int i = 0; i < len; i++)
		std::cout << dis(gen) << " ";
}
