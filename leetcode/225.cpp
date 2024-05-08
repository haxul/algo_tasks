#include <queue>
using namespace std;
class MyStack {
   private:
    queue<int> q1;
    queue<int> q2;

   public:
    MyStack() {}

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }
    int pop() {
        int r = q1.front();
        q1.pop();
        return r;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

int main() {
    MyStack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
}