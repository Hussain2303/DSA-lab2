#include<iostream>
#include<string.h>
using namespace std;

	class shape{
	public:
		virtual void area() = 0;
	};
	class circle :public shape{
	private:
		float radius;
	public:
		circle(float r = 0) :radius(r){}
		void area() override{
			cout << "radius of circle is :" << radius*radius*3.14 << endl;
		}
	};
	class rectangle :public shape{
		float length = 0;
		float width = 0;
	public:
		rectangle(float l = 0, float w = 0) :length(l), width(w){}
		void area() override{
			cout << "Area  of rectangle  is :" << length*width << endl;
		}
	};

	int main(){
		shape * shape1;
		shape* shape2;

		shape1 = new circle(5.5);
		shape2 = new rectangle(3, 5);
		shape1->area();
		shape2->area();


	return 0;
}