#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

void disp_vect(vector <int> v);
void disp_map(map <int, vector<int>> m);

int main()  {
    printf("hello!\n");
    int number_of_normals = 3;

    map <int, vector<int>> vertex_normals;

    for(int i = 0; i < 20; i++) {
        float vertex = (rand() % 5);

        number_of_normals = 1 + rand() % 4; // [1, 4] faces can include this vertex
        vector <int> normals_of_this_vertex;

        for(int i = 0; i < number_of_normals; i++)  {
            int random_normal = rand() % 100;
            normals_of_this_vertex.push_back(random_normal);
        }

        if (vertex_normals.find(vertex) != vertex_normals.end())    {
            // a vector of normals for current vertex already exists; extend.
            printf("\n vertex %f exists!", vertex);
            vertex_normals[vertex].insert(  vertex_normals[vertex].end(), 
                                            normals_of_this_vertex.begin(), 
                                            normals_of_this_vertex.end());
        } else  {
            vertex_normals[vertex] = normals_of_this_vertex;
        }
        // vertex_normals[vertex].insert(normals_of_this_vertex);

        normals_of_this_vertex.clear();

        printf("\n#%d --------------\n", i);
        disp_map(vertex_normals);
    }

    return 0;
}

// function definitions:

void disp_vect(vector <int> v) {
    for(auto i = v.begin(); i != v.end(); i++)   {
        cout << *i <<  " ";
    }
}

void disp_map(map <int, vector<int>> m)  {
    for(auto& x: m) {
        // cout << x.first << " " << x.second << endl;
        cout << x.first << " -- " ; disp_vect(x.second); cout << endl;
    }
}