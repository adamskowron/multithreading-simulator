#include <random>
#include <thread>

void Wait(int d, int u)
{
	std::mt19937 rng {std::random_device{}()};
	static thread_local std::uniform_int_distribution<> dist(d,u);
	std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng)));
}

int RandinRange(int d, int u)
{
	std::mt19937 rng {std::random_device{}()};
	static thread_local std::uniform_int_distribution<> dist(d,u);
	return dist(rng);
}
