#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct stu)//LEN为结构体类型 struct stu 的长度
struct stu//定义单链表的节点类型
{
    int num;
    char name[10];
    struct stu *next;
};
struct stu *creat()//返回指针值的函数,创建链表
{
    struct stu *head;//头指针，指向头节点
    struct stu *p;//指向新生成的节点
    struct stu *tail;//用于指向链表最后一个节点
    head=(struct stu *)malloc(LEN);
    int x;
    tail=head->next=NULL;
    scanf("%d",&x);
    while(x!=0)//输入学号为零时链表建立完成
    {
        p=(struct stu *)malloc(LEN);
        p->num=x;
        if(head->next==NULL) head->next=p;
        scanf("%s",&p->name);
        if(tail!=NULL) tail->next=p;//链表不空时，p所指的新节点需插入链表尾
        tail=p;
        scanf("%d",&x);

    }
    if(tail!=NULL) tail->next=NULL;//链表非空时，最后一个节点的指针域要为空
    return(head);
};
void list(struct stu *head)//遍历链表
{
    struct stu *p;
    p=head;
    if(head!=NULL)
    {
        printf("The information is\n");
        for(p=head->next;p!=NULL;p=p->next)
        {
            printf("%d %s\n",p->num,p->name);
        }
    }
    else printf("The list is null");
}
void insert(struct stu *head)//在第i-1与第i个节点间插入新节点,以首元结点为第一个节点
{
    int i;
    printf("The location to insert is\n");
    scanf("%d",&i);
    struct stu *p;
    p=head;int j=1;
    while(p&&(j<=i-1))//查找第i-1个节点
    {
        p=p->next;
        j++;
    }
    if(!p||(j>i)) printf("ERROR");
    else{
        struct stu *s;
        s=(struct stu *)malloc(LEN);//生成新节点
        s->next=p->next;
        p->next=s;
        printf("Input information\n");
        scanf("%d",&s->num);
        scanf("%s",&s->name);
        }
}
void delete(struct stu *head)//删除第i个节点
{
    int i;
    printf("The location to delete is\n");
    scanf("%d",&i);
    struct stu *p;
    p=head;int j=1;
    while(p&&(j<=i-1))//查找第i-1个节点
    {
        p=p->next;
        j++;
    }
    if(!p||(j>i)) printf("ERROR");
    else
    {
        struct stu *q;
        q=p->next;
        p->next=q->next;
        free(q);
    }
}
int main()
{
    struct stu *head;
    head=creat();
    list(head);
    insert(head);
    list(head);
    delete(head);
    list(head);
    return 0;
}
