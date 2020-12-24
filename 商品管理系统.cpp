#include <iostream>
#include <string>
using namespace std;
class goods
{
public:
    string name,price,factory,prodate,save;
    int goodsnum;
    goods *next;//申请一个指针 
    goods():next(0) {}
};
goods *t=NULL;
void add()//定义一个函数 
{
    goods *p;
    if(t==NULL)
    {
        t=new goods;
        p=t;
    }
    else
    {
        p=t;
        while(p->next!=0) p=p->next;
        p->next=new goods;
        p=p->next;
    }
    cout<<"商品号"<<endl;
    cin>>(p->goodsnum);
    cout<<"名称"<<endl;
    cin>>(p->name);
    cout<<"价格："<<endl;
    cin>>(p->price);
    cout<<"生产厂家：" <<endl;
    cin>>(p->factory);
    cout<<"生产日期："<<endl;
    cin>>(p->prodate);
    cout<<"现存量："<<endl;
    cin>>(p->save);
}
void modify()
{
    if(t==0)
    {
        cout<<"无记录"<<endl;
        return;
    }
    int goodsnum;
    cout<<"商品号：";
    cin>>goodsnum;
    goods *p;
    p=t;
    while(p!=0)
    {
        if(p->goodsnum==goodsnum) break;
        p=p->next;
    }
    if(p==0) cout<<"无记录"<<endl;
    else
    {
        cout<<"商品号 名称 价格 生产 厂家 生产日期 现存量"<<endl;
        cout<<(p->goodsnum)<<" "<<(p->name)<<" "<<(p->price)<<" "<<(p->factory)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
        int c;
        cout<<"1.商品号 2.名称 3.价格 4.生产厂家 5.生产日期 6.现存量"<<endl;
        cout<<"你要的操作：";
        cin>>c;
        if(c==1)
        {
            cout<<"商品号：";
            cin>>(p->goodsnum);
        }
        else if(c==2)
        {
            cout<<"名称：";
            cin>>(p->name);
        }
        else if(c==3)
        {
            cout<<"价格：";
            cin>>(p->price);
        }
        else if(c==4)
        {
            cout<<"生产厂家：";
            cin>>(p->factory);
        }
        else if(c==5)
        {
            cout<<"生产日期：";
            cin>>(p->prodate);
        }
        else if(c==6)
        {
            cout<<"现存量：";
            cin>>(p->save);
        }
        cout<<"商品号 名称 价格 生产厂家 生产日期 现存量"<<endl;
        cout<<(p->goodsnum)<<" "<<(p->name)<<" "<<(p->price)<<" "<<(p->factory)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
    }

}
void display()
{
    if(t==0)
    {
        cout<<"无记录"<<endl;
        return;
    }
    goods *p;
    p=t;
    cout<<"商品号 名称 价格 生产厂家 生产日期 现存量"<<endl;
    while(p!=0)
    {
        cout<<(p->goodsnum)<<" "<<(p->name)<<" "<<(p->price)<<" "<<(p->factory)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
        p=p->next;
    }

}
void sort(goods *head)
{
    goods *tail,*q,*p;

    tail=NULL;

    while(head->next!=tail)
    {
        q=head;
        p=q->next;

        while(p->next!=tail)
        {
            cout<<"进行了冒泡排序"<<endl;
            if((q->next->goodsnum)>(p->next->goodsnum))
            {
            	
                q->next=q->next->next;
                p->next=p->next->next;
                q->next->next=p;
                q=q->next;
                p=q->next;

            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        tail=p;
    }
}
void search(int i)
{
    if(t==0)
    {
        cout<<"无记录"<<endl;
        return;
    }
    goods *p;
    p=t;
    if(i==1)
    {
        string name;
        cout<<"商品名：";
        cin>>name;
        cout<<"商品号 价格 生产厂家 生产日期 现存量"<<endl;
        while(p!=0)
        {
            if(p->name==name)
                cout<<(p->goodsnum)<<" "<<(p->price)<<" "<<(p->factory)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
            p=p->next;
        }
    }
    else if(i==2)
    {
        string factory;
        cout<<"生产厂家：";
        cin>>factory;
        cout<<"商品号 名称 价格 生产日期 现存量"<<endl;
        while(p!=0)
        {
            if(p->factory==factory)
                cout<<(p->goodsnum)<<" "<<(p->name)<<" "<<(p->price)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
            p=p->next;
        }
    }
}


int main()
{
    int c;
    do
    {
        cout<<"********************************"<<endl;
		cout<<"*  欢迎您进入商品信息管理系统  *"<<endl;
		cout<<"*         1.浏览数据           *"<<endl;
		cout<<"*         2.增加数据           *"<<endl;
		cout<<"*         3.修改数据           *"<<endl;
		cout<<"*         4.查询数据           *"<<endl;
		cout<<"*         5.排序               *"<<endl;
		cout<<"*         6.退出               *"<<endl;
		cout<<"********************************"<<endl;
        cout<<"你要进行的操作："<<endl;
        cin>>c;
        if(c==1)
        {
            display();
        }
        else if(c==2)
        {
            add();
        }
        else if(c==3)
        {
            modify();
        }
         else if(c==4)
        {
            int i;
            cout<<"1.按商品名查找2.按生产厂家查找"<<endl;
            cout<<"你要的操作：";
            cin>>i;
            search(i);
        }
        else if(c==5)
        {
            sort(t);
        }

        else if(c==6)
        {
            goods *p;
            while(t!=0)
            {
                p=t->next;
                delete t;
                t=p;
            }
            break;
        }
    }
    while(1);
    return 0;
}
