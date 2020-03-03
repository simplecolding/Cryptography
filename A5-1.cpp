#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int get_maj(int x,int y,int z)
{
    return (x+y+z)/2==1? 1:0;
}
int main()
{
    int value_x_int[20]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};//x=19
    int value_y_int[22]={1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};//y=22
    int value_z_int[23]={1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};//z=23
    vector<int> value_x,value_y,value_z;
    value_x.insert(value_x.begin(), value_x_int, value_x_int+19);
    value_y.insert(value_y.begin(), value_y_int, value_y_int+22);
    value_z.insert(value_z.begin(), value_z_int, value_z_int+23);
	
    for(int i = 0;i<19;i++)
    {
    	cout<<value_x[i]<<" ";
    	if(i==18) cout<<endl;
	}
	for(int i = 0;i<22;i++)
    {
    	cout<<value_y[i]<<" ";
    	if(i==21) cout<<endl;
	}
	for(int i = 0;i<23;i++)
    {
    	cout<<value_z[i]<<" ";
    	if(i==22) cout<<endl;
	}
	int num_long = 0;
	vector<int> temp;
	int num;
	cout<<"输入要产生的秘钥位数：";
	cin>>num_long;
	for(int i = 0;i<num_long;i++)
	{
		num = get_maj(value_x[8],value_y[10],value_z[10]);
		if(num == value_x[8]) 
		{
			int k = value_x[13]+value_x[16]+value_x[17]+value_x[18];
			k = k%2;
			value_x.insert(value_x.begin(),k); 
			value_x.pop_back();   
		}
		if(num == value_y[10]) 
		{
			int k = value_y[20]+value_y[21];
			k = k%2;
			value_y.insert(value_y.begin(),k); 
			value_y.pop_back();   
		}
		if(num == value_z[10]) 
		{
			int k = value_z[7]+value_z[20]+value_z[21]+value_z[22];
			k = k%2;
			value_z.insert(value_z.begin(),k); 
			value_z.pop_back();   
		}
		temp.push_back((value_x[18]+value_y[21]+value_z[22])%2);	 
	}
	
	cout<<"产生的秘钥是：";
    for(int i = 0;i<temp.size();i++)
    {
    	cout<<temp[i];
	}
	cout<<endl;
	cout<<"";
	for(int i = 0;i<19;i++)
		cout<<value_x[i]<<" ";
	cout<<endl;
	for(int i = 0;i<22;i++)
		cout<<value_y[i]<<" ";
	cout<<endl;
	for(int i = 0;i<23;i++)
		cout<<value_z[i]<<" ";
	cout<<endl;    
    std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
    return 0;
}
