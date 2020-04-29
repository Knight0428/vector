#include "MyVector.h"

int g_newCount;

MyVector::MyVector(size_t initSize)
	:capacity_(initSize+MIM_CAPACITY),size_(0)
{
	objects_ = new Integer[capacity_];
}

//const����ֻ�ܵ���const��Ա����
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
	//����ܷ����
	if (newCapacity < size_)
		return;
	//����ռ�
	Integer *oldObjects = objects_;
	objects_ = new Integer[newCapacity];
	//����
	for (rsize_t i = 0; i < size_; i++)
		objects_[i] = oldObjects[i];
	//memcpy(objects_, oldObjects, size() * sizeof(int));
	//�ͷžɵĿռ�
	delete[] oldObjects;
	//�޸�����
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
	//���ռ䣬����������
	if (size_ == capacity_)
		reserve(capacity_ * 2);
	//1  2  []  3  4����posλ�ú��Ԫ��������
	for (int i = size_; i > pos; i--)
	{
		objects_[i] = objects_[i - 1];
	}
	objects_[pos] = elem;
	size_++;
}

void MyVector::push_back(Integer & elem)
{
	//���ռ�
	if (size_ == capacity_)
	{
		reserve(capacity_ * 2);
	}
	objects_[size_++] = elem;
}

Integer & MyVector::operator[](int index) const
{
	// TODO: �ڴ˴����� return ���
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
	//1  [2]  3  4����Ԫ����ǰ��
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
	// TODO: �ڴ˴����� return ���
	return objects_[size() - 1];
}

Integer & MyVector::front()
{
	// TODO: �ڴ˴����� return ���
	return objects_[0];
}

MyVector & MyVector::operator=(const MyVector & vec)
{
	// TODO: �ڴ˴����� return ���
	
	//�����
	clear();
	//��������
	for (size_t i = 0; i < vec.size(); i++)
		objects_[i] = vec[i];

	return *this;
}

void MyVector::operator+=(const MyVector & vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		push_back(vec[i]);
}
