#include <iostream>

class Box
{
private:
	int val;
public:
	Box() = default;
	Box(int val) : val{ val }
	{}
	Box operator +=(Box obj)
	{
		this->val += obj.val;
		return *this;
	}
	
	Box operator /(int val)
	{
		this->val /= val;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Box& obj);
};

std::ostream& operator<<(std::ostream& out, const Box& obj)
{
	out << obj.val;
	return out;
}

template <typename T>
T average(T* arr, int count)
{
	T sum{};

	for (int i{}; i < count; ++i)
		sum += arr[i];

	T result = sum / count;

	return result;
}

int main()
{
	Box* arr = new Box[5]{ Box{1}, Box{3}, Box{6}, Box{2}, Box{3} };
	std::cout << average(arr, 5);
}