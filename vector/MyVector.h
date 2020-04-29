#pragma once
#include <iostream>

using namespace std;

//声明元素总数
extern int g_newCount;

//整数类
class Integer
{
public:
	//默认构造
	Integer(int i = 0)
	{
		i_ = i;
		p = new char[10];
		g_newCount++;
	}
	//引用构造
	Integer(const Integer& obj)
	{
		p = obj.p;
	}

	//重载运算符
	Integer& operator = (Integer& obj)
	{
		//清除原先的值
		if (p != NULL)
		{
			delete[] p;
			g_newCount--;
		}
		//赋新值
		p = new char[10];
		i_ = obj.i_;
		g_newCount++;
		return *this;
	}

	//重载运算符
	Integer& operator = (int n)
	{
		i_ = n;
		return *this;
	}

	//获取数值
	int intValue() const
	{
		return i_;
	}

	//析构
	~Integer()
	{
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
			g_newCount--;
		}
	}

private:
	//数值
	int i_;
	//存放地址
	char *p;

};




//向量   数组
class MyVector
{
private:
	//枚举最小容量
	enum { MIM_CAPACITY = 1 };

public:
	MyVector(size_t initSize = 0);
	MyVector(const MyVector& vec);
	~MyVector();

	void reserve(size_t newCapacity);     //调整容量
	void resize(size_t newSize);          //调整大小
	size_t size() const;                  //获取大小
	size_t capacity() const;              //获取容量
	void insert(int pos, Integer& elem);  //插入元素
	void push_back(Integer& elem);        //尾部插入
	Integer& operator [] (int index) const;   //修改，获取指定元素
	bool empty() const;                   //是否空表
	void clear();                         //清空
	void erase(int pos);                  //删除元素
	void pop_back();                      //尾部删除
	Integer& back();                      //获取尾部元素
	Integer& front();                     //获取头部元素
	MyVector& operator = (const MyVector& vec);
	void operator += (const MyVector& vec);

private:
	Integer *objects_;        //元素
	size_t size_;             //大小
	size_t capacity_;         //容量

};

