#include<string>
#include<iostream>
#include<stdlib.h>


int main()
{
  std::string path = "C:\\Users\\Adity\\Desktop";
  std::string dirc;
  std::string Ncd= "cd ";
  std::cout << "current working directory is: \n" << '\n'<< path<<'\n';

  std::cout << "do you want to explore sub directories" << '\n'<<"1/0";
  int a;
  std::cin >> a;
  if(a == 1)
   {

    system(" dir");

    std::cout << "\n enter directory name" << '\n';
    getline(std::cin , dirc);
    path = Ncd + dirc ;
     system(path );
     std::cout << "\n current working directory is: \n" << '\n'<< path<<'\n';
  }

return 0;
}
