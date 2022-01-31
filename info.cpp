#include <iostream>

class Entry{
	private:
		int counter=1;
		int *UniqueId;
		int *age;
		int Visitors;
		int cost;
		int SumOfAge;
	public:
    Entry();
		Entry ( int ag[], int number_of_visitors)
					{
						age= new int[number_of_visitors];
						UniqueId = new int[1];
						for(int i=0; i<number_of_visitors;i++)
						{
								if (ag[i]>110 || age[i]<0)
									std::cout<< "age not possible\n enter correct age:\t"<<std::endl;
					 			else{
						 				age[i]=ag[i];
										SumOfAge+=ag[i];
					 					}
				 		}

						Visitors=number_of_visitors;
						UniqueId[counter] = (((counter+10)%SumOfAge)%number_of_visitors)*100;
					}

		bool UniqueIdChecker( int *UniqueId1)
				{
						for( int i=0; i<Visitors;i++)
							{
								if( UniqueId[i]==UniqueId1[i])
									return true;
								else
									return false;
				}
			}

		int costCalculator( int number_of_visitors)
					{
						for( int i=0; i<number_of_visitors; i++)
							{
								if( age[i]<=2)
									{
										cost+=0;
									}
								if( age[i]>2 && age[i]<18)
										{
												cost+=100;
										}
								if( age[i]>=18 && age[i]<60){
												cost+=500;
											}
								if(age[i]>=60){
											 	cost+=300;
											}
							}
						}

		void PrintTicket()
					{
								std::cout<<"Your ticket\n";
								std::cout<<"Your Unique id: "<<UniqueId[counter]<<std::endl;
								for( int i=0; i<Visitors;i++)
									{
											std::cout<<"guest "<<i<<":\t"<< age[i];
									}
								costCalculator(Visitors);
								std::cout<<"\nTotal amount to be paid: "<<cost<<"INR"<<std::endl;
								counter++;
						}


			};

class SecurityCheck : public Entry{
	int UniqueID;
	int no_of_visitor;
public:
	SecurityCheck(int *Id){
		if(UniqueIdChecker(Id)==true){
			std::cout<<"\n\nTicket verified, now you may proceed\n";
		}
		else{
			std::cout<<"\nTicket not verified, please purchase Ticket from counter\n";
		}
	}
};

int main()
{
	int age[5]={1,5,89,65,15};
	Entry e1(age,5);
	int id,*ID;
	std::cout<<"enter ID number";
	std::cin>> id;
    ID=&id;
SecurityCheck S1(ID);
return 0;
}
