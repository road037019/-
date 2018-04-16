/*
**输入一个链表，输出该链表中倒数第k个节点； 
*/

#include <iostream>
#include <vector>
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //vector<ListNode *> L;
        ListNode *temp = pListHead;
        int size = 0;
        for(; temp != NULL; temp = temp->next){
            ++size;
            //L.push_back(pListHead);
        }
        
        //缺少这个if判断条件会通不过，这是要求程序自己检查是否是有效位置； 
        if(k > size) 
        	return NULL;
        
        temp = pListHead;
        for(int i = 0; i != size - k; i++){
            temp = temp->next;
        }
        return temp;
    }
};

	
/*
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        vector<ListNode *> L;
        for(; pListHead != NULL; pListHead = pListHead->next){
            L.push_back(pListHead);
        }
        return L[L.size()-k];
    }
};*/

int main(){
	ListNode LN1(1),LN2(2),LN3(3);
	ListNode *pListHead = &LN1;
	LN1.next = &LN2;
	LN2.next = &LN3;
	Solution s;
	cout << s.FindKthToTail(pListHead, 1)->val << endl; 
	return 0;
}