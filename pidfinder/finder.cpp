#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main(){
   DWORD pid;
   string wname;

   cout <<"type window name of program\n";
   cin >> wname;
   //converts string to lpcstr so we can use it in the findwindow function since it only accepts lpcstr for window names
   LPCSTR name = const_cast<char *>(wname.c_str());
   HWND hproc = FindWindowA(NULL,(name));
   if (hproc == NULL){
       cout<<"Error:must of typed window name wrong\n";
       main();
   }
   else{
        GetWindowThreadProcessId(hproc,&pid);
        cout<< "PID:" << pid;
        system("pause");       
   }

}