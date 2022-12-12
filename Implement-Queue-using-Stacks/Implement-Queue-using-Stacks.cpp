class MyQueue {
public:
    queue&lt;int&gt; box;
    MyQueue() { }
    void push(int x) {
        box.push(x);
    }
    int pop() {
        int res = box.front();
        box.pop();
        return res;
    }
    int peek() {
        return box.front();
    }
    bool empty() {
        return box.size() == 0;
    }
};
/**
