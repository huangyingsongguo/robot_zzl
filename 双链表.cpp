#include <iostream>
#include <string>

using namespace std;

class DLink
{
public:   //公共的变量或方法，外部可以直接访问    
    DLink(int h);   //构造函数，当生成（new）一个对象时自动调用
    ~DLink(){};       //析构造函数，当删除（delete）一个对象时自动调用 
    static void Insert(int h);    //插入一个数据元素
    static bool Delete(int h);    //删除一个数据元素
    static void Deletes();    //销毁双链表
    static void List();      //遍历双链表 
    static DLink *Lookup(int h);   //查找双链表：静态函数只能访问静态变量或方法
    static bool IsNull();   //判断双链表是否为空
protected:   //保持的变量或方法，只能内部访问
    static DLink *head;   //头指针（指向第一个链节点）：类的静态变量，其的所有对象指向同一个变量。如要初始化只能在类的外部进行，如后文所示

private:     //私有的变量或方法，只能内部访问，
    int height;
    DLink *prev,*next;     //分别指向前一个、后一个链节点
};

//构造函数：一个对象初始化的操作
DLink::DLink(int h)
{
    this->height = h;
    this->next = NULL;
    this->prev = NULL; 
}

//删除一个数据元素
bool DLink::Delete(int h)
{
    DLink *th;
    th=DLink::Lookup(h);
    if (th==NULL) {
        return false;
    }else{
        if (th==DLink::head){
            if (DLink::head->next==NULL){
                DLink::head=NULL;
            }else{
                DLink::head=DLink::head->next;
                DLink::head->prev=NULL;
            }            
        }else{
            th->prev->next=th->next;
        }
        delete th;
        return false;
    }
}

void DLink::Insert(int h)
{
    DLink *t=new DLink(h);    
    if (DLink::head!=NULL){
        t->next = DLink::head;
        DLink::head->prev=t;
    }
    DLink::head = t;
}

// 查找数据元素：从链表头部开始查找，找到就返回这个对象的指针，没有就返回NULL
DLink* DLink::Lookup(int h)
{
    DLink *t = DLink::head;
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

//遍历双链表
void DLink::List()
{
    DLink *t=DLink::head;
    int i=1;
    while(t!=NULL){
        cout << "Node" << i++ << ":" << t->height << "\n";
        t=t->next;
    }
}

//销毁双链表
void DLink::Deletes()
{
    DLink *t;
    while(DLink::head!=NULL){
        t=DLink::head;
        DLink::head=DLink::head->next;
        delete t;
    }
}

bool DLink::IsNull()
{
    if (DLink::head==NULL){
        return true;
    }else{
        return false;
    }    
}

//初始化类的静态变量
DLink* DLink::head=NULL;

int main()
{
    DLink::List();
    DLink *p1=new DLink(123);
    DLink *p2=new DLink(456);
    DLink *p3=new DLink(789);

    DLink::Insert(456);
    DLink::Insert(123);
    DLink::List();
    DLink::Lookup(456);
    DLink::Lookup(46);

    DLink::Delete(456);    
    DLink::Lookup(789);
    DLink::Deletes();
    DLink::List();
    DLink::Lookup(46);
    return 0;
}