#include<iostream>
using namespace std;

int main()
{
  system("runas /noprofile /user:mymachine\\administratora C:\\'Program Files'\\MySQL\\'MySQL Server 8.0'\\bin\\mysqld --defaults-file='C:\\ProgramData\\MySQL\\MySQL Server 8.0\\my.ini'  --init-file=C:\\mysql-init.txt");
  return 0;
}
