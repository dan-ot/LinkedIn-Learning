#include "Iterator.h"

int ForwardsIterator::next()
{
    int current = numbers.at(currentPosition);
    currentPosition += 1;
    return current;
}

bool ForwardsIterator::isFinished()
{
    return currentPosition >= numbers.size();
}

int BackwardsIterator::next()
{
    int current = numbers.at(currentPosition);
    currentPosition -= 1;
    return current;
}

bool BackwardsIterator::isFinished()
{
    return currentPosition < 0;
}

NumberIterator* NumberCollection::getForwardIterator()
{
    return new ForwardsIterator(numbers);
}

NumberIterator* NumberCollection::getBackwardIterator()
{
    return new BackwardsIterator(numbers);
}
