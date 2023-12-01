#include "QueueP.h"
#include <stdexcept>

QueueP::QueueP(const QueueP& other)
{
	head = nullptr;
	size = 0;
	if(!other.isEmpty())
	{
		auto cur_node = other.head.get();
		while (cur_node != nullptr) 
		{
			Push(cur_node->data);
			cur_node = cur_node->next.get();
		}
	}
}

QueueP::~QueueP()
{
	Clear();
}

void QueueP::Push(const int& digit)
{
	std::unique_ptr<Node> new_node = std::make_unique<Node>(digit);
	auto cur_node = head.get();
	if (Size() == 0)
	{
		head = std::move(new_node);
		size++;
	}
	else 
	{
		
		if (cur_node->data >= digit) 
		{
			new_node->next = std::move(head);
			head = std::move(new_node);
			size++;
			return;
		}
		if (cur_node->data <= digit && cur_node->next == nullptr) 
		{
			cur_node->next = std::move(new_node);
			size++;
			return;
		}

		while (cur_node->next != nullptr) 
		{
			if (cur_node->next != nullptr && cur_node->next->data >= digit)
			{
				new_node->next = std::move(cur_node->next);
				cur_node->next = std::move(new_node);
				size++;
				break;
			}
			else
			{
				cur_node = cur_node->next.get();
			}
			if (cur_node->next == nullptr)
			{
				cur_node->next = std::move(new_node);
				size++;
				break;
			}
		}
	}
}

size_t QueueP::Size() const
{
	return this->size;
}

int QueueP::Top() const
{
	return this->head->data;
}

bool QueueP::isEmpty() const
{
	return !(this->Size());
}

void QueueP::Pop() 
{
	if(Size() == 0)
	{
		throw std::invalid_argument("Queue is empty");
	}
	head.reset(head->next.get());
	size--;
}

QueueP& QueueP::operator=(const QueueP& rhs)
{
	if (Size() != 0)
	{
		Clear();
	}

	if (rhs.isEmpty()) 
	{
		Clear();
		return *this;
	}

	auto cur_node = rhs.head.get();
	while(cur_node != nullptr)
	{
		Push(cur_node->data);
		cur_node = cur_node->next.get();
	}
	return *this;
}

QueueP& QueueP::operator=(QueueP&& const rhs) noexcept
{
	rhs.Swap(*this);
	return *this;
}

void QueueP::Clear()
{
	while (size > 0)
	{
		Pop();
	}
}

void QueueP::Swap(QueueP& other) noexcept
{
	std::swap(head, other.head);
	std::swap(size, other.size);
}

QueueP::Node::Node(int _value, std::unique_ptr<Node> _next) 
{
	data = _value;
	next = std::move(_next);
}
