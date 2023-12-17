#include <iostream>
#include <string>

using namespace std;

class SLink
{
public:   //公共的变量或方法，外部可以直接访问    
    SLink(int h);   //构造函数，当生成（new）一个对象时自动调用
    ~SLink(){};       //析构造函数，当删除（delete）一个对象时自动调用 
    static void Insert(int h);    //插入一个数据元素
    static bool Delete(int h);    //删除一个数据元素
    static void Deletes();    //销毁单链表
    static void List();      //遍历单链表 
    static SLink *Lookup(int h);   //查找单链表：静态函数只能访问静态变量或方法
    static bool IsNull();   //判断单链表是否为空
protected:   //保持的变量或方法，只能内部访问
    static SLink *head;   //头指针（指向第一个链节点）：类的静态变量，其的所有对象指向同一个变量。如要初始化只能在类的外部进行，如后文所示

private:     //私有的变量或方法，只能内部访问，
    int height;
    SLink *next;     //指向下一个链节点
};

//构造函数：一个对象初始化的操作
SLink::SLink(int h)
{
    this->height = h;    
}

//删除一个数据元素
bool SLink::Delete(int h)
{
    SLink *t,*th;
    th=SLink::Lookup(h);
    if (th==NULL) {
        return false;
    }
    t=SLink::head;
    if (t->height==th->height){
        SLink::head=SLink::head->next;
    }else{
        while (t->next->height!=th->height){
            t=t->next;
        }
        t->next=t->next->next;
    }
	delete th;
    return true;
}

void SLink::Insert(int h)
{
    SLink *t=new SLink(h);
    t->next = SLink::head;
    SLink::head = t;
}

// 查找数据元素：从链表头部开始查找，找到就返回这个对象的指针，没有就返回NULL
SLink* SLink::Lookup(int h)
{
    SLink *t = SLink::head;
    while (t!=NULL){
        if (t->height==h){
            break;
        }
        cout << t->height << " is at:" << t << "\n";
        t=t->next;
    }
    if (t==NULL){
        cout << h <<" is not found!" << "\n";
    }
    else{
         cout << t->height << " is at:" << t << "\n";
    }
    return t;
}

//遍历单链表
void SLink::List()
{
    SLink *t=SLink::head;
    int i=1;
    while(t!=NULL){
        cout << "Node" << i++ << ":" << t->height << "\n";
        t=t->next;
    }
}

//销毁单链表
void SLink::Deletes()
{
    SLink *t;
    while(SLink::head!=NULL){
        t=SLink::head;
        SLink::head=SLink::head->next;
        delete t;
    }
}

bool SLink::IsNull()
{
    if (SLink::head==NULL){
        return true;
    }else{
        return false;
    }    
}

//初始化类的静态变量
SLink* SLink::head=NULL;

int main()
{
    SLink::List();
    SLink *p1=new SLink(123);
    SLink *p2=new SLink(456);
    SLink *p3=new SLink(789);

    SLink::Insert(456);
    SLink::Insert(123);
    SLink::List();
    SLink::Lookup(456);
    SLink::Lookup(46);

    SLink::Delete(456);    
    SLink::Lookup(789);
    SLink::Deletes();
    SLink::List();
    SLink::Lookup(46);
    return 0;
}


