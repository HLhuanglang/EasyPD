#include "sigleton.h"

#include <iostream>

class test_demo {
	friend class singleton<test_demo>;
public:
	void hello() {
		std::cout << "hello!" << std::endl;
	}
};

int main() {
	singleton<test_demo>::get_instance()->hello();
	return 0;
}