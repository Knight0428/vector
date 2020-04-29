#pragma once
#include <iostream>

using namespace std;

//����Ԫ������
extern int g_newCount;

//������
class Integer
{
public:
	//Ĭ�Ϲ���
	Integer(int i = 0)
	{
		i_ = i;
		p = new char[10];
		g_newCount++;
	}
	//���ù���
	Integer(const Integer& obj)
	{
		p = obj.p;
	}

	//���������
	Integer& operator = (Integer& obj)
	{
		//���ԭ�ȵ�ֵ
		if (p != NULL)
		{
			delete[] p;
			g_newCount--;
		}
		//����ֵ
		p = new char[10];
		i_ = obj.i_;
		g_newCount++;
		return *this;
	}

	//���������
	Integer& operator = (int n)
	{
		i_ = n;
		return *this;
	}

	//��ȡ��ֵ
	int intValue() const
	{
		return i_;
	}

	//����
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
	//��ֵ
	int i_;
	//��ŵ�ַ
	char *p;

};




//����   ����
class MyVector
{
private:
	//ö����С����
	enum { MIM_CAPACITY = 1 };

public:
	MyVector(size_t initSize = 0);
	MyVector(const MyVector& vec);
	~MyVector();

	void reserve(size_t newCapacity);     //��������
	void resize(size_t newSize);          //������С
	size_t size() const;                  //��ȡ��С
	size_t capacity() const;              //��ȡ����
	void insert(int pos, Integer& elem);  //����Ԫ��
	void push_back(Integer& elem);        //β������
	Integer& operator [] (int index) const;   //�޸ģ���ȡָ��Ԫ��
	bool empty() const;                   //�Ƿ�ձ�
	void clear();                         //���
	void erase(int pos);                  //ɾ��Ԫ��
	void pop_back();                      //β��ɾ��
	Integer& back();                      //��ȡβ��Ԫ��
	Integer& front();                     //��ȡͷ��Ԫ��
	MyVector& operator = (const MyVector& vec);
	void operator += (const MyVector& vec);

private:
	Integer *objects_;        //Ԫ��
	size_t size_;             //��С
	size_t capacity_;         //����

};

