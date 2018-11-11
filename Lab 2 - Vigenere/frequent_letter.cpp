#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {	

	int i, j, k=0,max = 0, size;
	int v[26];
	char alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char letter;
	string line;
	ifstream myfile ("in.txt");
	if (myfile.is_open())
	{
		getline (myfile,line);
		myfile.close();
	}
	else cout << "Unable to open file"; 
	cout<<line<<endl;

  	for(i = 0; i < 26; i++)
	{
		v[i] = 0;
  		
	}
	size = line.size();
	for(i = 0; i < 26; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (alph[i] == line[j])
         		k++;	
		}
		v[i] = k;
		k = 0;	
   	}
	for(i = 0; i < 26; i++)
	{
		if(v[i]> max)
		{
			max = v[i];
			letter = line[i];
		}
	}
	cout<<"the mletter that apper the most in "<<letter<<" - "<<max<<" times"<<endl;
	for(i=0;i<26;i++)
	{
		
		cout<<"no. of aperences "<<v[i]<<" for the letter "<<alph[i]<<endl;
	}
	

  return 0;
}
