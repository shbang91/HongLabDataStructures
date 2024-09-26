﻿#pragma once

#include <iostream>
#include <fstream>
#include <string> // BinaryTree 출력

#include "Queue.h"
#include "Stack.h"

template<typename T>
class BinaryTree
{
public:
	struct Node
	{
		T item = T();
		Node* left = nullptr; // Left child
		Node* right = nullptr; // Right child
	};

	// 디버깅 도구: 큐에서 주소 대신에 아이템 출력
	class MyQueue : public Queue<Node*>
	{
	public:
		void Print()
		{
			using namespace std;

			for (int i = (this->front_ + 1) % this->capacity_; i != (this->rear_ + 1) % this->capacity_; i = (i + 1) % this->capacity_)
				cout << this->queue_[i]->item << " ";
			cout << endl;
		}
	};

	// 디버깅 도구: 스택에서 주소 대신에 아이템 출력
	class MyStack : public Stack<Node*>
	{
	public:
		void Print()
		{
			using namespace std;

			for (int i = 0; i < this->Size(); i++)
				cout << this->stack_[i]->item << " ";
			cout << endl;
		}
	};

	BinaryTree() {}

	BinaryTree(Node* root)
	{
		root_ = root;
	}

	bool IsEmpty()
	{
		return root_ == nullptr;
	}

	void Visit(Node* node)
	{
		using namespace std;
		cout << node->item << " "; // 수행하고 싶은 작업 구현(여기서는 출력)
	}

	int Sum()
	{
		return Sum(root_);
	}

	int Sum(Node* node)
	{
		if (!node)
			return 0;
		int sum = node->item;
		if (node->left)
			sum += Sum(node->left);
		if (node->right)
			sum += Sum(node->right);

		// alternative
		// return node->item + Sum(node->left) + Sum(node->right);
		
		return sum; // TODO:
	}

	int Height()
	{
		return Height(root_);
	}

	int Height(Node* node)
	{
		int left_height(1);
		int right_height(1);
		if (node->left)
		{
			left_height += Height(node->left);
		}
		if (node->right)
		{
			right_height += Height(node->right);
		}
		
		return left_height >= right_height ? left_height : right_height; // TODO:
	}

	~BinaryTree()
	{
		DeleteTree(root_);
	}

	void DeleteTree(Node* node)
	{
		if (node)
		{
			// TODO: 힌트 Post-order
			DeleteTree(node->left);
			DeleteTree(node->right);
			std::cout << "delete node " << node->item << std::endl;
			delete node;
		}
	}

	void Preorder() { Preorder(root_); }
	void Preorder(Node* node)
	{	
		// TODO:
		if (node){
		// 1. root
		Visit(node);
		// 2. left
		Preorder(node->left);
		// 3. right
		Preorder(node->right);
		}

	};

	void Inorder() { Inorder(root_); }
	void Inorder(Node* node)
	{
		// TODO:
		if (node){
		// 1. left
		Inorder(node->left);

		// 2. print
		Visit(node);
		
		// 3. right
		Inorder(node->right);
		}

	}

	void Postorder() { Postorder(root_); }
	void Postorder(Node* node)
	{
		// TODO:
		if (node){
		// 1. left	
		Postorder(node->left);

		// 2. right
		Postorder(node->right);

		// 3. print
		Visit(node);
		}
	}

	void LevelOrder() // *********************!!!!!!!!!!!!!Review!!!!!!!!!!!!!!*************************
	{
		Queue<Node*> q; // 힌트: MyQueue q;
		Node* current = root_;
		while (current)
		{
			Visit(current);
			// TODO:
			if(current->left)
				q.Enqueue(current->left);
			if(current->right)
				q.Enqueue(current->right);
			if(q.IsEmpty()) return;

			current = q.Front();
			q.Dequeue();
		}
	}

	void IterPreorder()
	{
		if (!root_) return;

		Stack<Node*> s; // 힌트: MyStack q;
		s.Push(root_);

		while (!s.IsEmpty())
		{
			// TODO:
			Node* current = s.Top();
			s.Pop();

			Visit(current);

			if(current->right)
				s.Push(current->right);
			if(current->left)
				s.Push(current->left);


		}
	}

	void IterInorder()
	{
		if (!root_) return;

		Stack<Node*> s;

		Node* current = root_;
		while (current || !s.IsEmpty())
		{
			// TODO:
			while(current)
			{
				s.Push(current);
				current = current->left;
			}
			current = s.Top();
			s.Pop();

			Visit(current);

			current = current->right;
		}
	}

	void IterPostorder()
	{
		if (!root_) return;

		Stack<Node*> s1, s2;
		s1.Push(root_);

		while (!s1.IsEmpty())
		{
			// TODO:
			Node* node = s1.Top();
			s1.Pop();

			s2.Push(node);

			if(node->left)
				s1.Push(node->left);
			if(node->right)
				s1.Push(node->right);
		}

		while (!s2.IsEmpty())
		{
			// TODO:
			Node* node = s2.Top();
			s2.Pop();

			Visit(node);
		}
	}

	void Print2D();
	void PrintLevel(int n);
	void DisplayLevel(Node* p, int lv, int d);

protected:
	Node* root_ = nullptr;
};

// 디버깅 편의 도구
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template<typename T>
void BinaryTree<T>::Print2D()
{
	using namespace std;
	int i = 0;
	while (i < Height()) {
		PrintLevel(i);
		i++;
		cout << endl;
	}
}

template<typename T>
void BinaryTree<T>::PrintLevel(int n) {
	using namespace std;
	Node* temp = root_;
	int val = (int)pow(2.0, Height() - n + 1.0);
	cout << setw(val) << "";
	DisplayLevel(temp, n, val);
}

template<typename T>
void BinaryTree<T>::DisplayLevel(Node* p, int lv, int d) {
	using namespace std;
	int disp = 2 * d;
	if (lv == 0) {
		if (p == NULL) {
			cout << "   ";
			cout << setw(disp - 3) << "";
			return;
		}
		else {
			int result = ((p->item <= 1) ? 1 : (int)log10(p->item) + 1);
			cout << " " << p->item << " ";
			cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
		}
	}
	else
	{
		if (p == NULL && lv >= 1) {
			DisplayLevel(NULL, lv - 1, d);
			DisplayLevel(NULL, lv - 1, d);
		}
		else {
			DisplayLevel(p->left, lv - 1, d);
			DisplayLevel(p->right, lv - 1, d);
		}
	}
}
