#include <iostream>
#include <string>
using namespace std;
class goods
{
public:
    string name,price,factory,prodate,save;
    int goodsnum;
    goods *next;//����һ��ָ�� 
    goods():next(0) {}
};
goods *t=NULL;
void add()//����һ������ 
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
    cout<<"��Ʒ��"<<endl;
    cin>>(p->goodsnum);
    cout<<"����"<<endl;
    cin>>(p->name);
    cout<<"�۸�"<<endl;
    cin>>(p->price);
    cout<<"�������ң�" <<endl;
    cin>>(p->factory);
    cout<<"�������ڣ�"<<endl;
    cin>>(p->prodate);
    cout<<"�ִ�����"<<endl;
    cin>>(p->save);
}
void modify()
{
    if(t==0)
    {
        cout<<"�޼�¼"<<endl;
        return;
    }
    int goodsnum;
    cout<<"��Ʒ�ţ�";
    cin>>goodsnum;
    goods *p;
    p=t;
    while(p!=0)
    {
        if(p->goodsnum==goodsnum) break;
        p=p->next;
    }
    if(p==0) cout<<"�޼�¼"<<endl;
    else
    {
        cout<<"��Ʒ�� ���� �۸� ���� ���� �������� �ִ���"<<endl;
        cout<<(p->goodsnum)<<" "<<(p->name)<<" "<<(p->price)<<" "<<(p->factory)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
        int c;
        cout<<"1.��Ʒ�� 2.���� 3.�۸� 4.�������� 5.�������� 6.�ִ���"<<endl;
        cout<<"��Ҫ�Ĳ�����";
        cin>>c;
        if(c==1)
        {
            cout<<"��Ʒ�ţ�";
            cin>>(p->goodsnum);
        }
        else if(c==2)
        {
            cout<<"���ƣ�";
            cin>>(p->name);
        }
        else if(c==3)
        {
            cout<<"�۸�";
            cin>>(p->price);
        }
        else if(c==4)
        {
            cout<<"�������ң�";
            cin>>(p->factory);
        }
        else if(c==5)
        {
            cout<<"�������ڣ�";
            cin>>(p->prodate);
        }
        else if(c==6)
        {
            cout<<"�ִ�����";
            cin>>(p->save);
        }
        cout<<"��Ʒ�� ���� �۸� �������� �������� �ִ���"<<endl;
        cout<<(p->goodsnum)<<" "<<(p->name)<<" "<<(p->price)<<" "<<(p->factory)<<" "<<(p->prodate)<<" "<<(p->save)<<endl;
    }

}
void display()
{
    if(t==0)
    {
        cout<<"�޼�¼"<<endl;
        return;
    }
    goods *p;
    p=t;
    cout<<"��Ʒ�� ���� �۸� �������� �������� �ִ���"<<endl;
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
            cout<<"������ð������"<<endl;
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
        cout<<"�޼�¼"<<endl;
        return;
    }
    goods *p;
    p=t;
    if(i==1)
    {
        string name;
        cout<<"��Ʒ����";
        cin>>name;
        cout<<"��Ʒ�� �۸� �������� �������� �ִ���"<<endl;
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
        cout<<"�������ң�";
        cin>>factory;
        cout<<"��Ʒ�� ���� �۸� �������� �ִ���"<<endl;
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
		cout<<"*  ��ӭ��������Ʒ��Ϣ����ϵͳ  *"<<endl;
		cout<<"*         1.�������           *"<<endl;
		cout<<"*         2.��������           *"<<endl;
		cout<<"*         3.�޸�����           *"<<endl;
		cout<<"*         4.��ѯ����           *"<<endl;
		cout<<"*         5.����               *"<<endl;
		cout<<"*         6.�˳�               *"<<endl;
		cout<<"********************************"<<endl;
        cout<<"��Ҫ���еĲ�����"<<endl;
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
            cout<<"1.����Ʒ������2.���������Ҳ���"<<endl;
            cout<<"��Ҫ�Ĳ�����";
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
