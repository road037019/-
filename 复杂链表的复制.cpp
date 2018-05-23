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
        RandomListNode* temp = pHead; //保存pHead指针作为未来复制random指针时使用；
        
        RandomListNode *p;
        RandomListNode *q;
        RandomListNode *t;
        
        map<RandomListNode*, RandomListNode*> hashnode; //构建hash映射；
        if(pHead){ //创建头结点； 这一步是很重要的，通过这一步的单独操作可以省去很多麻烦，详见codeblocks的复杂链表的复制典型错误版； 
        	p = new RandomListNode(pHead->label);
        	q = p;
        	t = p;
            hashnode[pHead] = q;
            pHead = pHead->next;
        }
        while(pHead){ //复制节点和next指针；
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