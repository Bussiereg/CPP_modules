#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	PmergeMe<unsigned int, std::vector> contVect(argc, argv);
	PmergeMe<unsigned int, std::deque> contDeq(argc, argv);
 	struct timeval tv;

	gettimeofday(&tv, NULL);
	uint64_t ret = tv.tv_usec + tv.tv_sec * 1000000;
	gettimeofday(&tv, NULL);
	contVect.executeAlgo();
	uint64_t ret2 = tv.tv_usec + tv.tv_sec * 1000000;
	contVect.printInput();
	contVect.printSortedSequence();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << ret2 - ret << " us" << std::endl;

	gettimeofday(&tv, NULL);
	uint64_t ret3 = tv.tv_usec + tv.tv_sec * 1000000;
	contDeq.executeAlgo();
	gettimeofday(&tv, NULL);
	uint64_t ret4 = tv.tv_usec + tv.tv_sec * 1000000;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << ret4 - ret3 << " us" << std::endl;


	return 0;
}