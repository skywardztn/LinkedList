#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct stu)//LENΪ�ṹ������ struct stu �ĳ���
struct stu//���嵥����Ľڵ�����
{
    int num;
    char name[10];
    struct stu *next;
};
struct stu *creat()//����ָ��ֵ�ĺ���,��������
{
    struct stu *head;//ͷָ�룬ָ��ͷ�ڵ�
    struct stu *p;//ָ�������ɵĽڵ�
    struct stu *tail;//����ָ���������һ���ڵ�
    head=(struct stu *)malloc(LEN);
    int x;
    tail=head->next=NULL;
    scanf("%d",&x);
    while(x!=0)//����ѧ��Ϊ��ʱ���������
    {
        p=(struct stu *)malloc(LEN);
        p->num=x;
        if(head->next==NULL) head->next=p;
        scanf("%s",&p->name);
        if(tail!=NULL) tail->next=p;//������ʱ��p��ָ���½ڵ����������β
        tail=p;
        scanf("%d",&x);

    }
    if(tail!=NULL) tail->next=NULL;//����ǿ�ʱ�����һ���ڵ��ָ����ҪΪ��
    return(head);
};
void list(struct stu *head)//��������
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
void insert(struct stu *head)//�ڵ�i-1���i���ڵ������½ڵ�,����Ԫ���Ϊ��һ���ڵ�
{
    int i;
    printf("The location to insert is\n");
    scanf("%d",&i);
    struct stu *p;
    p=head;int j=1;
    while(p&&(j<=i-1))//���ҵ�i-1���ڵ�
    {
        p=p->next;
        j++;
    }
    if(!p||(j>i)) printf("ERROR");
    else{
        struct stu *s;
        s=(struct stu *)malloc(LEN);//�����½ڵ�
        s->next=p->next;
        p->next=s;
        printf("Input information\n");
        scanf("%d",&s->num);
        scanf("%s",&s->name);
        }
}
void delete(struct stu *head)//ɾ����i���ڵ�
{
    int i;
    printf("The location to delete is\n");
    scanf("%d",&i);
    struct stu *p;
    p=head;int j=1;
    while(p&&(j<=i-1))//���ҵ�i-1���ڵ�
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
