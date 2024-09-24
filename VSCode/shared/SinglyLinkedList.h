#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: 연결 리스트 복사
		// auto* current_node = list.first_;
		// auto* current_node_copy = this->first_;
		// if (current_node)
		// {
		// 	this->first_ = new SinglyLinkedList::Node();
		// 	current_node_copy = this->first_;
		// 	current_node_copy->item = current_node->item;
		// }
		// while (current_node->next)
		// {
		// 	current_node_copy->next = new SinglyLinkedList::Node();
		// 	current_node_copy->next->item = current_node->next->item;
		// 	current_node = current_node->next;
		// 	current_node_copy = current_node_copy->next;
		// }

		auto *current_node = list.first_;
		while(current_node)
		{
			PushBack(current_node->item);
			current_node = current_node->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
		auto *current_node = this->first_;
		while (current_node)
		{
			auto *tmp = current_node;
			current_node = current_node->next;
			delete tmp;
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환
		auto *node = this->first_;
		while (node)
		{
			size++;
			node = node->next;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO: 수정
	}

	T Back()
	{
		assert(first_);
		auto *node = this->first_;
		// for (int i(0); i < this->Size() - 1; ++i)
		// {
		// 	node = node->next;
		// }
		while(node->next)
			node = node->next;

		return node->item; // TODO: 수정
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
		// auto *node = this->first_;
		// if (node == nullptr)
		// 	return nullptr;
		// if (node->item == item)
		// 	return node;
		// else
		// {
		// 	for (int i(0); i < this->Size() - 1; ++i)
		// 	{
		// 		node = node->next;
		// 		if (node->item == item)
		// 			return node;
		// 	}
		// }

		// alternative
		auto *current = first_;
		while(current)
		{
			if(current->item == item)
				return current;
			
			current = current->next;
		}
		return current;
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
		auto *next_node = node->next;
		node->next = new SinglyLinkedList::Node();
		node->next->item = item;
		node->next->next = next_node;
	}

	void Remove(Node* n)
	{
		if (first_ == n)
		{
			first_ = first_->next;
			delete n;
			return;
		}
		assert(first_);

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
		auto *prev_node = this->first_;
		while (prev_node->next)
		{
			if(prev_node->next == n)
			{
				break;
			}
			prev_node = prev_node->next;
		}
		//update prev_node->next
		prev_node->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		// TODO:
		auto *node = new SinglyLinkedList::Node();
		node->item = item;

		// 연결 관계 정리
		// TODO:
		node->next = first_;
		first_ = node;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			// TODO:
			// find the final node
			// auto *node = first_;
			// for (int i(0); i < this->Size() - 1; ++i)
			// 	node = node->next;
			// node->next = new SinglyLinkedList::Node();
			// node->next->item = item;

			//
			auto *node = first_;
			while(node->next)
				node = node->next;

			auto *new_node = new Node();
			new_node->item = item;
			new_node->next = nullptr;

			node->next = new_node;
		}
		else
		{
			// TODO:
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

		// TODO: 메모리 삭제
		auto *tmp = first_;
		first_ = first_->next;
		delete tmp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다. (WHY??????)
		if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}

		assert(first_);

		// TODO: 메모리 삭제
		// auto *node = first_;
		// for (int i(0); i < this->Size() - 2; ++i)
		// 	node = node->next;
		
		// delete node->next;
		// node->next = nullptr;

		//alternative
		auto *second_last = first_;
		while (second_last->next->next)
			second_last = second_last->next;
		
		Node* temp = second_last->next;
		second_last->next = second_last->next->next;

		delete temp;
	}

	void Reverse() // TODO: *******************!!!!!!!!!!!!!!!!!!!!!!!!!review this concept!!!!!!!!!!!!!!!!!!!!!!!***************************
	{
		// TODO: 
		// iterate through the middle node
		// int size = this->Size();
		// auto *final_node = this->first_; // save a final node (save final node ptr)
		// for (int i(0); i < size; ++i){
		// 	auto *node = this->first_;
		// 	auto *prev_node = this->first_;
		// 	while (node->next)
		// 	{
		// 		prev_node = node;
		// 		node = node->next;
		// 	}
		// 	if (i == 0)
		// 		final_node = node;
		// 	node->next = prev_node;
		// 	prev_node->next = nullptr;
		// }
		// this->first_ = final_node;

		// alternative
		Node *current = first_;
		Node *prev = nullptr;

		while (current)
		{
			Node *tmp = prev;
			prev = current;
			current = current->next;
			prev->next = tmp;
		}
		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};