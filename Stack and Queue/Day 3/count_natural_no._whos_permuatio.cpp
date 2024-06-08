#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countNumber(int n){
    int result = 0;
    stack <int> st;
    for (int i =0 ; i<= 9 ; i++){
        if(i<=n){
            st.push(i);
            result ++;
        }
        while (!st.empty()){
            int top = st.top();
            st.pop();
            for (int j = top ; j<=9; j++){
                int x = top*10 + j;
                if (x<=n){
                    st.push(x);
                    result++;
                }
            }
        }
    }
    return result;


}

int main() 
{ 
    int n = 15; 
    cout << countNumber(n) << endl; 
    return 0;
}