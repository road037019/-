#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* temp = pHead; //����pHeadָ����Ϊδ������randomָ��ʱʹ�ã�
        
        RandomListNode *p;
        RandomListNode *q;
        RandomListNode *t;
        
        map<RandomListNode*, RandomListNode*> hashnode; //����hashӳ�䣻
        if(pHead){ //����ͷ��㣻 ��һ���Ǻ���Ҫ�ģ�ͨ����һ���ĵ�����������ʡȥ�ܶ��鷳�����codeblocks�ĸ�������ĸ��Ƶ��ʹ���棻 
        	p = new RandomListNode(pHead->label);
        	q = p;
        	t = p;
            hashnode[pHead] = q;
            pHead = pHead->next;
        }
        while(pHead){ //���ƽڵ��nextָ�룻
        	q->next = new RandomListNode(pHead->label);
            hashnode[pHead] = q->next;
            pHead = pHead->next;
            q = q->next;
        }
     
        while(t){
            t->random = hashnode[temp->random];
            t = t->next;
            temp = temp->next;
        }
        
        return p;
    }
};

int main(){	
	RandomListNode p1(1);
	RandomListNode p2(2);
	RandomListNode p3(3);
	p2.next = &p3;
	p2.random = &p1;
	p1.next = &p2;
	p1.random = &p3;
	Solution s;
	RandomListNode *temp = s.Clone(&p1);
	while(temp){
		cout << temp->label << " ";
		temp= temp->next;
	}
	
	
}