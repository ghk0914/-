#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int>> data_input(int num){
    vector <vector <int>> all_node;
    for (int i=0;i<num;i++){
        vector <int> reg;
        for (int j=0;j<num;j++){
            int node;
            cin>>node;
            reg.push_back(node);
        }
        all_node.push_back(reg);
    }
    return all_node;
}
vector <int> who_disconnected(const vector <vector <int>> &vec){
    vector <int> road,queue;
    road.resize(vec.size());
    queue.push_back(0);
    while (queue.size()!=0){
        if (road[queue[0]]==0){
            road[queue[0]]=1;
        }
        for (int i=0;i<vec[queue[0]].size();i++){
            if (vec[queue[0]][i]>=1 and road[i]==0){
                queue.push_back(i);
            }
        }
        queue.erase(queue.begin());
    }
    return road;
}
void step1and2(const vector <vector <int>> &data,const vector <int> &weight,vector <int> &visited,vector <int> &cost,vector <int> &path,const vector <int> loop_stop_condition,int starting){
    vector <int> visited_non_zero;
    for (int addr=0;addr<visited.size();addr++){
        if (visited[addr]==1){
            visited_non_zero.push_back(addr);
        }
    }
    if (loop_stop_condition==visited_non_zero){
        for (auto &a:cost){
            if (a==99999){
                cout<<"infinity ";
            }
            else{
                cout<<a<<" ";
            }
        }
        cout<<endl;
        return;
    }
    //step 1
    for (int i=0;i<data.size();i++){
        if (data[starting][i]!=0 and visited[i]==0){
            //calaulate new_cost
            int new_cost;
            if (cost[starting]==0){
                new_cost=data[starting][i];
            }
            else{
                new_cost=cost[starting]+weight[starting]+data[starting][i];
            }
            //end calaulate new_cost
            //refresh path and cost when qualify
            if (new_cost<cost[i]){
                cost[i]=new_cost;
                path[i]=starting;
            }
            //end refresh path and cost when qualify
        }
    }
    //end step 1

    //step 2
    int new_starting,addr;
    vector <int> reg_cost;
    reg_cost=cost;
    for (int i=0;i<cost.size();i++){
        if (visited[i]==1){
            reg_cost[i]=99999;
        }
    }
    // for (auto &a:reg_cost){
    //     cout<<a<<"|";
    // }
    // cout<<endl;
    auto min_it=min_element(reg_cost.begin(),reg_cost.end());
    // cout<<"min_it is "<<*min_it<<endl;
    if (min_it!=reg_cost.end()){
        addr=distance(reg_cost.begin(),find(reg_cost.begin(),reg_cost.end(),*min_it));
        new_starting=addr;
        visited[addr]=1;
    }
    else{
        cout<<"cost is empty\n";
    }
    //output
    // cout<<"visited=";
    // for (auto &a:visited){
    //     cout<<a<<"|";
    // }
    // cout<<endl;
    //     cout<<"cost=";
    // for (auto &a:cost){
    //     cout<<a<<"|";
    // }
    // cout<<endl;
    //     cout<<"path=";
    // for (auto &a:path){
    //     cout<<a<<"|";
    // }
    // cout<<endl;
    // cout<<"new_starting:"<<new_starting<<endl;
    //end output
    //end step 2
    return step1and2(data,weight,visited,cost,path,loop_stop_condition,new_starting);
}
int main(int argc, char** argv) {
    while (true){
        int num,center;
        vector <int> weight;
        cin>>num;
        if (num<1) break;
        //input weight
        for (int i=0;i<num;i++){
            int s;
            cin>>s;
            weight.push_back(s);
        }
        //end input weight
        vector <vector <int>> data=data_input(num);
        cin>>center;

        //Dijkstra
        vector <int> who_disc=who_disconnected(data),loop_stop_condition;
        //initialize
        vector <int> visited(num,0),cost(num,99999),path(num,-1);
        //end initialize
        //step 0
        visited[center]=1;
        cost[center]=0;
        //end step 0
        //who_disc non_zero elements addr
        for (int addr=0;addr<who_disc.size();addr++){
            if (who_disc[addr]!=0){
                loop_stop_condition.push_back(addr);
            }
        }
        //end who_disc non_zero elements addr
        step1and2(data,weight,visited,cost,path,loop_stop_condition,center);
        //end Dijkstra
    }
	return 0;
}