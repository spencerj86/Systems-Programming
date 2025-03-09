#include "TriangleHeap.h"

TriangleHeap::TriangleHeap()
{
	mHeight = new float(0);
	mBase = new float(0);
}

TriangleHeap::~TriangleHeap()
{
	delete mHeight;
	delete mBase;
}

TriangleHeap& TriangleHeap::operator=(const TriangleHeap& other)
{
	*mBase = *other.mBase;
	*mHeight = *other.mHeight;
	return *this;
}
//copy constructor