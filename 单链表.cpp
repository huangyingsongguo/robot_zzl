#include <iostream>
#include <string>

using namespace std;

class SLink
{
public:   //�����ı����򷽷����ⲿ����ֱ�ӷ���    
    SLink(int h);   //���캯���������ɣ�new��һ������ʱ�Զ�����
    ~SLink(){};       //�����캯������ɾ����delete��һ������ʱ�Զ����� 
    static void Insert(int h);    //����һ������Ԫ��
    static bool Delete(int h);    //ɾ��һ������Ԫ��
    static void Deletes();    //���ٵ�����
    static void List();      //���������� 
    static SLink *Lookup(int h);   //���ҵ�������̬����ֻ�ܷ��ʾ�̬�����򷽷�
    static bool IsNull();   //�жϵ������Ƿ�Ϊ��
protected:   //���ֵı����򷽷���ֻ���ڲ�����
    static SLink *head;   //ͷָ�루ָ���һ�����ڵ㣩����ľ�̬������������ж���ָ��ͬһ����������Ҫ��ʼ��ֻ��������ⲿ���У��������ʾ

private:     //˽�еı����򷽷���ֻ���ڲ����ʣ�
    int height;
    SLink *next;     //ָ����һ�����ڵ�
};

//���캯����һ�������ʼ���Ĳ���
SLink::SLink(int h)
{
    this->height = h;    
}

//ɾ��һ������Ԫ��
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

// ��������Ԫ�أ�������ͷ����ʼ���ң��ҵ��ͷ�����������ָ�룬û�оͷ���NULL
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

//����������
void SLink::List()
{
    SLink *t=SLink::head;
    int i=1;
    while(t!=NULL){
        cout << "Node" << i++ << ":" << t->height << "\n";
        t=t->next;
    }
}

//���ٵ�����
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

//��ʼ����ľ�̬����
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


