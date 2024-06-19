#include "Serialization.hpp"

int main(void){
	Data info;
	info.username = "gbussier";
	info.code = "testcode";

	uintptr_t buf = Serialization::serialize(&info);
	std::cout << "->serialization of the data: " << buf << std::endl << std::endl;

	Data *msg = Serialization::deserialize(buf);
	std::cout << "->deserialization of the data: " << std::endl;
	std::cout << "---username: " << msg->username << std::endl;
	std::cout << "---code: " << msg->code << std::endl;

	return 0;
}