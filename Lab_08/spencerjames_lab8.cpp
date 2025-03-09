#include <iostream>
#include <vector>

#include "TriangleStack.h"
#include "TriangleHeap.h"

int AddNumbersReturnInt(int* a, int* b);
void AddNumbersReturnVoid(int a, int b, int* sum);
void SwapValues(int* a, int* b);

int main()
{ 
	TriangleStack* t1 = new TriangleStack;
	t1->SetBase(40);
	t1->SetHeight(50);

	TriangleStack* t2 = new TriangleStack;
	t2->SetBase(15);
	t2->SetHeight(25);

	std::vector<TriangleStack*> triangle;
	triangle.push_back(t1);
	triangle.push_back(t2);

	for (size_t i = 0; i < triangle.size(); i++)
	{
		std::cout << "\nThe area of Triangle " << i + 1 << " is ";
		std::cout << triangle[i]->GetArea() << "\n";
	}

	TriangleHeap* t3 = new TriangleHeap;
	t3->SetBase(25);
	t3->SetHeight(45);

	TriangleHeap* t4 = new TriangleHeap;
	t4->SetBase(5);
	t4->SetHeight(5);

	std::vector<TriangleHeap*> triangle2;
	triangle2.push_back(t3);
	triangle2.push_back(t4);

	for (size_t i = 0; i < triangle2.size(); i++)
	{
		std::cout << "\nThe area of Triangle " << i + 3 << " is ";
		std::cout << triangle2[i]->GetArea() << "\n";
	}

}

int AddNumbersReturnInt(int* a, int* b)
{
	int c;
	c = (*a + *b);
	return c;
}

void AddNumbersReturnVoid(int a, int b, int* sum)
{
	*sum = a + b;
}

void SwapValues(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

