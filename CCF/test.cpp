#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
struct Point  //ip�����ip��ַ��ʮ���Ʊ�ʾ��ABCD�ֱ����ĸ����֡�
{
    ll ip,A,B,C,D;//len��ǰ׺����
    int len;
}Ip[100005];
bool cmp(Point a,Point b){//�Ȱ���ip�ٰ��ճ�������
    if(a.ip==b.ip){
        return a.len<b.len;
    }
    else return a.ip<b.ip;
}
bool check(Point a,Point b)//����a��b�ܷ����a����b�ĺϲ�
{
    if(a.len>b.len)return 0;
    else{//�жϳ��ȵ�aǰ׺Ϊֹǰ׺�Ƿ���ͬ
        if((a.ip>>(32-a.len))==(b.ip>>(32-a.len)))return 1;
        else return 0;
    }
}
bool check2(Point a,Point b)//�ж��Ƿ�a��b�ܹ�����aǰ׺��һλ�ĺϲ�
{
    if(a.len!=b.len)return 0;
    if((a.ip>>(32-a.len+1))!=(b.ip>>(32-a.len+1)))return 0;
    if((a.ip>>(32-a.len))%2!=0)return 0;//��ȡa�ĵ�lenλ�ǲ���0
    if((b.ip>>(32-b.len))%2==1)return 1;//��ȡb�ĵ�lenλ�ǲ���1
}
Point sb(Point x){//sb��������Ϊx��ǰ׺��һλҲ����a��b
    Point ans;
    ans=x;ans.len--;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    char C[100005];
    for(int i=1;i<=n;i++){
        cin>>C;
        int l=strlen(C),num_d=0,num_x=0;
        for(int j=0;j<l;j++){//�ж�����һ��ipǰ׺
            if(C[j]=='.')num_d++;
            if(C[j]=='/')num_x++;
        }
        ll a=0,b=0,c=0,d=0,Len=0,cnt=0,now=0;//��ll�ᱬint
        for(int j=0;j<l;j++){
            if(C[j]=='/'){now=0;cnt=100;continue;}
            if(C[j]=='.'){now=0;cnt++;continue;}
            now=now*10;now+=(C[j]-'0');
            if(cnt==0)a=now;if(cnt==1)b=now;
            if(cnt==2)c=now;if(cnt==3)d=now;
            if(j==l-1)Len=now;
        }//����256���Ƴ�����
        Ip[i].A=a;Ip[i].B=b;Ip[i].C=c;Ip[i].D=d;
        Ip[i].ip=d+256*c+256*256*b+256*256*256*a;
        if(num_x)Ip[i].len=Len;
        else Ip[i].len=(num_d+1)*8;
 
    }
    vector<Point>v1;
    sort(Ip+1,Ip+1+n,cmp);//����
    for(int i=1;i<=n;i++){//��һ���ϲ�
        int cnt=1;
        while(check(Ip[i],Ip[i+cnt])){cnt++;}
        v1.push_back(Ip[i]);
        i=i+cnt-1;
    }
    int lll=v1.size();//�ڶ����ϲ�
    for(vector<Point>::iterator it=v1.begin();it!=v1.end()-1;it++)
    {
        if(check2((*it),(*(it+1)))){
            v1.erase(it+1);
            (*it)=sb((*it));
            if(it!=v1.begin())it-=2;//��Ŀ˵����ϲ��ɹ�Ҫ�ص���κϲ�����һ��
            else it--;//����ϲ��ɹ�����ǰ��û����
        }
    }
    lll=v1.size();//�������
    for(int i=0;i<lll;i++){
        cout<<v1[i].A<<"."<<v1[i].B<<"."<<v1[i].C<<"."<<v1[i].D<<"/"<<v1[i].len<<endl;
    }
 
}
/*����ȫ��ΪС��ں�
8
101.6.6.0/24
101.6.6.128/25
101.6.6/23
101/8
1/32
101.6.6.0
101.6
1
5
255.23.24.25/32
125.6.6.0/24
192.168.0.0/16
32.32.32.32/32
101.6.6.0/24

*/
