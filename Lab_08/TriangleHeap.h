#pragma once
class TriangleHeap
{
	//dynamic
private:
	float *mBase;
	float *mHeight;
public:
	TriangleHeap();
	~TriangleHeap();

	TriangleHeap& operator=(const TriangleHeap&);

	TriangleHeap(const TriangleHeap& input)
	{
		*mBase = *input.mBase;
		*mHeight = *input.mHeight;
	}

	void SetHeight(float h)
	{
		*mHeight = h;
	}

	void SetBase(float b)
	{
		*mBase = b;
	}

	float GetArea()
	{
		float area = ((*mBase * *mHeight) / 2);
		return area;
	}

};

