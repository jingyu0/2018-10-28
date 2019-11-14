class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票全价" << endl;
	}
};

class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票半价" << endl;
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

// 1.final 修饰基类的虚函数不能被派生类重写 
class Car 
{ 
public:    
	virtual void Drive() final {} 
};

class Benz :public Car 
{ 
public:    
	virtual void Drive() { cout << "Benz-舒适" << endl; }
}

class Car{ 
public:    
	virtual void Drive(){} 
}; 
// 2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错 
class Benz :public Car { public:   
	virtual void Drive() override {cout << "Benz-舒适" << endl;} 
};