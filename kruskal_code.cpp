#include <iostream>
using namespace std;

const int MAX = 30;

struct eg {
  int u, v, w;
} eg;

struct edgList {
struct eg data[MAX];
  int n;
} edgList;

struct edgList elist;

int graph[MAX][MAX], n;
struct edgList spnLst;

void Krus();
int search(int relatesTo[], int verNo);
void Union(int relatesTo[], int c1, int c2);
void sort();
void disp();

int main() {
  int i, j, total_cost;

  n = 6;

  graph[0][0] = 0;
  graph[0][1] = 4;
  graph[0][2] = 4;
  graph[0][3] = 0;
  graph[0][4] = 0;
  graph[0][5] = 0;
  graph[0][6] = 0;

  graph[1][0] = 4;
  graph[1][1] = 0;
  graph[1][2] = 2;
  graph[1][3] = 0;
  graph[1][4] = 0;
  graph[1][5] = 0;
  graph[1][6] = 0;

  graph[2][0] = 4;
  graph[2][1] = 2;
  graph[2][2] = 0;
  graph[2][3] = 3;
  graph[2][4] = 4;
  graph[2][5] = 0;
  graph[2][6] = 0;

  graph[3][0] = 0;
  graph[3][1] = 0;
  graph[3][2] = 3;
  graph[3][3] = 0;
  graph[3][4] = 3;
  graph[3][5] = 0;
  graph[3][6] = 0;

  graph[4][0] = 0;
  graph[4][1] = 0;
  graph[4][2] = 4;
  graph[4][3] = 3;
  graph[4][4] = 0;
  graph[4][5] = 0;
  graph[4][6] = 0;

  graph[5][0] = 0;
  graph[5][1] = 0;
  graph[5][2] = 2;
  graph[5][3] = 0;
  graph[5][4] = 3;
  graph[5][5] = 0;
  graph[5][6] = 0;

  Krus();
  disp();
}

void Krus() {
  int relatesTo[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i+=1)
    for (j = 0; j < i; j+=1) {
      if (graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = graph[i][j];
        elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i+=1)
    relatesTo[i] = i;

  spnLst.n = 0;

  for (i = 0; i < elist.n; i+=1) {
    cno1 = search(relatesTo, elist.data[i].u);
    cno2 = search(relatesTo, elist.data[i].v);

    if (cno1 != cno2) {
      spnLst.data[spnLst.n] = elist.data[i];
      spnLst.n = spnLst.n + 1;
      Union(relatesTo, cno1, cno2);
    }
  }
}

int search(int relatesTo[], int verNo) {
  return (relatesTo[verNo]);
}

void Union(int relatesTo[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i+=1)
    if (relatesTo[i] == c2)
      relatesTo[i] = c1;
}

// Sorting algo
void sort() {
  int i, j;
  struct eg temp;

  for (i = 1; i < elist.n; i+=1)
    for (j = 0; j < elist.n - 1; j+=1)
      if ( elist.data[j].w > elist.data[j + 1].w)
      {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

void disp() {
  int i, cost = 0;

  for (i = 0; i < spnLst.n; i+=1) {
    cout<<"\n"<< spnLst.data[i].u << spnLst.data[i].v << spnLst.data[i].w ;
    cost = cost + spnLst.data[i].w;
  }

  cout<<"\nSpanning tree cost: "<<cost;
}
