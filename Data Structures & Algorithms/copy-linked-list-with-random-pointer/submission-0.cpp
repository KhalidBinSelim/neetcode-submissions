/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;
        mpp[NULL] = NULL;
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur -> val);
            mpp[cur] = copy;
            cur = cur -> next;
        }
        cur = head; 
        while (cur) {
            Node* copy = mpp[cur];
            copy -> next = mpp[cur -> next];
            copy -> random = mpp[cur -> random];
            cur = cur -> next;
        }
        return mpp[head];
    }
};
