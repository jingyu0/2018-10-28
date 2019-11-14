class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊȫ��" << endl;
	}
};

class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ���" << endl;
	}
};

void Func(Person & people)
{
	people.BuyTicket();
}

void Test()
{
	Person per;
	Student st;

	Func(per);
	Func(st);

	return 0;
}

// 1.final ���λ�����麯�����ܱ���������д 
class Car 
{ 
public:    
	virtual void Drive() final {} 
};

class Benz :public Car 
{ 
public:    
	virtual void Drive() { cout << "Benz-����" << endl; }
}

class Car{ 
public:    
	virtual void Drive(){} 
}; 
// 2.override �����������麯��ǿ�������д�����û����д����뱨�� 
class Benz :public Car { public:   
	virtual void Drive() override {cout << "Benz-����" << endl;} 
};