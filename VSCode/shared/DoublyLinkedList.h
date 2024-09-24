#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO:
		Node *current = first_;
		while(current)
		{
			PopFront();
			current = current->right;
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr; // TODO:
	}

	int Size()
	{
		int size = 0;

		// TODO:
		Node *current = first_;
		while(current)
		{
			size++;
			current = current->right;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
			cout << first_->item;
			while (current->right)
			{
				cout << current->right->item;
				current = current->right;
			}
			cout << endl;

			cout << "Backward: ";
			cout << current->item;
			while (current->left)
			{
				cout << current->left->item;
				current = current->left;
			}
			
			// TODO:
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		Node* current = first_;
		while(current)
		{
			if(current->item == item)
				return current;
			current = current->right;
		}
		return nullptr; // TODO:
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
			Node* new_node = new Node();
			new_node->item = item;

			Node* tmp_right = node->right;
			node->right = new_node;
			new_node->left = node;
			new_node->right = tmp_right;
			tmp_right->left = new_node;
		}
	}

	void PushFront(T item)
	{
		// TODO:
		Node* new_node = new Node();
		new_node->item = item;
		new_node->right = first_;
		if(first_)
			first_->left = new_node;
		first_ = new_node;
		new_node->left = nullptr;
	}

	void PushBack(T item)
	{
		// TODO:
		if(first_)
		{
			Node* new_node = new Node();
			new_node->item = item;

			Node* last_node = first_;
			while(last_node->right)
				last_node = last_node->right;
			last_node->right = new_node;
			new_node->left = last_node;
			new_node->right = nullptr;
		}
		else{
			PushFront(item);
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO:
		Node *temp = first_;
		first_ = first_->right;
		if (first_) first_->left = nullptr;
		delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.
		assert(first_);
		// TODO:

		Node* current = first_;

		if(current->right)
		{
			while(current->right->right)
				current = current->right;
			
			Node* temp = current->right;
			current->right = current->right->right;

			delete temp;

		} else {
			delete first_;
			first_ = nullptr;
		}
	}

	void Reverse()
	{
		// TODO:
		if (IsEmpty())
			return;
		else
		{
			Node* current = first_;
			Node* prev = nullptr;

			while(current)
			{
				prev = current;
				current = current->right;
				std::swap(prev->left, prev->right);
			}
			first_ = prev;
		}
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO:
	}

	T Back()
	{
		assert(first_);
		Node* current = first_;
		while(current->right)
			current = current->right;

		return current->item; // TODO:
	}

protected:
	Node* first_ = nullptr;
};