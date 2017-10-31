#include<iostream>
using namespace std;

class Room {
	int conRoom[4]; //+1 to prevent segmentation fault
	int cons; // cons = 0; number of adjacent rooms
	int Satisfact;
	public:
	Room();
	int getConRoom(int i) { return conRoom[i]; }
	int setConRoom(int i) { conRoom[++cons] = i; }

	int setSatisfact(int i) { Satisfact = i; }
	int getSatisfact() { return Satisfact; }

	int getCons() { return cons; }
};

Room::Room(){
	cons = 0;
}

int BaseRouterMax(Room Rooms[], int remainder, int n , const int N)
{
  if (n>N) {
     return 0;
  }
	int sat = Rooms[n].getSatisfact();
	for (int j = Rooms[n].getCons(); j>0; j--) {
		int adjRoom = Rooms[n].getConRoom(j);
		sat += Rooms[adjRoom].getSatisfact();
	}
	remainder += sat;
    //on the base level, compare all the remaining routers with different rooms
	 int bb = BaseRouterMax(Rooms, remainder-sat, n+1, N);
	 return max(remainder, bb);

}

int Sum(Room Rooms[], int remainder, int n , int m, const int N)
{
    if (n > N)
        return 0;
    if (m == 1)
        return BaseRouterMax(Rooms, remainder, n, N);
    if (m >= 2) {
        Room NewRooms[N+1];
        for( int i = 1; i <= N; i++){
            for(int c = Rooms[i].getCons(); c > 0; c --)
                NewRooms[i].setConRoom(Rooms[i].getConRoom(c));
            NewRooms[i].setSatisfact(Rooms[i].getSatisfact());
        }
        int sat = Rooms[n].getSatisfact(); //satisfaction of room router placed in
        for (int j = Rooms[n].getCons(); j>0; j--) {
            int adjRoom = Rooms[n].getConRoom(j);
            sat += Rooms[adjRoom].getSatisfact();
            NewRooms[adjRoom].setSatisfact(0);
        }
        NewRooms[n].setSatisfact(0);
        remainder += sat;   //sat is remainder
        int nmax = Sum(NewRooms, remainder, n, m-1, N);
        //cout << "nmax" << nmax << endl;
        //cout << "remainder" << remainder << endl;
        return max(nmax, Sum(Rooms, remainder-sat, n+1, m, N));
    }
}

int main(){
	int N; //number of rooms
	cin >> N;

	int M; //number of routers
	cin >> M;

	Room Rooms[N+1]; //+1 to prevent segmentation fault

	for (int i=1; i<=N; i++){
		int x;
		cin >> x;
		Rooms[i].setSatisfact(x);
	}

	//cout << "ready to input rooms";
	for (int i=1; i<N; i++){
		int x, y;
		cin >> x >> y;
		Rooms[x].setConRoom(y);
		Rooms[y].setConRoom(x);
	}

    int sum = Sum(Rooms, 0, 1, M, N);
	cout << sum << endl;
}
