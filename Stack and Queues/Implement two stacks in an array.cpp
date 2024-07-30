class twoStacks {
  public:

    twoStacks() {}

    // Function to push an integer into the stack1.
    stack<int>st1;
    stack<int>st2;

    // Function to push an integer into the stack1.
    void push1(int x) {
        st1.push(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        st2.push(x);
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        int res=-1;
        if(!st1.empty()){
             res=st1.top();
            st1.pop();
        }
       
        return res;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        int res=-1;
        if(!st2.empty()){
            res = st2.top();
            st2.pop();
        }
        return res;
    }
};

