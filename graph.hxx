#ifndef ALGODS_GRAPH_HXX
#define ALGODS_GRAPH_HXX

#include <vector>

namespace algods {

    namespace graph {

        struct adjacency_list_edge {
            std::size_t node;
            adjacency_list_edge* next;
        };

        struct adjacency_list {
            std::vector<adjacency_list_edge*>
        };

    }

}
#endif
