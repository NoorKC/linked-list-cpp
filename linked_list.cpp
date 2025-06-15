#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
	public:
	    Node* head;
	
	    LinkedList() {
	        head = nullptr;
    };

    // TODO: Implement this function
    void insert(int val) {
        // Insert a new node with the given value at the end of the list
        
        Node* newNode = new Node(val); 
        
        if(!head){
        	head = newNode;
        	return;
		}
		
		Node* temp = head;
		while(temp->next){
		temp = temp->next;
		}
		temp->next = newNode;
    }

    // TODO: Implement this function
    vector<int> display() {
        // Return the elements of the linked list as a vector
        
        Node* temp = head;
        
        while(temp){
        	cout << temp->data << " ";
        	temp = temp->next;
		}
		
		cout << endl;
        return {};
    }

    // TODO: Implement this function
    void reverseKGroup(int k) {
        // Reverse nodes in groups of size k
        
        // confirm whether the list exists and k is greater than 1
        if (!head || k <= 1) return;

		// create fake head to not lose the head
    	Node* fakeHead = new Node(0);
    	// fakeHead points to the head
    	fakeHead->next = head;      
		// create a node pointer lastGroupTail pointing to the same thing as fakeHead                  
    	Node* lastGroupTail = fakeHead;
		// create a current node pointer pointing to the same thing as head
    	Node* current = head;                         

    	while (true) {
        	// Check if there are k nodes to reverse
        	Node* check = current;
        	int count = 0;
        	// while the count is less than k and the node pointer is not pointing to null, add to the counter
        	while (count < k && check != nullptr) {
            	check = check->next;
            	count++;
        	}
        	
        	// Less than k nodes left, don’t reverse
        	if (count < k) break;  

        	// Start reversing k nodes
        	Node* last = nullptr;                                 
        	Node* groupHead = current;                  
        	for (int i = 0; i < k; i++) {
           		Node* next = current->next;			    
           		current->next = last;					
           		last = current;                        
            	current = next;
        	}

        	// Connect previous group to reversed
        	lastGroupTail->next = last;

        	// Connect end of reversed group to the next group
        	groupHead->next = current;
	
        	// Move prevGroupTail forward
        	lastGroupTail = groupHead;
    	}

    	// Update head
    	head = fakeHead->next;
        
    }

    // TODO: Implement this function
	bool detectLoop() {
		/* using the hare and turtle method, 
		where one pointer moves faster than the other causing the faster 
		one to reach back to the slow one incase a loop is detected */
	    Node* slow = head;
	    Node* fast = head;
	
	    while (fast != nullptr && fast->next != nullptr) {
	        slow = slow->next;          // moves 1 step
	        fast = fast->next->next;    // moves 2 steps
	
	        if (slow == fast) {
	            return true;            // Loop detected
	        }
	    }
	
	    return false;                   // No loop
	}

    // TODO: Implement this function
    void reorderOddEven() {
        // Reorder the list with odd-positioned nodes before even-positioned ones
if (!head || !head->next) return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // Save start of even list

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead; // Connect odd list to even list
    }
};
