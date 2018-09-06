#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;

int popOut(stack<int>& s);
void findTotal(int n,stack<int>& s,int sum,vector<int>& op);

int maxNum = 3;
int total= 0;
stack<int> s;
int main()
{
    vector<int>op(maxNum,0);
    s.push(1);
    s.push(1);
    findTotal(1,s,1,op);
    cout<<total<<endl;
    return 0;
}

void findTotal(int n,stack<int>& s,int sum,vector<int>& op)
{
    for(int i = 0; i<op.size();i++)
    {
        cout<<op[i]<<" ";
    }
    cout<<endl;
    cout<<"sum"<<sum<<endl;
    cout<<"n" <<n<<endl;
    if(n == 0)
        return;
    if(n == maxNum)
    {
        int num = 0;
        int sign = 0;
            //s.pop();
            stack<int> s2 = s;
         num = popOut(s2);
         sign = s2.top();
        cout<<"s2 "<<num<<endl;
        if(num*sign + sum == 0)
            total++;
        return findTotal(n-1,s,sum,op);
    }
    if(op[n] == 3)
    {
        op[n] = 0;
        if(n != maxNum-1)
            s.pop();
        return findTotal(n-1,s,sum-n-1,op);
    }
    if(op[n] == 2)
    {
        op[n]++;
       s.push(n+1);
     return findTotal(n+1,s,sum,op);
    }
    if(op[n] == 1)
    {
        //stack<int> s2 = s;
        op[n]++;
        int num = popOut(s);
        int sign = s.top();
        s.pop();
        s.push(-1);
        s.push(n);
        return findTotal(n+1,s,sum + sign*(num+1),op);
    }
    if(op[n] == 0)
    {
        //stack<int> s2 = s;
        op[n]++;
        int num = popOut(s);
        int sign = s.top();
        s.pop();
        s.push(1);
        s.push(n);
        return findTotal(n+1,s,sum + sign*(num+1),op);
    }
}
int popOut(stack<int>& s)
{
    int t = 0;
    int ten  = 1;
    while(s.size() != 1)
    {
        cout<<s.top()<<" ";
        t = s.top()*ten+ t;
        s.pop();
        ten*=10;
    }
    cout<<endl;
    cout<< t<<"t"<<endl;
    return t;
}
