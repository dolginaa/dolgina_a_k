#pragma once
#include<memory>

class QueueP
{
public:
	QueueP() = default;
	QueueP(const QueueP& other);
	~QueueP();
	void Push(const int& digit);
	size_t Size() const;
	int Top() const;
	bool isEmpty() const;
	void Pop();
	QueueP& operator=(const QueueP& rhs);
	QueueP& operator=(QueueP&& const rhs) noexcept;
	void Clear();
	void Swap(QueueP& other) noexcept;

private:
	struct Node
	{
		Node(int _value, std::unique_ptr<Node> next = nullptr);
		std::unique_ptr<Node> next;
		int data = 0;
	};

	size_t size = 0;
	std::unique_ptr<Node> head = nullptr;
};