//10.输入性别身高体重，评判体重等级。

#include <iostream>
#include <cmath>
using namespace std;
struct Person
{
	double high;   //unit:m
	double weight; //unit:kg
};

int main()
{
	double BMI, w, BMItemp;
	Person p;
	cout << "Please input your height in [m] :";
	cin >> p.high;
	cout << "Please input your Weight in [kg] :";
	cin >> p.weight;
	BMI = p.weight / pow(p.high, 2); //BMI指数公式
	cout << "Your BMI is " << BMI << endl;
	w = p.weight;
	if (BMI <= 23.9 && BMI >= 18.5)
	{
		cout << "You are in standard value!!!\n";
	}
	else if (BMI < 18.5)
	{
		do
		{
			w += 0.5;
			BMItemp = w / pow(p.high, 2);
		} while (BMItemp < 18.5);
		cout << "You will gain " << (w - p.weight) << " kg "
			 << "to acheive the standard!\n";
	}
	else
	{
		do
		{
			w -= 0.5;
			BMItemp = w / pow(p.high, 2);
		} while (BMItemp > 23.9);
		cout << "You will lose " << (p.weight - w) << " kg "
			 << "to acheive the standard!\n";
	}
	return 0;
}