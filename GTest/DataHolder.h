#pragma once

class QueueInterface {
public:
	virtual ~QueueInterface() {};
	virtual void enqueue(int data) = 0;
	virtual int dequeue() = 0;
};

class DataHolder {
public:
	DataHolder(QueueInterface* queue) : queue_(queue) {};
	void add_data(int data);
	int get_data();
protected:
	QueueInterface* queue_;
};