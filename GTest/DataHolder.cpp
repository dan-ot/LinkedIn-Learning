#include "DataHolder.h"

void DataHolder::add_data(int data)
{
	queue_->enqueue(data);
}

int DataHolder::get_data()
{
	return queue_->dequeue();
}
