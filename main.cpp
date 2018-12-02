#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

class Vertex {
    private:    
        int x;
        int y;
        int z;

    public:
        Vertex(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        bool operator< (const Vertex& x) const;
        friend std::ostream& operator<< (std::ostream&, const Vertex&);
};

void disp_vect(std::vector <int> v);
void disp_map(std::map <Vertex, std::vector<int>> m);

int main()  {
    int number_of_normals;
    int random_normal;
    const int VERTEX_RANGE = 10;
    std::map <Vertex, std::vector<int>> vertex_normals;
    std::vector <int> normals_of_this_vertex;

    for(int i = 0; i < 20; i++) {
        // create a random vertex
        Vertex vertex(rand() % VERTEX_RANGE, rand() % VERTEX_RANGE, rand() % VERTEX_RANGE);
        number_of_normals = 1 + rand() % 4; // [1, 4] faces can include this vertex
        
        for(int i = 0; i < number_of_normals; i++)  {
            random_normal = rand() % 100;
            normals_of_this_vertex.push_back(random_normal);
        }

        if (vertex_normals.find(vertex) != vertex_normals.end())    {
            // a vector of normals for current vertex already exists; extend.
            printf("\n vertex exists!");
            vertex_normals[vertex].insert(  vertex_normals[vertex].end(), 
                                            normals_of_this_vertex.begin(), 
                                            normals_of_this_vertex.end());
        } else  {
            printf("\n vertex does not exist!");
            vertex_normals[vertex] = normals_of_this_vertex;
        }

        normals_of_this_vertex.clear(); // clear the normals

        printf("\n#%d --------------\n", i);
        disp_map(vertex_normals);
    }
    return 0;
}

// function definitions:

bool Vertex::operator< (const Vertex& v) const  {
    return x < v.x;
}

std::ostream& operator<< (std::ostream& out, const Vertex& v)  {
    return out << " (" << v.x << ", " << v.y << ", " << v.z << ") ";
}

void disp_vect(std::vector <int> v) {
    for(auto i = v.begin(); i != v.end(); i++)   {
        std::cout << *i <<  " ";
    }
}

void disp_map(std::map <Vertex, std::vector<int>> m)  {
    for(auto& x: m) {
        std::cout << x.first << " -- " ; disp_vect(x.second); std::cout << std::endl;
    }
}