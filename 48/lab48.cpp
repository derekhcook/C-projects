// Derek Cook
// CS 2336
// Lab 48

#include<queue>

template<typename T>
void distribution(const priority_queue<T>& pq, ostream& os)
{
    if(pq.empty())
        return;
    priority_queue<T> copy(pq);
    T temp = copy.top();
    uint count = 0;

    while(!copy.empty())
    {
        if(copy.top() == temp)
        {
            count++;
            copy.pop();
        }
        else
        {
            os << temp << '(' << count << ')' << endl;
            temp = copy.top();
            count = 1;
            copy.pop();
        }
    }
    os << temp << '(' << count << ')' << endl;
}