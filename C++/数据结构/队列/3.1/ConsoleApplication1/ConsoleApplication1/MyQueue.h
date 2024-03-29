#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue
{
public:
	MyQueue(int queueCapacity);
	virtual ~MyQueue();
	void ClearQueue();
	bool QueueEmpty() const;
	int QueueLength() const;
	bool QueueFull() const;
	bool EnQueue(int element);
	bool DeQueue(int &element);
	void QueueTraverse();
private:
	int *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;

};


#endif