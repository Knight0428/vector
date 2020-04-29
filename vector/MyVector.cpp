#include "MyVector.h"

int g_newCount;

MyVector::MyVector(size_t initSize)
	:capacity_(initSize+MIM_CAPACITY),size_(0)
{
	objects_ = new Integer[capacity_];
}

//const对象只能调用const成员函数
MyVector::MyVector(const MyVector & vec)
	:capacity_(vec.capacity_),size_(vec.size_)
{
	objects_ = new Integer[capacity_];
	for (size_t i = 0; i < size_; i++)
		objects_[i] = vec[i];
}

MyVector::~MyVector()
{
	delete[] objects_;
}

void MyVector::reserve(size_t newCapacity)
{
	//检查能否调整
	if (newCapacity < size_)
		return;
	//申请空间
	Integer *oldObjects = objects_;
	objects_ = new Integer[newCapacity];
	//拷贝
	for (rsize_t i = 0; i < size_; i++)
		objects_[i] = oldObjects[i];
	//memcpy(objects_, oldObjects, size() * sizeof(int));
	//释放旧的空间
	delete[] oldObjects;
	//修改容量
	capacity_ = newCapacity;
}

void MyVector::resize(size_t newSize)
{
	if (newSize > capacity_)
		reserve(newSize * 2);

	size_ = newSize;
}

size_t MyVector::size() const
{
	return size_;
}

size_t MyVector::capacity() const
{
	return capacity_;
}

void MyVector::insert(int pos, Integer & elem)
{
	if (empty())
		return;
	if (pos < 0 || (size_t)pos >= size_)
		return;
	//检查空间，不足则扩大
	if (size_ == capacity_)
		reserve(capacity_ * 2);
	//1  2  []  3  4，将pos位置后的元素往后移
	for (int i = size_; i > pos; i--)
	{
		objects_[i] = objects_[i - 1];
	}
	objects_[pos] = elem;
	size_++;
}

void MyVector::push_back(Integer & elem)
{
	//检查空间
	if (size_ == capacity_)
	{
		reserve(capacity_ * 2);
	}
	objects_[size_++] = elem;
}

Integer & MyVector::operator[](int index) const
{
	// TODO: 在此处插入 return 语句
	return objects_[index];
}

bool MyVector::empty() const
{
	return size_ == 0;
}

void MyVector::clear()
{
	size_ = 0;
}

void MyVector::erase(int pos)
{
	if (empty())
		return;
	if (pos < 0 || (size_t)pos >= size_)
		return;
	//1  [2]  3  4，将元素往前移
	for (size_t i = pos; i < size_ - 1; i++)
	{
		objects_[i] = objects_[i + 1];
	}
	size_--;
}

void MyVector::pop_back()
{
	size_--;
}

Integer & MyVector::back()
{
	// TODO: 在此处插入 return 语句
	return objects_[size() - 1];
}

Integer & MyVector::front()
{
	// TODO: 在此处插入 return 语句
	return objects_[0];
}

MyVector & MyVector::operator=(const MyVector & vec)
{
	// TODO: 在此处插入 return 语句
	
	//先清空
	clear();
	//遍历插入
	for (size_t i = 0; i < vec.size(); i++)
		objects_[i] = vec[i];

	return *this;
}

void MyVector::operator+=(const MyVector & vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		push_back(vec[i]);
}
