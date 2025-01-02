#pragma once

#include <iostream>
#include <utility>

// CMP is a "template-template", std::less is the default template
template<typename PriorityKey, typename Value, template<typename> typename CMP = std::less>
class PriorityQueue
{
private:
	using Pair = std::pair<PriorityKey, Value>;
	struct Node
	{
		Node* next;
		Pair pair;

		Node() = delete;
		Node(const Pair& pair_, Node* next_)
			: pair(pair_), next(next_) {}
	};

	CMP<PriorityKey> m_cmp;
	Node* m_head;
	std::size_t m_size;

public:
	PriorityQueue()
	{
		m_head = nullptr;
		m_size = 0;
	}

	void push(const Pair& pair)
	{
		Node* new_node = new Node(pair, nullptr);

		if (m_head == nullptr || !m_cmp(pair.first, m_head->pair.first))
		{
			// for example, using std::greater, if the new private-key
			// is not greater than the first one, then insert it at the beginning
			new_node->next = m_head;
			m_head = new_node;
		}
		else
		{
			// find the right place to insert the new element, for example
			// using std::greater, if the new private-key is greater than every
			// element (aux->next is nullptr) then insert at the end.
			// Due we are using aux->next always, the first element's key will not be compared
			// against the new value's key so the previous "if" is strictly needed
			Node* aux = m_head;
			while (aux->next != nullptr && m_cmp(pair.first, aux->next->pair.first))
				aux = aux->next;

			Node* next = aux->next;
			aux->next = new_node;
			new_node->next = next;
		}
		++m_size;
	}

	void pop()
	{
		if (empty())
			throw std::out_of_range("Cannot pop from an empty queue");

		Node* aux = m_head;
		m_head = m_head->next;
		delete aux;
		--m_size;
	}

	const Pair& front()
	{
		// In order to prevent keys modification, an non-const overload of this
		// function must not be implemented
		if (empty())
			throw std::out_of_range("Cannot return front from an empty queue");
		return m_head->pair;
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_size;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_head == nullptr;
	}

	friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& pq)
	{
		PriorityQueue::Node* aux = pq.m_head;
		while (aux != nullptr)
		{
			os << aux->pair.first << ' ' << aux->pair.second << '\n';
			aux = aux->next;
		}
		return os;
	}
};
