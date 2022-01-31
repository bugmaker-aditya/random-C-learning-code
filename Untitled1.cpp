#include<string>
#include<iostream>
using namespace std;

class laptop{
	private:
	string brand, model;
	public:
		laptop(){
			brand = "lenovo";
			model= "ideapad";
		}
		laptop(string brand, string model){
			this->brand = brand;
			this->model = model;
		}
		laptop(const laptop& l){
			brand = l.brand;
			model = l.model;
		}
		void set_info(){
			cout<<"enter brand and model\n";
			cin>>brand;
			cin>>model;
		}
		void display(){
			cout<<brand<<" "<<model<<" ";
		}
};


int add(int a, int b , int c){
	return a+b+c;
}
float add(float a, float b){
	return a+b;
}
void fun ( int &a){ a=a+10;

}
int main(){
	laptop l1;
	l1.display();
	laptop l2("acer ", "aspire");
	l2.display();

	laptop l3(l2);
	l3.display();
	//int a;
	
	//cout<<a<<endl;
}
