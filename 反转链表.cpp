#include <iostream>
using namespace std; 

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
	
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

        ListNode *pTail = NULL;
        ListNode *preNode = NULL;
        for( ; pHead != NULL; pHead = pHead->next){
            pTail = new ListNode(pHead->val);  //Ҫ�㣡 
            pTail->next = preNode;
            preNode = pTail;
        }

        ListNode *temp = pTail;
        for( ; temp != NULL; temp = temp->next)
            cout << temp->val << ',';
        return pTail;
    }
};

int main(){
	ListNode LN1(1),LN2(2),LN3(3);
	ListNode *pListHead = &LN1;
	LN1.next = &LN2;
	LN2.next = &LN3;
	Solution s;
	s.ReverseList(pListHead);
	return 0;
}