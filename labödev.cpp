//Selime Selin Can - 210501005
//Zeynep İrem Akyalçın - 210501008
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000; // sonsuzluğu temsil etmek için büyük bir sayı kullanıyoruz.

vector<pair<int, int>> graph[1000]; // grafı, çift olarak (düğüm, maliyet) şeklinde tutuyoruz.
int distances[1000];                // en kısa mesafeleri tutmak için dizi kullanıyoruz.
int previous[1000];                 // önceki düğümleri tutmak için dizi kullanıyoruz.
bool visited[1000];                 // ziyaret edilen düğümleri işaretlemek için bool dizisi
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap kullanarak önceliğe göre işlem yapacağız.


     // mesafeleri sonsuzluğa eşitliyoruz ve ziyaret edilmedi olarak işaretliyoruz.
    for (int i = 0; i < 1000; i++)
    {
        distances[i] = INF;
        visited[i] = false;
    }

    // başlangıç düğümünün mesafesini 0 olarak ayarlıyoruz.
    distances[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        if (visited[current])
            continue;
        visited[current] = true;

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int cost = graph[current][i].second;

            if (distances[current] + cost < distances[next])
            {
                distances[next] = distances[current] + cost;
                previous[next] = current;
                pq.push(make_pair(distances[next], next));
            }
        }
    }
}

void print_path(int start, int end)
{
    char letter;
    if (start == 1)
        letter = 'X';
    else if (start == 2)
        letter = 'Y';
    else if (start == 3)
        letter = 'Z';
    else if (start == 4)
        letter = 'T';
    else if (start == 5)
        letter = 'V';
    else if (start == 6)
        letter = 'U';
    else if (start == 7)
        letter = 'W';

    char letterB;
    if (end == 1)
        letterB = 'X';
    else if (end == 2)
        letterB = 'Y';
    else if (end == 3)
        letterB = 'Z';
    else if (end == 4)
        letterB = 'T';
    else if (end == 5)
        letterB = 'V';
    else if (end == 6)
        letterB = 'U';
    else if (end == 7)
        letterB = 'W';

    if (start == end)
    {
        cout << letter << " ";
        return;
    }
    print_path(start, previous[end]);
    cout << letterB << " ";
}

void printArray(int arr[24][3])
{
    char letter;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cout << " (" << arr[i][j] << ")";
            }
            else if (j == 0)
            {
                if (arr[i][j] == 1)
                    letter = 'X';
                else if (arr[i][j] == 2)
                    letter = 'Y';
                else if (arr[i][j] == 3)
                    letter = 'Z';
                else if (arr[i][j] == 4)
                    letter = 'T';
                else if (arr[i][j] == 5)
                    letter = 'V';
                else if (arr[i][j] == 6)
                    letter = 'U';
                else if (arr[i][j] == 7)
                    letter = 'W';
                cout << letter << " -> ";
            }
            else
            {
                if (arr[i][j] == 1)
                    letter = 'X';
                else if (arr[i][j] == 2)
                    letter = 'Y';
                else if (arr[i][j] == 3)
                    letter = 'Z';
                else if (arr[i][j] == 4)
                    letter = 'T';
                else if (arr[i][j] == 5)
                    letter = 'V';
                else if (arr[i][j] == 6)
                    letter = 'U';
                else if (arr[i][j] == 7)
                    letter = 'W';
                cout << letter;
            }
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    n = 7;
    m = 24;

    int inputValues[24][3] = {
        {1, 3, 8},
        {1, 2, 6},
        {1, 5, 3},
        {1, 7, 6},
        {2, 1, 6},
        {2, 3, 12},
        {2, 5, 8},
        {2, 4, 7},
        {3, 1, 8},
        {3, 2, 12},
        {4, 2, 7},
        {4, 5, 4},
        {4, 6, 2},
        {5, 1, 3},
        {5, 2, 8},
        {5, 7, 4},
        {5, 6, 3},
        {5, 4, 4},
        {6, 7, 3},
        {6, 5, 3},
        {6, 4, 2},
        {7, 1, 6},
        {7, 5, 4},
        {7, 6, 3}};

    printArray(inputValues);

    for (int i = 0; i < m; i++)
    {
        int a = inputValues[i][0];
        int b = inputValues[i][1];
        int c = inputValues[i][2];
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c)); // yönsüz graf olduğu için her iki yönde de eklememiz gerekiyor.

    }

    int start;
    char letter;
    cout << "Baslangic dugumunu girin: ";
    cin >> letter;
    if (letter == 'X')
    {
        start = 1;
    }
    else if (letter == 'Y')
    {
        start = 2;
    }
    else if (letter == 'Z')
    {
        start = 3;
    }
    else if (letter == 'T')
    {
        start = 4;
    }
    else if (letter == 'V')
    {
        start = 5;
    }
    else if (letter == 'U')
    {
        start = 6;
    }
    else
    {
        start = 7;
    }

    dijkstra(start);

    char letters[7] = {'X', 'Y', 'Z', 'T', 'V', 'U', 'W'};

    cout << "En kisa yollar: " << endl;
    for (int i = 1; i <= n; i++)
    {
        if (distances[i] == INF)
            cout << letters[i - 1] << ": UlaÅŸÄ±lamaz" << endl;
        else
            cout << letters[i - 1] << ": " << distances[i] << " -> ";
        print_path(start, i);
        cout << endl;
    }
    return 0;
}
