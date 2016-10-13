#include<iostream>
#include<queue>
using namespace std;

struct queueEntry
{
	int v;	 // Vertex number
	int dist; // Distance of this vertex from source
};

int  getMinDiceThrows(vector<int> moves,int N){
	
	//mark all vertices unvisited
	vector<bool> visited;
	for(int i=0;i<N;i++)
		visited.push_back(false);
	
	//for BFS
	queue<queueEntry> q;
	
	//source visited, enqueue it
	visited[0]=true;
	queueEntry v0={0,0};
	q.push(v0);
	
	queueEntry qe;//do bfs, insert all edges of v0
	while(!q.empty())
	{
		qe=q.front();
		int v=qe.v; //fetch the enqueued vertex
		
		if(v==N-1) break;//if destination break
		
		//6 adjacent vertices as dice has 6 numbers, each dist is 1 as 1 throw required
		q.pop();
		for(int j=v+1;j<=(v+6);j++){
			if(!visited[j]){
				queueEntry vn;
				vn.dist=qe.dist+1;
				visited[j]=true;
				
				// Check if there a snake or ladder at 'j'
				// then tail of snake or top of ladder
				// become the adjacent of 'i'
				if(moves[j]!=-1)
					vn.v=moves[j];
				else
					vn.v=j;
				q.push(vn);
			}
				
		}
		
	}
	return qe.dist;
	
	
}

int main(){
	int N=30;
	vector<int> moves;
	for(int i=0;i<N;i++)
		moves.push_back(-1);
		
	// Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    
    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
	
}
