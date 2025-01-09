#pragma once
#include <vector>

class NumberIterator
{
public:
	virtual int next() = 0;
	virtual bool isFinished() = 0;
};

class ForwardsIterator : public NumberIterator {
	int currentPosition;
	std::vector<int>& numbers;
public:
	ForwardsIterator(std::vector<int>& numbers)
		: currentPosition(0), numbers(numbers) {
	};
	int next() override;
	bool isFinished() override;
};

class BackwardsIterator : public NumberIterator {
	int currentPosition;
	std::vector<int>& numbers;
public:
	BackwardsIterator(std::vector<int>& numbers)
		: currentPosition(numbers.size() - 1), numbers(numbers) {
	};
	int next() override;
	bool isFinished() override;
};

class NumberCollection {
	std::vector<int> numbers;
public:
	NumberCollection(const std::vector<int>& numbers) : numbers(numbers) {};
	NumberIterator* getForwardIterator();
	NumberIterator* getBackwardIterator();
};