class MyStack {
public:
    queue<int> q1,q2; // q1 hamesha khali rahegi par stack banane me madad karegi push karne me, q2 me stack rahega
    MyStack() {
    }
    
    void push(int x) {
        while(!q2.empty()){ //Pelhe q2 ke saare elements q1 me daalo aur q2 ko khaali karo (sab temporarily)
            q1.push(q2.front());
            q2.pop();
        }

        q2.push(x); // fir khaali q2 me push karo

        while(!q1.empty()){  // fir q1 se saare elements wapas q2 me daal do taaki q2 ke last me hamesha last element inserted rahe
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int fronti=q2.front();
        q2.pop();
        return fronti;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        if(q2.size()==0)return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */