#pragma once

#include <iostream>
#include <utility>
#include <functional>

// CMP is a "template-template", std::less is the default template
template<typename PriorityKey, typename Value, template<typename> typename CMP = std::less>
class PriorityQueue
{
private:
	using Pair = std::pair<PriorityKey, Value>;
	struct Node
	{
		Node* next;
		PriorityKey key;
		Value value;

		Node() = delete;

		template<typename... Args>
		Node(Node* next_, const PriorityKey& key_, Args&& ... value_args)
			: next(next_), key(key_), value(std::forward<Args>(value_args)...) {}
	};

	CMP<PriorityKey> m_cmp;
	Node* m_head;
	std::size_t m_size;

	void deep_copy(const PriorityQueue& rhs)
	{
		Node* aux = rhs.m_head;
		Node* current_node = nullptr;

		while (aux != nullptr)
		{
			Node* new_node = new Node(nullptr, aux->key, aux->value);

			if (current_node != nullptr)
			{
				// link the current node to the new one
				current_node->next = new_node;
			}
			else
			{
				// the first time, link the head
				m_head = new_node;
			}

			current_node = new_node;
			aux = aux->next;
		}
		m_size = rhs.m_size;
	}

public:
	PriorityQueue()
	{
		m_head = nullptr;
		m_size = 0;
	}

	PriorityQueue(PriorityQueue&& rhs) noexcept : PriorityQueue()
	{
		m_head = rhs.m_head;
		m_size = rhs.m_size;
		rhs.m_head = nullptr;
		rhs.m_size = 0;
	}

	PriorityQueue(const PriorityQueue& rhs) : PriorityQueue()
	{
		deep_copy(rhs);
	}

	~PriorityQueue()
	{
		clear();
	}

	PriorityQueue& operator=(const PriorityQueue& rhs)
	{
		if (this != &rhs)
		{
			clear();
			deep_copy(rhs);
		}
		return *this;
	}

	template<typename ...Args>
	void emplace(const PriorityKey& key, Args&& ...value_args)
	{
		Node* new_node = new Node(nullptr, key, std::forward<Args>(value_args)...);

		if (m_head == nullptr || !m_cmp(key, m_head->key))
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
			while (aux->next != nullptr && m_cmp(key, aux->next->key))
				aux = aux->next;

			Node* next = aux->next;
			aux->next = new_node;
			new_node->next = next;
		}
		++m_size;
	}

	void swap(PriorityQueue& rhs)
	{
		Node* head_aux = m_head;
		m_head = rhs.m_head;
		rhs.m_head = head_aux;

		std::size_t size_aux = m_size;
		m_size = rhs.m_size;
		rhs.m_size = size_aux;
	}

	void push(const PriorityKey& key, const Value& value)
	{
		emplace(key, value);
	}

	void push(const PriorityKey& key, Value&& value)
	{
		emplace(key, std::move(value));
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

	void clear()
	{
		while (!empty())
			pop();
	}

	// returns a std::pair
	[[nodiscard]] Pair front()
	{
		if (empty())
			throw std::out_of_range("Cannot return front from an empty queue");
		return std::make_pair(m_head->key, m_head->value);
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_size;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_head == nullptr;
	}

	bool operator==(const PriorityQueue& rhs) const noexcept
	{
		if (m_size != rhs.size())
			return false;

		Node* this_queue = m_head;
		Node* rhs_queue = rhs.m_head;

		while (this_queue != nullptr)
		{
			if (this_queue->key != rhs_queue->key || this_queue->value != rhs_queue->value)
				return false;

			this_queue = this_queue->next;
			rhs_queue = rhs_queue->next;
		}

		return true;
	}

	bool contains_value(const Value& value) const
	{
		Node* aux = m_head;

		while (aux != nullptr)
		{
			if (aux->value == value)
				return true;
			else
				aux = aux->next;
		}		

		return false;
	}

	bool contains_key(const PriorityKey& key) const
	{
		Node* aux = m_head;

		while (aux != nullptr)
		{
			if (aux->key == key)
				return true;
			else
				aux = aux->next;
		}

		return false;
	}

	std::vector<PriorityKey> get_all_keys() const
	{
		std::vector<PriorityKey> keys_vector;
		Node* aux = m_head;

		while (aux != nullptr)
		{
			keys_vector.push_back(aux->key);
			aux = aux->next;
		}

		return keys_vector;
	}

	std::vector<Value> get_all_values() const
	{
		std::vector<Value> values_vector;
		Node* aux = m_head;

		while (aux != nullptr)
		{
			values_vector.push_back(aux->value);
			aux = aux->next;
		}

		return values_vector;
	}

	friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& pq)
	{
		PriorityQueue::Node* aux = pq.m_head;
		while (aux != nullptr)
		{
			os << aux->key << ' ' << aux->value << '\n';
			aux = aux->next;
		}
		return os;
	}
};
