#include <iostream>
#include "vertex.hpp"

bool Vertex::operator< (const Vertex& v) const  {
    return x < v.x;
}

std::ostream& operator<< (std::ostream& out, const Vertex& v)  {
    return out << " (" << v.x << ", " << v.y << ", " << v.z << ") ";
}