#include <iostream>
#include <vector>
using namespace std;
void exchange_sort(vector <int> &vec){
    int vec_len=vec.size();
    for (int i=0;i<vec_len-1;i++){
        for (int j=0;j<vec_len-1-i;j++){
            if (vec[j]>vec[j+1]){
                swap(vec[j],vec[j+1]);
            }
        }
    }
    return;
}
void binary_search(const vector <int> &vec,int target,int right,int left,int middle){
    if (left>right){
        cout<<"not found\n";
        return;
    }
    if (vec[middle]==target){
        cout<<"this element addres is "<<middle<<endl;
        return;
    }
    else if (vec[middle]>target){
        right=middle-1;
    }
    else{
        left=middle+1;
    }
    middle=(right+left)/2;
    binary_search(vec,target,right,left,middle);
}
int main(int argc, char** argv) {
    vector <int> num;
    int a,right,left,middle,target;
    cout<<"please input 10 number\n";
    for (int i=0;i<10;i++){
        cin>>a;
        num.push_back(a);
    }
    cout<<"please input you target\n";
    cin>>target;
    exchange_sort(num);
    for (auto &a:num){
        cout<<a<<",";
    }
    cout<<endl;
    right=num.size()-1;
    left=0;
    middle=(right+left)/2;
    binary_search(num,target,right,left,middle);
	return 0;
}