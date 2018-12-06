#ifndef VERTEX_HPP
#define VERTEX_HPP

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

#endif